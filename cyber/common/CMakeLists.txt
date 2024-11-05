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

add_library(FileLibrary file.cc)
target_link_libraries(FileLibrary
  glog::glog
  ${PROTOBUF_LIBRARIES}
  CyberProtoLib
  BinaryLibrary
)

add_executable(file_test file_test.cc)
target_link_libraries(file_test
  GTest::GTest
  GTest::Main
  pthread
  FileLibrary
)

target_include_directories(file_test PUBLIC
  "${CMAKE_BINARY_DIR}/cyber/proto"
)