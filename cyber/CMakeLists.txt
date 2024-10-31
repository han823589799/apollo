add_subdirectory(common)

add_library(BinaryLibrary binary.cc)

target_include_directories(BinaryLibrary PUBLIC
  "${PROJCET_SOURCE_DIR}"
)

add_library(StateLibrary state.cc)

target_include_directories(StateLibrary PUBLIC
  "${PROJCET_SOURCE_DIR}"
)