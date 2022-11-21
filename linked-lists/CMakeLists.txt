set(utils_files io.hpp)
add_library(utils_lib INTERFACE)
target_sources(utils_lib INTERFACE ${utils_files})

set(lists_files forward_list.hpp list.hpp)
add_library(lists_lib INTERFACE)
target_sources(lists_lib INTERFACE ${lists_files})

add_executable(linked-list main.cpp io.hpp)
target_link_libraries(linked-list PRIVATE utils_lib lists_lib)
