#include "file.h"

#include <cstdlib>
#include <string>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "unit_test.pb.h"

namespace apollo {
namespace cyber {
namespace common {

TEST(FileTest, proto_set_get_test) {
  apollo::cyber::proto::UnitTest message;
  message.set_class_name("FileTest");
  apollo::cyber::proto::UnitTest read_message;
  EXPECT_FALSE(SetProtoToASCIIFile(message, -1));
  EXPECT_FALSE(SetProtoToASCIIFile(message, "not_exists_dir/message.proto"));
  EXPECT_TRUE(SetProtoToASCIIFile(message, "message.ascii"));
  EXPECT_TRUE(SetProtoToBinaryFile(message, "message.binary"));
  EXPECT_FALSE(GetProtoFromASCIIFile("not_exists_dir/message.proto", &read_message));
  EXPECT_FALSE(GetProtoFromBinaryFile("not_exists_dir/message.proto", &read_message));
  EXPECT_TRUE(GetProtoFromASCIIFile("message.ascii", &read_message));
  EXPECT_TRUE(GetProtoFromBinaryFile("message.binary", &read_message));
  EXPECT_FALSE(GetProtoFromFile("not_exists_dir/message.proto", &read_message));
  EXPECT_TRUE(GetProtoFromFile("message.binary", &read_message));

  remove("message.binary");
  remove("message.ascii");
}

TEST(FileTest, file_utils_test) {
  apollo::cyber::proto::UnitTest message;
  message.set_class_name("FileTest");
  apollo::cyber::proto::UnitTest read_message;
  EXPECT_TRUE(SetProtoToBinaryFile(message, "message.binary"));

  std::string content;
  GetContent("message.binary", &content);
  EXPECT_FALSE(content.empty());
  content = "";
  GetContent("not_exists_dir/message.proto", &content);
  EXPECT_EQ("", content);

  EXPECT_TRUE(PathExists("./"));
  EXPECT_FALSE(PathExists("not_exists_file"));
}

}  // common
}  // cyber
}  // apollo