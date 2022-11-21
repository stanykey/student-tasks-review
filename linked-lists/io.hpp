#ifndef IO_HPP
#define IO_HPP

#include <iostream>


namespace io {
    template<typename T>
    T read(std::istream& in) {
        T value{};
        in >> value;
        return value;
    }
}  // namespace io

#endif  // IO_HPP
