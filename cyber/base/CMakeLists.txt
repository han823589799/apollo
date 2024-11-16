find_package(GTest REQUIRED)

add_executable(AtomicRWLockTest atomic_rw_lock_test.cc)

target_link_libraries(AtomicRWLockTest
  GTest::GTest
  GTest::Main
  pthread
)

add_executable(AtomicHashMapTest atomic_hash_map_test.cc)

target_link_libraries(AtomicHashMapTest
  GTest::GTest
  GTest::Main
  pthread
)