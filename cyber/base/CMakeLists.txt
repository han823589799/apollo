find_package(GTest REQUIRED)

add_executable(AtomicRWLock atomic_rw_lock_test.cc)

target_link_libraries(AtomicRWLock
  GTest::GTest
  GTest::Main
  pthread
)