find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS unit_test.proto)

message(STATUS ${PROTO_SRCS})

add_library(CyberProtoLib ${PROTO_SRCS})

# target_link_libraries(CyberProtoLib
  # ${PROTOBUF_LIBRARIES}
# )

# target_include_directories(CyberProtoLib PUBLIC
  # ${CMAKE_CURRENT_BINARY_DIR}
# )