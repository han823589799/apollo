#ifndef CYBER_BINARY_H_
#define CYBER_BINARY_H_

#include <string>

namespace apollo {
namespace cyber {
namespace binary {
std::string GetName();
void SetName(const std::string& name);
}  // namespace binary
}  // namespace cyber
}  // namespace apollo
#endif  // CYBER_BINARY_H_