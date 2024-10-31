find_package(glog REQUIRED)
find_package(GTest REQUIRED)
find_package(Protobuf REQUIRED)

add_executable(log_test log_test.cc)

target_link_libraries(log_test
  GTest::GTest
  GTest::Main
  pthread
  glog::glog
  BinaryLibrary
)

target_include_directories(log_test PUBLIC
  "${PROJECT_SOURCE_DIR}/cyber"
)

add_library(FileLibrary file.cc)

target_link_libraries(FileLibrary
  ${PROTOBUF_LIBRARIES}
)