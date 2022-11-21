set(header_files
    forward_list.hpp
    list.hpp)

add_library(lists_lib INTERFACE)
target_sources(lists_lib INTERFACE ${header_files})

add_executable(linked-list main.cpp)
target_link_libraries(linked-list PRIVATE lists_lib)
