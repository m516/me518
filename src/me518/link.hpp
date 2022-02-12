#pragma once
#include "matrix_transformation.hpp"
namespace ME518{
    class Link{
        public:
        matrix_unit distance;
        matrix_unit twist;
        matrix_unit offset;
        matrix_unit angle;

        operator TransformationMatrix() const{
            TransformationMatrix t;
            t[0][0]=cos(angle);                      t[0][1]=-sin(angle);                    t[0][2]=0;                t[0][3]=distance;
            t[1][0]=sin(angle)*cos(twist);           t[1][1]=cos(angle)*cos(twist);          t[1][2]=-sin(twist);      t[1][3]=-offset*sin(twist);
            t[2][0]=sin(angle)*sin(twist);           t[2][1]=cos(angle)*sin(twist);          t[2][2]=cos(twist);       t[2][3]=offset*cos(twist);
            t[3][0]=0;                               t[3][1]=0;                              t[3][2]=0;                t[3][3]=1;
            return t;
        }


        private:
        
    };
}