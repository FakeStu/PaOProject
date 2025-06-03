# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PaOProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PaOProject_autogen.dir\\ParseCache.txt"
  "PaOProject_autogen"
  )
endif()
