#pragma once
#include "matrix.hpp"
#include <cmath>

namespace ME518{
    class TranslationMatrix : public Matrix<3,1> {
        public:

        enum Direction{X,Y,Z};

        TranslationMatrix(Matrix<3,1> M) : Matrix<3,1>()
        {
            M.copyTo(this);
        }

        TranslationMatrix() : Matrix<3,1>()
        {

        }

        void
        operator=(Matrix<3,1> M){
            M.copyTo(this);
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