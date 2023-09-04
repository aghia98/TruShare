/*

	main.c -- Template main()

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

#include <stdio.h>
#include <stdlib.h>
#include <string>

//#include "../SS_no_gmp_module/ss-worker.h"
#include "combine.h"

using namespace std;


//#define kBUFFERSIZE 4096	// How many bytes to read at a time

void copyString(string source, char* destination) {
    for (size_t i = 0; i < source.length(); ++i) {
        destination[i] = source[i];
    }
    destination[source.length()] = '\0'; // Append null character to terminate the string
}

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

char* convertToHex(int* input, int size_input, int x_share, int t) {
    char* result = (char*)malloc(sizeof(char) * size_input * 2 + 5);  // Allocate memory for the result string
    
    if (result) {
        char hex[3];
        char* ptr = result;
        
        intToHex(x_share, hex);
        *ptr++ = hex[0];
        *ptr++ = hex[1];
        
        intToHex(t, hex);
        *ptr++ = hex[0];
        *ptr++ = hex[1];
        
        *ptr++ = 'A';
		*ptr++ = 'A';
        
        for (int i = 0; i < size_input; i++) {
            intToHex(input[i], hex);
            *ptr++ = hex[0];
            *ptr++ = hex[1];
        }
        *ptr = '\0';  // Null-terminate the result string
    }
    
    return result;
}


int main( int argc, char ** argv ) {
    

    //DString * shares = stdin_buffer();
	string share1="0203AA7FD708A0D1C2460C1A73697A492E555DC0894752";
	string share2="0303AA2E8C2069ED3A0D4C2D8BB515090967441AADBED8";
	string share3="0403AA94EABCFC8B8FBE2EFA5B87FB02893477E9E2CC00";
	int len_res = 20;
	int res[20];

	string shares_string = share1+'\n'+share2+'\n'+share3+'\n';	
	
	string share1_string = share1+'\n';
	string share2_string = share2+'\n';
	string share3_string = share3+'\n';

	//const char* combined_shares = shares_string.c_str();
	char* combined_shares = static_cast<char*>(malloc((shares_string.length()+1)*sizeof(char)));
	
	char* share1_c_str = static_cast<char*>(malloc((share1_string.length()+1)*sizeof(char)));
	char* share2_c_str = static_cast<char*>(malloc((share2_string.length()+1)*sizeof(char)));
	char* share3_c_str = static_cast<char*>(malloc((share3_string.length()+1)*sizeof(char)));

	copyString(shares_string, combined_shares); 
	
	copyString(share1, share1_c_str);
	copyString(share2, share2_c_str);
	copyString(share3, share3_c_str);

	printf("%s\n",combined_shares);

	
	int x_share = 5;
	int x_shares[3] = {2,3,4};
	int x_shares_len = 3;

	int prime = 257;
	int t=3;

    char * secret = extract_secret_from_share_strings(combined_shares);
	//char* hex = recover_share_from_string_shares(combined_shares, x_share, 3);

	fprintf(stdout, "%s\n", secret);
	
	//int* partial_recovery_of_share_from_one_share(const char * one_share, int x_share, int t, int* x_shares, int x_shares_len)
	int* res1 = partial_recovery_of_share_from_one_share(share1_c_str, x_share, x_shares, x_shares_len);
	int* res2 = partial_recovery_of_share_from_one_share(share2_c_str, x_share, x_shares, x_shares_len);
	int* res3 = partial_recovery_of_share_from_one_share(share3_c_str, x_share, x_shares, x_shares_len);

	for(int i=0; i < len_res ; i++){
		res[i] = (res1[i]+res2[i]+res3[i])%prime;
		printf("%d...%d...%d...%d...%02X\n",res1[i],res2[i],res3[i],res[i],res[i]);
		//printf("%d\n",res1[i]);
		//printf("%d\n",res2[i]);
		//printf("%d\n",res3[i]);
	}

	//fprintf(stdout, "%s\n", hex);
	char* res_str = convertToHex(res, len_res, x_share, t);
	printf("%s\n", res_str);
    

    free(secret);
	//free(hex);
    free(combined_shares);

	free(share1_c_str);
	free(share2_c_str);
	free(share3_c_str);
	free(res1);
	free(res2);
	free(res3);
	free(res_str);
}
