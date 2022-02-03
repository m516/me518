#pragma once
#include "matrix.hpp"
#include <cmath>

namespace ME518{
    class RotationMatrix : public Matrix<3,3> {
        public:

        enum Direction {
            X,
            Y,
            Z,
            XYZ,
            ZYX
        };

        RotationMatrix(Matrix<3,3> M) : Matrix<3,3>()
        {
            M.copyTo(*this);
        }

        RotationMatrix() : Matrix<3,3>()
        {
            Matrix<3,3> I = Identity<3>();
            set<3,3>(0,0,I);
        }

        RotationMatrix
        inverse() const
        {
            // Rotation matrices are orthonormal
            // For orthonormal matrices, the inverse is just the transpose
            return transpose();
        }

        RotationMatrix 
        rotate(Direction direction, matrix_unit a, matrix_unit b = 0, matrix_unit c = 0) const
        {
            RotationMatrix R = Identity<3>();
            matrix_unit sinA = sin(a), cosA = cos(a);


            switch(direction){
                case X:
                    R.set(1, 1, cosA);  R.set(1, 2, -sinA); 
                    R.set(2, 1, sinA);  R.set(2, 2, cosA ); 
                break;
                case Y:
                    R.set(0, 0, cosA);  R.set(0, 2, sinA ); 
                    R.set(2, 0, -sinA); R.set(2, 2, cosA ); 
                break;
                case Z:
                    R.set(0, 0, cosA);  R.set(0, 1, -sinA); 
                    R.set(1, 0, sinA);  R.set(1, 1, cosA ); 
                break;
                case XYZ:
                    R = R.rotate(X, a);
                    R = R.rotate(Y, b);
                    R = R.rotate(Z, c);
                break;
                case ZYX:
                    R = R.rotate(Z, a);
                    R = R.rotate(Y, b);
                    R = R.rotate(X, c);
                break;
            }

            return *this*R;
        }

    };
}