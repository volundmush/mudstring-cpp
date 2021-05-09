set(header_path "${mudstring_SOURCE_DIR}/include/mudstring")

set(header "${header_path}/mudstring.hpp" "${header_path}/color.hpp" "${header_path}/style.hpp"
        "${header_path}/text.hpp")

set(src "mudstring.cpp" "color.cpp" "style.cpp" "text.cpp")

#configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

find_package(Boost REQUIRED)

add_library(mudstring ${header} ${src})
target_include_directories(mudstring PUBLIC ${mudstring_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR} ${Boost_INCLUDE_DIRS})
target_link_libraries(mudstring)