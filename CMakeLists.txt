cmake_minimum_required(VERSION 3.20)
project(mudstring VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(include_dest "include/mudstring-${CMAKE_PROJECT_VERSION}")
set(main_lib_dest "lib/mudstring-${CMAKE_PROJECT_VERSION}")
set(lib_dest ${main_lib_dest}/${CMAKE_BUILD_TYPE})

# add subdiretories
add_subdirectory(src)
#add_subdirectory(example)
#add_subdirectory(tool)
#add_subdirectory(test)

install(FILES mudstring-config.cmake DESTINATION ${main_lib_dest})
install(EXPORT mudstring DESTINATION "${lib_dest}")