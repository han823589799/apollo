#ifndef CYBER_COMMON_ENVIRONMENT_H_
#define CYBER_COMMON_ENVIRONMENT_H_

#include <cassert>
#include <string>

#include "log.h"

namespace apollo {
namespace cyber {
namespace common {

inline std::string GetEnv(const std::string& var_name,
                          const std::string& default_value = "") {
  const char* var = std::getenv(var_name.c_str());
  if (var == nullptr) {
    AWARN << "Environment variable [" << var_name << "] not set, fallback to "
          << default_value;
    return default_value;
  }
  return std::string(var);
}

inline const std::string WorkRoot() {
  std::string work_root = GetEnv("CYBER_PATH");
  if (work_root.empty()) {
    work_root = "/apollo/cyber";
  }
  return work_root;
}

}  // namespace common
}  // namespace cyber
}  // namespace apollo

#endif  // CYBER_COMMON_ENVIRONMENT_H_