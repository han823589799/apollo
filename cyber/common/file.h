#ifndef CYBER_COMMON_FILE_H_
#define CYBER_COMMON_FILE_H_

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"

#include "log.h"

namespace apollo {
namespace cyber {
namespace common {

enum FileType {TYPE_FILE, TYPE_DIR};

bool SetProtoToASCIIFile(const google::protobuf::Message& message, int file_descriptor);

bool SetProtoToASCIIFile(const google::protobuf::Message& message, const std::string& file_name);

bool GetProtoFromASCIIFile(const std::string& file_name, google::protobuf::Message* message);

bool SetProtoToBinaryFile(const google::protobuf::Message& message, const std::string& file_name);

bool GetProtoFromBinaryFile(const std::string& file_name, google::protobuf::Message* message);

bool GetProtoFromFile(const std::string& file_name, google::protobuf::Message* message);

bool GetProtoFromJsonFile(const std::string& file_name, google::protobuf::Message* message);

bool GetContent(const std::string& file_name, std::string* content);

std::string GetAbsolutePath(const std::string& prefix, const std::string& relative_path);

bool PathExists(const std::string& path);

bool PathIsAbsolute(const std::string& path);

bool DirectoryExists(const std::string& directory_path);

std::vector<std::string> Glob(const std::string& pattern);

bool CopyFile(const std::string& from, const  std::string& to);

bool CopyDir(const std::string& from, const std::string& to);

bool Copy(const std::string& from, const std::string& to);

bool EnsureDirectory(const std::string& directory_path);

bool RemoveAllFiles(const std::string& directory_path);

std::vector<std::string> ListSubPaths(const std::string& directory_path,
                                      const unsigned char d_type = DT_DIR);

size_t FindPathByPattern(const std::string& base_path, const std::string& patt,
                         const unsigned char d_type, const bool recursive,
                         std::vector<std::string>* result_list);

std::string GetDirName(const std::string& path);

std::string GetFileName(const std::string& path, const bool remove_extension = false);

bool GetFilePathWithEnv(const std::string& path, const std::string& env_var,
                        std::string* file_path);

std::string GetCurrentPath();

bool DeleteFile(const std::string& filename);

bool GetType(const std::string& filename, FileType* type);

bool CreateDir(const std::string& dir);

template <typename T>
bool loadConfig(const std::string& relative_path, T* config) {
  CHECK_NOTNULL(config);
  std::string actual_config_path;
  if (!GetFilePathWithEnv(relative_path, "APOLLO_CONF_PATH",
                          &actual_config_path)) {
    AERROR << "conf file [" << relative_path << "] is not found in APOLLO_CONF_PATH";
    return false;
  }
  AINFO << "load conf file: " << actual_config_path;
  return GetProtoFromFile(actual_config_path, config);
}

}  // namespace common
}  // namespace cyber
}  // namespace apollo

#endif  // CYBER_COMMON_FILE_H_