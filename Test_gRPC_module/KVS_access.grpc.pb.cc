// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: KVS_access.proto

#include "KVS_access.pb.h"
#include "KVS_access.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace keyvaluestore {

static const char* KVS_method_names[] = {
  "/keyvaluestore.KVS/Get",
  "/keyvaluestore.KVS/Put",
  "/keyvaluestore.KVS/Delete",
};

std::unique_ptr< KVS::Stub> KVS::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< KVS::Stub> stub(new KVS::Stub(channel, options));
  return stub;
}

KVS::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Get_(KVS_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Put_(KVS_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(KVS_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status KVS::Stub::Get(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::keyvaluestore::Value* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Get_, context, request, response);
}

void KVS::Stub::async::Get(::grpc::ClientContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, std::move(f));
}

void KVS::Stub::async::Get(::grpc::ClientContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluestore::Value, ::keyvaluestore::Key, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status KVS::Stub::Put(::grpc::ClientContext* context, const ::keyvaluestore::KV_pair& request, ::keyvaluestore::Value* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluestore::KV_pair, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Put_, context, request, response);
}

void KVS::Stub::async::Put(::grpc::ClientContext* context, const ::keyvaluestore::KV_pair* request, ::keyvaluestore::Value* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluestore::KV_pair, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Put_, context, request, response, std::move(f));
}

void KVS::Stub::async::Put(::grpc::ClientContext* context, const ::keyvaluestore::KV_pair* request, ::keyvaluestore::Value* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Put_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::PrepareAsyncPutRaw(::grpc::ClientContext* context, const ::keyvaluestore::KV_pair& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluestore::Value, ::keyvaluestore::KV_pair, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Put_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::AsyncPutRaw(::grpc::ClientContext* context, const ::keyvaluestore::KV_pair& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPutRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status KVS::Stub::Delete(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::keyvaluestore::Value* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Delete_, context, request, response);
}

void KVS::Stub::async::Delete(::grpc::ClientContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, std::move(f));
}

void KVS::Stub::async::Delete(::grpc::ClientContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::PrepareAsyncDeleteRaw(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluestore::Value, ::keyvaluestore::Key, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluestore::Value>* KVS::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::keyvaluestore::Key& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

KVS::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KVS_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KVS::Service, ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KVS::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluestore::Key* req,
             ::keyvaluestore::Value* resp) {
               return service->Get(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KVS_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KVS::Service, ::keyvaluestore::KV_pair, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KVS::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluestore::KV_pair* req,
             ::keyvaluestore::Value* resp) {
               return service->Put(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KVS_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KVS::Service, ::keyvaluestore::Key, ::keyvaluestore::Value, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KVS::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluestore::Key* req,
             ::keyvaluestore::Value* resp) {
               return service->Delete(ctx, req, resp);
             }, this)));
}

KVS::Service::~Service() {
}

::grpc::Status KVS::Service::Get(::grpc::ServerContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status KVS::Service::Put(::grpc::ServerContext* context, const ::keyvaluestore::KV_pair* request, ::keyvaluestore::Value* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status KVS::Service::Delete(::grpc::ServerContext* context, const ::keyvaluestore::Key* request, ::keyvaluestore::Value* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace keyvaluestore

