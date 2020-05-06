#include "brave/components/brave_sync/fake_access_token_fetcher.h"

#include "base/threading/thread_task_runner_handle.h"
#include "base/time/time.h"

namespace brave_sync {

FakeAccessTokenFetcher::FakeAccessTokenFetcher(AccessTokenConsumer* consumer)
    : AccessTokenFetcher(consumer) {}

FakeAccessTokenFetcher::~FakeAccessTokenFetcher() {}

void FakeAccessTokenFetcher::Start(const std::string& client_id,
                                   const std::string& client_secret,
                                   const std::string& timestamp) {
  AccessTokenConsumer::TokenResponse response = pending_response_;
  if (response.access_token.empty())
    response = AccessTokenConsumer::TokenResponse("access_token",
        base::Time::Now() + base::TimeDelta::FromHours(1), "");
  if (pending_error_.state() == GoogleServiceAuthError::NONE) {
    base::ThreadTaskRunnerHandle::Get()->PostTask(
        FROM_HERE, base::BindOnce(&FakeAccessTokenFetcher::OnGetTokenSuccess,
          weak_ptr_factory_.GetWeakPtr(), response));
  } else {
    base::ThreadTaskRunnerHandle::Get()->PostTask(
        FROM_HERE, base::BindOnce(&FakeAccessTokenFetcher::OnGetTokenFailure,
          weak_ptr_factory_.GetWeakPtr(), pending_error_));
  }
}

void FakeAccessTokenFetcher::SetAccessTokenResponseForTest(
    const AccessTokenConsumer::TokenResponse& token_response) {
  pending_response_ = token_response;
}

void FakeAccessTokenFetcher::SetTokenResponseCallback(
    base::OnceClosure on_available) {
  on_available_ = std::move(on_available);
}

void FakeAccessTokenFetcher::SetTokenResponseError(
    const GoogleServiceAuthError& error) {
  pending_error_ = error;
}

void FakeAccessTokenFetcher::OnGetTokenSuccess(
    const AccessTokenConsumer::TokenResponse& token_response) {
  FireOnGetTokenSuccess(token_response);
  if (on_available_)
    std::move(on_available_).Run();
  pending_response_ = AccessTokenConsumer::TokenResponse();
}

void FakeAccessTokenFetcher::OnGetTokenFailure(
    const GoogleServiceAuthError& error) {
  FireOnGetTokenFailure(error);
  if (on_available_)
    std::move(on_available_).Run();
  pending_error_ = GoogleServiceAuthError();
}

void FakeAccessTokenFetcher::StartGetTimestamp() {
  FireOnGetTimestampSuccess("dummy_timestamp");
}

void FakeAccessTokenFetcher::CancelRequest() {}

}  // namespace brave_sync