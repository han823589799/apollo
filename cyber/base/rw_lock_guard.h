#ifndef CYBER_BASE_RW_LOCK_GUARD_H_
#define CYBER_BASE_RW_LOCK_GUARD_H_

#include <unistd.h>

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>

namespace apollo {
namespace cyber {
namespace base {

template <typename RWLock>
class ReadLockGuard {
 public:
  explicit ReadLockGuard(RWLock& lock) : rw_lock_(lock) {rw_lock_.ReadLock(); }

  ~ReadLockGuard() {rw_lock_.ReadUnlock(); }
 private:
  ReadLockGuard(const ReadLockGuard& other) = delete;
  ReadLockGuard& operator=(const ReadLockGuard& other) = delete;
  RWLock& rw_lock_;
};

template <typename RWLock>
class WriteLockGuard {
 public:
  explicit WriteLockGuard(RWLock& lock) : rw_lock_(lock) {rw_lock_.WriteLock(); }

  ~WriteLockGuard() {rw_lock_.WriteUnlock(); }
 private:
  WriteLockGuard(const WriteLockGuard& other) = delete;
  WriteLockGuard& operator=(const WriteLockGuard& other) = delete;
  RWLock& rw_lock_;
};
}  // namespace base
}  // namespace cyber
}  // namespace apollo
#endif  // CYBER_BASE_RW_LOCK_GUARD_H_