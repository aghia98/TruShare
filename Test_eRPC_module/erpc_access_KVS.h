/*
 * Generated by erpcgen 1.10.0 on Thu Apr 13 14:57:26 2023.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_erpc_access_KVS_h_)
#define _erpc_access_KVS_h_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "erpc_version.h"

#if 11000 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

#if !defined(ERPC_TYPE_DEFINITIONS_ERPC_ACCESS_KVS)
#define ERPC_TYPE_DEFINITIONS_ERPC_ACCESS_KVS

#endif // ERPC_TYPE_DEFINITIONS_ERPC_ACCESS_KVS

/*! @brief AccessKVS identifiers */
enum _AccessKVS_ids
{
    kAccessKVS_service_id = 1,
    kAccessKVS_erpcGet_id = 1,
    kAccessKVS_erpcPut_id = 2,
};

#if defined(__cplusplus)
extern "C" {
#endif

//! @name AccessKVS
//@{
void erpcGet(int32_t k, int32_t * v);

void erpcPut(int32_t k, int32_t v);
//@}

#if defined(__cplusplus)
}
#endif

#endif // _erpc_access_KVS_h_