#pragma once

#include <math.h>
#include <memory.h>

namespace ME518{

    typedef float matrix_unit;
    template<size_t n, size_t m>
    class Matrix{
        public:


        matrix_unit data[n][m];


        Matrix<n,m>(){
            memset(data, 0, sizeof(data));
        }


        matrix_unit* 
        operator[](size_t i)
        {return data[i];}


        Matrix<n,m> 
        operator+(const Matrix<n,m> &other) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]+other.data[i][j];
        }


        template<size_t q> 
        Matrix<n, m+q>
        augmentAfter(const Matrix<n,q> &other) const
        {
            Matrix<n, m+q> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j];

            
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j+m]=other.data[i][j];

            return M;
        }


        template<size_t q> 
        Matrix<n, m+q>
        augmentBefore(const Matrix<n,q> &other) const
        {
            Matrix<n, m+q> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j+q]=data[i][j];

            
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=other[i][j];

            return M;
        }


        template<size_t p> 
        Matrix<n+p, m>
        augmentAbove(const Matrix<p,m> &other) const
        {
            Matrix<n+p, m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i+p][j]=data[i][j];

            
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=other.data[i][j];

            return M;
        }


        template<size_t p> 
        Matrix<n+p, m>
        augmentBelow(const Matrix<p,m> &other) const
        {
            Matrix<n+p, m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j];

            
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i+n][j]=other.data[i][j];

            return M;
        }


        template<size_t q> 
        Matrix<n, q>
        operator *(const Matrix<m, q> &other) const
        {
            Matrix<n, q> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            for(int k = 0; k < q; k++) 
            M[i][k]=data[i][j]*other.data[j][k];

            return M;
        }

        Matrix<m, n>
        transpose() const
        {
            Matrix<m, n> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[j][i]=data[i][j];
        }



    };

    template<size_t n>
    Matrix<n,n>
    Identity(){
        Matrix<n,n> I;
        for(int i = 0; i < n; i++)
        I[n][n]=1;
        return I;
    }

}