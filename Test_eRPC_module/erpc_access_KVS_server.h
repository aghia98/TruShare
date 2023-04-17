#if !defined(_erpc_access_KVS_server_h_)
#define _erpc_access_KVS_server_h_

#ifdef __cplusplus
#include "erpc_server.hpp"
#include "erpc_codec.hpp"
extern "C"
{
#include "erpc_access_KVS.h"
#include <stdint.h>
#include <stdbool.h>
}

#if 11000 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif


/*!
 * @brief Service subclass for AccessKVS.
 */
class AccessKVS_service : public erpc::Service
{
public:
    AccessKVS_service() : Service(kAccessKVS_service_id) {}

    /*! @brief Call the correct server shim based on method unique ID. */
    virtual erpc_status_t handleInvocation(uint32_t methodId, uint32_t sequence, erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory);

private:
    /*! @brief Server shim for erpcGet of AccessKVS interface. */
    erpc_status_t erpcGet_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);

    /*! @brief Server shim for erpcPut of AccessKVS interface. */
    erpc_status_t erpcPut_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);
};

extern "C" {
#else
#include "erpc_access_KVS.h"
#endif // __cplusplus

typedef void * erpc_service_t;

/*! @brief Return AccessKVS_service service object. */
erpc_service_t create_AccessKVS_service(void);

/*! @brief Destroy AccessKVS_service service object. */
void destroy_AccessKVS_service(erpc_service_t service);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _erpc_access_KVS_server_h_