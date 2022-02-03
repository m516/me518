#pragma once
#include "matrix.hpp"
#include "matrix_rotation.hpp"
#include "matrix_translation.hpp"

namespace ME518{
    class TransformationMatrix : public Matrix<4,4> {
        public:

        TransformationMatrix(Matrix<4,4> M) : Matrix<4,4>()
        {
            M.copyTo(*this);
        }


        TransformationMatrix(RotationMatrix R, TranslationMatrix T) : Matrix<4, 4>()
        {
            setRotation(R);
            setTranslation(T);
            set(3, 3, 1);
        }

        TransformationMatrix() : Matrix<4,4>()
        {
            RotationMatrix R;
            setRotation(R);
            set(3, 3, 1);
        }


        TranslationMatrix
        getTranslation() const{
            //Get the current translation and add p
            /*
                get<3,1> gets a 3x1 submatrix from this matrix
                (0,3) coordinates of the top left element of the matrix to get
            */
            return TranslationMatrix(get<3,1>(0,3));
        }

        RotationMatrix
        getRotation() const{
            //Get the current rotation and multiply by R
            /*
                get<3,3> gets a 3x3 submatrix from this matrix
                (0,0) coordinates of the top left element of the matrix to get
            */
            return RotationMatrix(get<3,3>(0,0));
        }

        TransformationMatrix
        translate(TranslationMatrix p) const
        {
            //Make a new transformation matrix
            TransformationMatrix T;
            copyTo(T);

            // Set the translation
            T.setTranslation(getTranslation() + p);

            return T;
        }

        TransformationMatrix
        rotate(RotationMatrix R) const
        {
            //Make a new transformation matrix
            TransformationMatrix T;
            copyTo(T);

            // Set the rotation
            T.setRotation(getRotation() * R);

            return T;
        }

        void
        setTranslation(const TranslationMatrix &p)
        {
            // Set the translation
            set<3,1>(0, 3, p);
        }

        void
        setRotation(const RotationMatrix &R)
        {
            // Set the rotation
            set<3,3>(0, 0, R);
        }

        TransformationMatrix
        inverse() const
        {
            //Make a new transformation matrix
            TransformationMatrix T;
            copyTo(T);

            //rotation
            T.setRotation(getRotation().inverse());

            //translation
            T.setTranslation(T.getRotation()*getTranslation()*-1.0);

            return T;
        }

        TranslationMatrix
        transform(const TranslationMatrix &p) const
        {
            //Using homogeneous coordinates
            //Convert this point into a 4x1
            Matrix<4,1> pe; //point extended
            pe.set<3,1>(0,0,p);
            pe.set(3,0,1); //Last coordinate should be 1

            //Transform this point
            pe = *this * pe;

            //Divide by the last, extra element to get the true coordinates
            pe = pe/pe.get(3,0);

            //Grab and return the first three elements
            Matrix<3,1> a = pe.get<3,1>(0,0);
            TranslationMatrix pp = a;
            return pp;
        }

    };
}