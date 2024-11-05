#include "atomic_rw_lock.h"

#include <thread>
#include "gtest/gtest.h"
#include "reentrant_rw_lock.h"

namespace apollo {
namespace cyber {
namespace base {

TEST(ReentrantRWLockTest, read_lock) {
  int count = 0;
  int thread_init = 0;
  bool flag = true;
  ReentrantRWLock lock;
  auto f = [&]() {
    ReadLockGuard<ReentrantRWLock> lg(lock);
    count++;
    thread_init++;
    while (flag) {
        std::this_thread::yield();
    }
  };
  std::thread t1(f);
  std::thread t2(f);
  while (thread_init != 2) {
    std::this_thread::yield();
  }
  EXPECT_EQ(2, count);
  flag = false;
  t1.join();
  t2.join();
  {
    ReadLockGuard<ReentrantRWLock> lg1(lock);
    {
      ReadLockGuard<ReentrantRWLock> lg2(lock);
      {
        ReadLockGuard<ReentrantRWLock> lg3(lock);
        {
          ReadLockGuard<ReentrantRWLock> lg4(lock);
        }
      }
    }
  }
}
}  // base
}  // cyber
}  // apollo