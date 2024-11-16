#include "atomic_hash_map.h"

#include <string>
#include <thread>

#include "gtest/gtest.h"

namespace apollo {
namespace cyber {
namespace base {

TEST(AtomicHashMapTest, int_int) {
  AtomicHashMap<int, int> map;
  int value = 0;
  for (int i = 0; i < 1000; i++) {
    map.Set(i, i);
    EXPECT_TRUE(map.Has(i));
    EXPECT_TRUE(map.Get(i, &value));
    EXPECT_EQ(i, value);
  }

  for (int i = 0; i < 1000; i++) {
    map.Set(1000 - i, i);
    EXPECT_TRUE(map.Has(1000 - i));
    EXPECT_TRUE(map.Get(1000 - i, &value));
    EXPECT_EQ(i, value);
  }
}

}  // namespace base
}  // namespace cyber
}  // namespace apollo