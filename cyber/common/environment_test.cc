#include "environment.h"

#include <cstdlib>

#include "gtest/gtest.h"

namespace apollo {
namespace cyber {
namespace common {

TEST(EnvironmentTest, get_env) {
  unsetenv("EnvironmentTest_get_env");
  std::string env_value = GetEnv("EnvironmentTest_get_env");
  EXPECT_EQ(env_value, "");
  setenv("EnvironmentTest", "123456789", 1);
  env_value = GetEnv("EnvironmentTest");
  EXPECT_EQ(env_value, "123456789");
  unsetenv("EnvironmentTest");

  const std::string default_value = "DEFAULT_FOR_TEST";
  EXPECT_EQ(default_value, GetEnv("SOMETHING_NOT_EXIST", default_value));
}

TEST(EnvironmentTest, work_root) {
  std::string before = WorkRoot();
  unsetenv("CYBER_PATH");
  std::string after = GetEnv("CYBER_PATH");
  EXPECT_EQ(after, "");
  setenv("CYBER_PATH", before.c_str(), 1);
  after = WorkRoot();
  EXPECT_EQ(after, before);
}

}  // namespace common
}  // namespace cyber
}  // namespace apollo