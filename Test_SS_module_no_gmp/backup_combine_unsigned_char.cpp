/*

	shamir.c -- Shamir's Secret Sharing

	Inspired by:

		http://en.wikipedia.org/wiki/Shamir's_Secret_Sharing#Javascript_example


	Compatible with:

		http://www.christophedavid.org/w/c/w.php/Calculators/ShamirSecretSharing

	Notes:

		* The secrets start with 'AABBCC'
		* 'AA' is the hex encoded share # (1 - 255)
		* 'BB' is the threshold # of shares, also in hex
		* 'CC' is fake for compatibility with the web implementation above (= 'AA')
		* Remaining characters are encoded 1 byte = 2 hex characters, plus
			'G0' = 256 (since we use 257 prime modulus)

	Limitations:

		* rand() needs to be seeded before use (see below)


	Copyright © 2015 Fletcher T. Penney. Licensed under the MIT License.

	## The MIT License ##

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "combine.h"


static int prime = 257;


/*
	Math stuff
*/

int * gcdD(int a, int b) {
	int * xyz = static_cast<int*>(malloc(sizeof(int) * 3));

	if (b == 0) {
		xyz[0] = a;
		xyz[1] = 1;
		xyz[2] = 0;
	} else {
		int n = floor(a / b);
		int c = a % b;
		int * r = gcdD(b, c);

		xyz[0] = r[0];
		xyz[1] = r[2];
		xyz[2] = r[1] - r[2] * n;

		free(r);
	}

	return xyz;
}


/*
	More math stuff
*/

int modInverse(int k) {
	k = k % prime;

	int r;
	int * xyz;

	if (k < 0) {
		xyz = gcdD(prime, -k);
		r = -xyz[2];
	} else {
		xyz = gcdD(prime, k);
		r = xyz[2];
	}

	free(xyz);

	return (prime + r) % prime;
}


/*
	join_shares() -- join some shares to retrieve the secret
	xy_pairs is array of int pairs, first is x, second is y
	n is number of pairs submitted
*/

int join_shares(int * xy_pairs, int n) {
	int secret = 0;
	long numerator;
	long denominator;
	long startposition;
	long nextposition;
	long value;
	int i;
	int j;

	// Pairwise calculations between all shares
	for (i = 0; i < n; ++i) {
		numerator = 1;
		denominator = 1;

		for (j = 0; j < n; ++j) {
			if (i != j) {
				startposition = xy_pairs[i * 2];		// x for share i
				nextposition = xy_pairs[j * 2];		// x for share j
				numerator = (numerator * (0-nextposition)) % prime;
				denominator = (denominator * (startposition - nextposition)) % prime;
			}
		}

		value = xy_pairs[i * 2 + 1];

		secret = (secret + (value * numerator * modInverse(denominator))) % prime;
	}


	/* Sometimes we're getting negative numbers, and need to fix that */
	secret = (secret + prime) % prime;
	//printf("%02X\n",secret);

	return secret;
}

int join_shares_to_recover_share(int * xy_pairs, int n, int x_share){
	int secret = 0;
	long numerator;
	long denominator;
	long startposition;
	long nextposition;
	long value;
	int i;
	int j;

	// Pairwise calculations between all shares
	for (i = 0; i < n; ++i) {
		numerator = 1;
		denominator = 1;

		for (j = 0; j < n; ++j) {
			if (i != j) {
				startposition = xy_pairs[i * 2];		// x for share i
				nextposition = xy_pairs[j * 2];		// x for share j
				numerator = (numerator * (x_share-nextposition)) % prime;
				denominator = (denominator * (startposition - nextposition)) % prime;
			}
		}

		value = xy_pairs[i * 2 + 1];

		secret = (secret + (value * numerator * modInverse(denominator))) % prime;
	}


	/* Sometimes we're getting negative numbers, and need to fix that */
	secret = (secret + prime) % prime;
	//printf("%02X\n",secret);

	return secret;

}

int compute_partial_share(int* xy_pairs, int n, int x_share, int* x_shares, int x_shares_len){ //xy_pairs = [x,y]
	int share = 0;
	long numerator = 1 ;
	long denominator = 1;
	long startposition;
	long nextposition;
	long value;

	for(int i=0; i<x_shares_len; i++){
		if(x_shares[i] != xy_pairs[0]){
			startposition = xy_pairs[0]; 
			nextposition = x_shares[i];
			numerator = (numerator * (x_share-nextposition)) % prime;
			denominator = (denominator * (startposition - nextposition)) % prime;
		}
	}

	value = xy_pairs[1];

	share = (value * numerator * modInverse(denominator))% prime;
	share = (share + prime) % prime;
	 
	//printf("%d\n",share);

	return share;
}

#ifdef TEST
void Test_join_shares(CuTest * tc) {
	int n = 200;
	int t = 100;

	int shares[n * 2];

	int count = 255;	/* How many times should we test it? */
	int j;

	for (j = 0; j < count; ++j) {
		int * test = split_number(j, n, t);
		int i;

		for (i = 0; i < n; ++i) {
			shares[i * 2] = i + 1;
			shares[i * 2 + 1] = test[i];
		}

		/* Send all n shares */
		int result = join_shares(shares, n);

		free(test);

		CuAssertIntEquals(tc, j, result);
	}
}
#endif


void free_string_shares(char ** shares, int n) {
	int i;

	for (i = 0; i < n; ++i) {
		free(shares[i]);
	}

	free(shares);
}


char * join_strings(char ** shares, int n) {
	/* TODO: Check if we have a quorum */

	if ((n == 0) || (shares == NULL) || (shares[0] == NULL)) {
		return NULL;
	}

	// `len` = number of hex pair values in shares
	int len = (strlen(shares[0]) - 6) / 2;

	char * result = static_cast<char*>(malloc(len + 1));
	char codon[3];
	codon[2] = '\0';	// Must terminate the string!

	int x[n];		// Integer value array
	int i;			// Counter
	int j;			// Counter

	// Determine x value for each share
	for (i = 0; i < n; ++i) {
		if (shares[i] == NULL) {
			free(result);
			return NULL;
		}

		codon[0] = shares[i][0];
		codon[1] = shares[i][1];

		x[i] = strtol(codon, NULL, 16);
	}

	// Iterate through characters and calculate original secret
	for (i = 0; i < len; ++i) {
		int * chunks = static_cast<int*>(malloc(sizeof(int) * n  * 2));

		// Collect all shares for character i
		for (j = 0; j < n; ++j) {
			// Store x value for share
			chunks[j * 2] = x[j];

			codon[0] = shares[j][6 + i * 2];
			codon[1] = shares[j][6 + i * 2 + 1];

			// Store y value for share
			if (memcmp(codon, "G0", 2) == 0) {
				chunks[j * 2 + 1] = 256;
			} else {
				chunks[j * 2 + 1] = strtol(codon, NULL, 16);
			}
		}

		//unsigned char letter = join_shares(chunks, n);
		unsigned char letter = join_shares(chunks, n);

		free(chunks);

		//sprintf(result + i, "%c", letter);
		result[i] = letter;
	}

	return result;
}

char* join_strings_to_recover_share(char ** shares, int n, int x_share) { //In fact n is t
		/* TODO: Check if we have a quorum */

	if ((n == 0) || (shares == NULL) || (shares[0] == NULL)) {
		return NULL;
	}

	// `len` = number of hex pair values in shares
	int len = (strlen(shares[0]) - 6) / 2;

	char * result = static_cast<char*>(malloc(len + 1));
	char codon[3];
	codon[2] = '\0';	// Must terminate the string!

	int x[n];		// Integer value array
	int i;			// Counter
	int j;			// Counter

	// Determine x value for each share
	for (i = 0; i < n; ++i) {
		if (shares[i] == NULL) {
			free(result);
			return NULL;
		}

		codon[0] = shares[i][0];
		codon[1] = shares[i][1];

		x[i] = strtol(codon, NULL, 16);
	}

	// Iterate through characters and calculate original secret
	for (i = 0; i < len; ++i) { // `len` = number of hex pair values in shares
		int * chunks = static_cast<int*>(malloc(sizeof(int) * n  * 2));

		// Collect all shares for character i
		for (j = 0; j < n; ++j) {
			// Store x value for share
			chunks[j * 2] = x[j];//***************** x value of share 

			codon[0] = shares[j][6 + i * 2];
			codon[1] = shares[j][6 + i * 2 + 1];

			// Store y value for share
			if (memcmp(codon, "G0", 2) == 0) {
				chunks[j * 2 + 1] = 256;
			} else {
				chunks[j * 2 + 1] = strtol(codon, NULL, 16); //*****************y value of share
			}
		}

		//unsigned char letter = join_shares(chunks, n);
		unsigned char letter = join_shares_to_recover_share(chunks, n, x_share);

		free(chunks);

		//sprintf(result + i, "%c", letter);
		result[i] = letter;
	}

	return result;
}


unsigned char* recover_partial_share(char ** shares, int n, int x_share, int* x_shares, int x_shares_len) { 
	// In fact n is t and it is equal to 1
	// "shares" contains just one share

	if ((n == 0) || (shares == NULL) || (shares[0] == NULL)) {
		return NULL;
	}

	// `len` = number of hex pair values in shares
	int len = (strlen(shares[0]) - 6) / 2;

	unsigned char * result = static_cast<unsigned char*>(malloc(len + 1));
	//int* result = static_cast<int*>(malloc(sizeof(int)*len));
	char codon[3];
	codon[2] = '\0';	// Must terminate the string!

	int x[n];		// Integer value array
	int i;			// Counter
	int j;			// Counter

	// Determine x value for each share
	i = 0;
	
	if (shares[i] == NULL) {
		free(result);
		return NULL;
	}

	codon[0] = shares[i][0];
	codon[1] = shares[i][1];

	x[i] = strtol(codon, NULL, 16);
	
	i++;

	// Iterate through characters and calculate original secret
	for (i = 0; i < len; ++i) { // `len` = number of hex pair values in each share
		int * chunks = static_cast<int*>(malloc(sizeof(int) * n  * 2));

		// Collect all shares for character i
		j=0;
		// Store x value for share
		chunks[j * 2] = x[j];//***************** x value of share 

		codon[0] = shares[j][6 + i * 2];
		codon[1] = shares[j][6 + i * 2 + 1];

		// Store y value for share
		if (memcmp(codon, "G0", 2) == 0) {
			chunks[j * 2 + 1] = 256;
		} else {
			chunks[j * 2 + 1] = strtol(codon, NULL, 16); //*****************y value of share
		}
		

		
		unsigned char letter = compute_partial_share(chunks, n, x_share, x_shares, x_shares_len); //compute_partial_share(int* xy_pairs, int n, int x_share, int* x_shares, int x_shares_len)

		//printf("%d\n",letter);
		free(chunks);

		result[i] = letter;
	}

	return result;
}

#ifdef TEST
void Test_split_string(CuTest * tc) {
	int n = 255;	/* Maximum n = 255 */
	int t = 254;	/* t <= n, we choose less than that so we have two tests */

	char * phrase = "This is a test of Bücher and Später.";

	int count = 10;
	int i;

	for (i = 0; i < count; ++i) {
		char ** result = split_string(phrase, n, t);

		/* Extract secret using first t shares */
		char * answer = join_strings(result, t);
		CuAssertStrEquals(tc, phrase, answer);
		free(answer);

		/* Extract secret using all shares */
		answer = join_strings(result, n);
		CuAssertStrEquals(tc, phrase, answer);
		free(answer);

		free_string_shares(result, n);
	}
}
#endif


/* Trim spaces at end of string */
void trim_trailing_whitespace(char * str) {
	unsigned long l;

	if (str == NULL) {
		return;
	}

	l = strlen(str);

	if (l < 1) {
		return;
	}

	while ( (l > 0) && (( str[l - 1] == ' ' ) ||
						( str[l - 1] == '\n' ) ||
						( str[l - 1] == '\r' ) ||
						( str[l - 1] == '\t' )) ) {
		str[l - 1] = '\0';
		l = strlen(str);
	}
}


/*
	extract_secret_from_share_strings() -- get a raw string, tidy it up
		into individual shares, and then extract secret

*/

char hexDigit(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value;
    } else {
        return 'A' + (value - 10);
    }
}

void intToHex(int num, char *hex) {
    hex[0] = hexDigit((num >> 4) & 0xF);
    hex[1] = hexDigit(num & 0xF);
    hex[2] = '\0'; // Null-terminate the string
}

char* convertToHex(const char* input, int x_share, int t) {
    int length = strlen(input);
    char* result = (char*)malloc(length * 2 + 1 + 6);  // Allocate memory for the result string
    
    if (result) {
		char x_share_hex[3];
		char t_hex[3];
		intToHex(x_share, x_share_hex);
		intToHex(t, t_hex);

        char* ptr = result;
		*ptr++ = x_share_hex[0];
		*ptr++ = x_share_hex[1];
		*ptr++ = t_hex[0];
		*ptr++ = t_hex[1];
		*ptr++ = 'A';
		*ptr++ = 'A';
        for (int i = 0; i < length; ++i) {
            *ptr++ = "0123456789ABCDEF"[((unsigned char)input[i]) >> 4];
            *ptr++ = "0123456789ABCDEF"[((unsigned char)input[i]) & 0x0F];
        }
        *ptr = '\0';  // Null-terminate the result string
    }
    
    return result;
}

char * extract_secret_from_share_strings(const char * string) {
	char ** shares = static_cast<char**>(malloc(sizeof(char *) * 255));

	char * share;
	char * saveptr = NULL;
	int i = 0;

	/* strtok_rr modifies the string we are looking at, so make a temp copy */
	char * temp_string = strdup(string);

	/* Parse the string by line, remove trailing whitespace */
	share = strtok_rr(temp_string, "\n", &saveptr);

	shares[i] = strdup(share);
	trim_trailing_whitespace(shares[i]);

	while ( (share = strtok_rr(NULL, "\n", &saveptr))) {
		i++;

		shares[i] = strdup(share);

		trim_trailing_whitespace(shares[i]);

		if ((shares[i] != NULL) && (strlen(shares[i]) == 0)) {
			/* Ignore blank lines */
			free(shares[i]);
			i--;
		}
	}

	i++;

	char * secret = join_strings(shares, i);

	free_string_shares(shares, i);
	free(temp_string);

	return secret;
}

char* recover_share_from_string_shares(const char * string, int x_share, int t){
	char ** shares = static_cast<char**>(malloc(sizeof(char *) * 255));

	char * share;
	char * saveptr = NULL;
	int i = 0;

	/* strtok_rr modifies the string we are looking at, so make a temp copy */
	char * temp_string = strdup(string);

	/* Parse the string by line, remove trailing whitespace */
	share = strtok_rr(temp_string, "\n", &saveptr);

	shares[i] = strdup(share);
	trim_trailing_whitespace(shares[i]);

	while ( (share = strtok_rr(NULL, "\n", &saveptr))) {
		i++;

		shares[i] = strdup(share);

		trim_trailing_whitespace(shares[i]);

		if ((shares[i] != NULL) && (strlen(shares[i]) == 0)) {
			/* Ignore blank lines */
			free(shares[i]);
			i--;
		}
	}

	i++;

	char * recovered_share = join_strings_to_recover_share(shares, i, x_share);
	

	free_string_shares(shares, i);
	free(temp_string);

	char* hex_recovered_share = convertToHex(recovered_share, x_share, t);

	return hex_recovered_share;
}


unsigned char* partial_recovery_of_share_from_one_share(const char * string, int x_share, int t, int* x_shares, int x_shares_len){ //here string = 1 "share\n"
	char ** shares = static_cast<char**>(malloc(sizeof(char *) * 255));

	char * share;
	char * saveptr = NULL;
	int i = 0;

	/* strtok_rr modifies the string we are looking at, so make a temp copy */
	char * temp_string = strdup(string);

	/* Parse the string by line, remove trailing whitespace */
	share = strtok_rr(temp_string, "\n", &saveptr);

	shares[i] = strdup(share);
	trim_trailing_whitespace(shares[i]);

	while ( (share = strtok_rr(NULL, "\n", &saveptr))) {
		i++;

		shares[i] = strdup(share);

		trim_trailing_whitespace(shares[i]);

		if ((shares[i] != NULL) && (strlen(shares[i]) == 0)) {
			/* Ignore blank lines */
			free(shares[i]);
			i--;
		}
	}

	i++;

	unsigned char * partial_recovered_share = recover_partial_share(shares, i, x_share, x_shares, x_shares_len); //int* recover_partial_share(char ** shares, int n, int x_share, int* x_shares, int x_shares_len)
	

	free_string_shares(shares, i);
	free(temp_string);


	return partial_recovered_share;
}

#ifdef TEST
void Test_extract_secret_from_share_strings(CuTest * tc) {
	char * shares = "0103AAFEBDB7A3F114\n0203AA1F407C51B784\n0303AAD9F0B37DB8C3\n0403AA29CB5B26F4D1\n0503AA11D2754D6AAE\n0603AA910400F21B5A\n0703AAA863FE1307D6\n0803AA56EE6CB32E20\n0903AA9CA44CD0903A\n0A03AA79869E6A2C23\n";

	char * secret = extract_secret_from_share_strings(shares);

	CuAssertStrEquals(tc, "secret", secret);

	free(secret);
}
#endif