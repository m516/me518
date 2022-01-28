#pragma once
#include <exception>

namespace ME518{

    class MatrixIndexOutOfBounds : public std::invalid_argument{
        public:
        MatrixIndexOutOfBounds() : std::invalid_argument("Matrix index is out of bounds") {};
    };


}