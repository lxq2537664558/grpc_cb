// Licensed under the Apache License, Version 2.0.
// Author: Jin Qing (http://blog.csdn.net/jq0123)

#ifndef GRPC_CB_GRPC_CB_H
#define GRPC_CB_GRPC_CB_H

#include <grpc_cb_core/client/channel.h>       // for Channel
#include <grpc_cb_core/common/completion_queue.h>  // for CompletionQueue
#include <grpc_cb_core/common/completion_queue_for_next.h>  // for CompletionQueueForNext
#include <grpc_cb_core/common/completion_queue_for_next_sptr.h>  // for CompletionQueueForNextSptr
#include <grpc_cb_core/common/run.h>     // for Run()
#include <grpc_cb_core/server/server.h>  // for Server
#include <grpc_cb_core/server/service_sptr.h>  // for ServiceSptr

namespace grpc_cb {
using grpc_cb_core::Channel;
using grpc_cb_core::CompletionQueue;
using grpc_cb_core::CompletionQueueForNext;
using grpc_cb_core::CompletionQueueForNextSptr;
using grpc_cb_core::Run;
using grpc_cb_core::Server;
using grpc_cb_core::ServiceSptr;
}  // namespace grpc_cb

#include <grpc_cb/client/channel_sptr.h>
#include <grpc_cb/client/client_async_reader.h>
#include <grpc_cb/client/client_async_reader_writer.h>
#include <grpc_cb/client/client_async_writer.h>
#include <grpc_cb/client/client_sync_reader.h>
#include <grpc_cb/client/client_sync_reader_writer.h>
#include <grpc_cb/client/client_sync_writer.h>
#include <grpc_cb/client/msg_cb_tmpl.h>   // for MsgCbTmpl<>
#include <grpc_cb/client/service_stub.h>  // for ServiceStub
#include <grpc_cb/client/status_cb.h>     // for StatusCb
#include <grpc_cb/client/stub_helper.h>   // for StubHelper

#include <grpc_cb/common/proto_utils.h>  // for Proto::Deserialize()
#include <grpc_cb/common/status_fwd.h>  // for Status

#include <grpc_cb/server/server_reader_for_bidi_streaming.h>
#include <grpc_cb/server/server_reader_for_client_side_streaming.h>
#include <grpc_cb/server/server_replier.h>   // for ServerReplier<>
#include <grpc_cb/server/server_writer.h>    // for ServerWriter<>
#include <grpc_cb/server/service.h>          // for Service

#endif  // GRPC_CB_GRPC_CB_H
