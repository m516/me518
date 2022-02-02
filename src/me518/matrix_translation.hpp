#pragma once
#include "matrix.hpp"
#include <cmath>

namespace ME518{
    class TranslationMatrix : public Matrix<3,1> {
        public:

        TranslationMatrix(Matrix<3,1> M) : Matrix<3,1>()
        {
            M.copyTo(*this);
        }

        TranslationMatrix() : Matrix<3,1>()
        {

        }

        TranslationMatrix(matrix_unit x, matrix_unit y = 0, matrix_unit z = 0) : Matrix<3,1>()
        {
            set(0,0,x);
            set(1,0,y);
            set(2,0,z);
        }

        matrix_unit length(){
            return sqrt(
                data[0][0]*data[0][0]+
                data[1][0]*data[1][0]+
                data[2][0]*data[2][0]
            );
        }

    };
}