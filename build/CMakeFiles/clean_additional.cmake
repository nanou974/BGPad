# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/bgpad_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/bgpad_autogen.dir/ParseCache.txt"
  "bgpad_autogen"
  )
endif()
