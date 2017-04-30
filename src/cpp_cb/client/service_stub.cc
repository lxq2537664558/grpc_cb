// Licensed under the Apache License, Version 2.0.
// Author: Jin Qing (http://blog.csdn.net/jq0123)

#include <grpc_cb/service_stub.h>

#include <grpc_cb/channel.h>  // for GetCallTimeoutMs()
#include <grpc_cb/impl/call.h>
#include <grpc_cb/impl/client/client_call_cqtag.h>  // for ClientCallCqTag
#include <grpc_cb/impl/cqueue_for_next.h>  // for CQueueForNext
#include <grpc_cb/impl/cqueue_for_pluck.h>  // for CQueueForPluck

#include "common/do_next_completion.h"  // for DoNextCompletion()

namespace grpc_cb {

ErrorCallback ServiceStub::default_error_callback_;  // Default empty.

ServiceStub::ServiceStub(const ChannelSptr& channel_sptr)
    : channel_sptr_(channel_sptr),  // copy shared_ptr
    cq4n_sptr_(new CQueueForNext),
    error_callback_(default_error_callback_),
    call_timeout_ms_(channel_sptr->GetCallTimeoutMs()) {
  assert(channel_sptr);
}

ServiceStub::~ServiceStub() {
  assert(cq4n_sptr_);
}

Status ServiceStub::BlockingRequest(const string& method, const string& request,
                                    string& response) {
  CQueueForPluck cq4p;
  CallSptr call_sptr(MakeSharedCall(method, cq4p));
  ClientCallCqTag tag(call_sptr);
  if (!tag.Start(request))
    return ::grpc_cb::Status::InternalError("Failed to request.");
  cq4p.Pluck(&tag);
  return tag.GetResponseString(response);
}

void ServiceStub::AsyncRequest(const string& method, const string& request,
                               const OnResponse& on_resonse,
                               const ErrorCallback& on_error) {
  // XXX
}

// Blocking run stub.
void ServiceStub::BlockingRun() {
  assert(cq4n_sptr_);
  CQueueForNext& cq4n = *cq4n_sptr_;
  while (DoNextCompletion(cq4n))
    ;
}

void ServiceStub::Shutdown() {
  assert(cq4n_sptr_);
  cq4n_sptr_->Shutdown();
}

}  // namespace grpc_cb

