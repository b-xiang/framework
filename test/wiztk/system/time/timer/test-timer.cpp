//
// Created by zhanggyb on 16-9-19.
//

#include "test-timer.hpp"

#include <wiztk/system/time/timer.hpp>
#include <iostream>

using wiztk::system::time::Timer;

class Response {
 public:

  Response()
      : count_(10) {
    timer_.SetInterval(1000);
    timer_.expire().Bind(this, &Response::OnTimeout);
  }

  ~Response() {}

  void Start() {
    timer_.Start();
  }

  void Stop() {
    timer_.Stop();
  }

  bool IsArmed() const {
    return timer_.is_armed();
  }

 private:

  void OnTimeout();

  int count_;

  Timer timer_;
};

void Response::OnTimeout() {
  std::cout << "Timeout count #" << count_ << std::endl;
  count_--;
  if (count_ == 0)
    timer_.Stop();
}

TEST_F(TestTimer, expire_1) {
  Timer t;
  t.SetInterval(1000);
  int count = 0;

  auto l = [&] {
    count++;
    std::cout << "count: " << count << std::endl;
    if (count == 10) t.Stop();
  };

  t.expire().Bind(l);

  std::cout << "before start: count: " << count << std::endl;

  t.Start();

  while (true) {
    sleep(1);
    if (!t.is_armed()) break;
  }

  std::cout << "after stop: count: " << count << std::endl;

  ASSERT_TRUE(count == 10);
}

TEST_F(TestTimer, timeout_1) {
  Response response;

  response.Start();

  while (true) {
    sleep(1);
    if (!response.IsArmed()) break;
  }

  ASSERT_TRUE(true);
}
