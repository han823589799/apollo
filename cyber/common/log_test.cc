#include "log.h"
#include "gtest/gtest.h"
#include "glog/logging.h"

namespace apollo {
namespace cyber {
namespace common {

TEST(LogTest, TestAll) { AINFO << "11111"; }

}  // namespace common
}  // namespace cyber
}  // namespace apollo