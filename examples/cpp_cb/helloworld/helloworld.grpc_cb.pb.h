// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: helloworld.proto
#ifndef GRPC_CB_helloworld_2eproto__INCLUDED
#define GRPC_CB_helloworld_2eproto__INCLUDED

#include <grpc_cb/grpc_cb.h>  // Include all for user.

#include "helloworld.pb.h"

// package helloworld
namespace helloworld {

namespace Greeter {  // service Greeter

const ::google::protobuf::ServiceDescriptor& GetServiceDescriptor();

class Stub : public ::grpc_cb::ServiceStub {
 public:
  explicit Stub(const ::grpc_cb::ChannelSptr& channel,
      const ::grpc_cb::CompletionQueueForNextSptr& cq4n_sptr = nullptr);

  ::grpc_cb::Status Sync_SayHello(
      const ::helloworld::HelloRequest& request,
      ::helloworld::HelloReply* response = nullptr);

  using SayHello_RespCb = ::grpc_cb::MsgCbTmpl<::helloworld::HelloReply>;
  void Async_SayHello(
      const ::helloworld::HelloRequest& request,
      const SayHello_RespCb& cb = SayHello_RespCb(),
      const ::grpc_cb::ErrorCb& ecb = ::grpc_cb::ErrorCb());

};  // class Stub

class Service : public ::grpc_cb::Service {
 public:
  Service();
  virtual ~Service();

  virtual const std::string& GetMethodName(size_t i) const GRPC_OVERRIDE;
  virtual void CallMethod(
      size_t method_index, grpc_byte_buffer* request_buffer,
      const ::grpc_cb::CallSptr& call_sptr) GRPC_OVERRIDE;

 public:
  using SayHello_Replier = ::grpc_cb::ServerReplier<
      ::helloworld::HelloReply>;
 protected:
  virtual void SayHello(
      const ::helloworld::HelloRequest& request,
      SayHello_Replier replier);
 private:
  void SayHello(
      grpc_byte_buffer& request_buffer,
      const SayHello_Replier& replier);

 private:
  virtual const ::google::protobuf::ServiceDescriptor& GetDescriptor()
      const GRPC_OVERRIDE {
    return GetServiceDescriptor();
  }
};

}  // namespace Greeter

}  // namespace helloworld

#endif  // GRPC_CB_helloworld_2eproto__INCLUDED
