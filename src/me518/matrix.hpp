#pragma once

#include <cstring>
#include "matrix_exceptions.hpp"

namespace ME518{

    typedef float matrix_unit;
    template<size_t n, size_t m>
    class Matrix{
        public:


        matrix_unit data[n][m];


        Matrix<n,m>(){
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            data[i][j]=0;

            //memset(data[0], 0, sizeof(data));
        }

        void
        operator=(const Matrix<n,m> &M){
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            data[i][j]=M.data[i][j];
        }


        matrix_unit* 
        operator[](size_t i)
        {return data[i];}


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

        



        Matrix<n,m> 
        operator +(const Matrix<n,m> &other) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]+other.data[i][j];
            return M;
        }

        

        Matrix<n,m> 
        operator +(matrix_unit a) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]+a;
            return M;
        }

        Matrix<n,m> 
        operator -(matrix_unit a) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]-a;
            return M;
        }

        Matrix<n,m> 
        operator *(matrix_unit a) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]*a;
            return M;
        }

        Matrix<n,m> 
        operator /(matrix_unit a) const
        {
            Matrix<n,m> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[i][j]=data[i][j]/a;
            return M;
        }



        Matrix<m, n>
        transpose() const
        {
            Matrix<m, n> M;
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            M[j][i]=data[i][j];
            return M;
        }


        matrix_unit
        get(size_t i, size_t j) const
        {
            if(i>=n) throw MatrixIndexOutOfBounds();
            if(j>=m) throw MatrixIndexOutOfBounds();
            return data[i][j];
        }

        
        template<size_t p, size_t q>
        Matrix<p, q>
        get(size_t c, size_t d) const
        {
            if(c+p>n) throw MatrixIndexOutOfBounds();
            if(d+q>m) throw MatrixIndexOutOfBounds();
            Matrix<p, q> M;
            for(int i = 0; i < p; i++) 
            for(int j = 0; j < q; j++) 
            M[i][j]=data[i+c][j+d];     
            return M;       
        }

        void
        set(size_t i, size_t j, matrix_unit newVal)
        {
            if(i>=n) throw MatrixIndexOutOfBounds();
            if(j>=m) throw MatrixIndexOutOfBounds();
            data[i][j] = newVal;
        }

        
        template<size_t p, size_t q>
        void
        set(size_t c, size_t d, Matrix<p,q> newVal)
        {
            if(c+p>n) throw MatrixIndexOutOfBounds();
            if(d+q>m) throw MatrixIndexOutOfBounds();
            for(int i = 0; i < p; i++) 
            for(int j = 0; j < q; j++) 
            data[i+c][j+d] = newVal[i][j];    
        }



        Matrix<1, m>
        row(size_t i) const
        {
            return get<1, m>(i, 0);
        }

        
        Matrix<1, m>
        column(size_t j) const
        {
            return get<n,1>(0, j);
        }


        void
        copyTo(Matrix<n,m> &other) const
        {
            for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
            other[i][j]=data[i][j];
        }



    };

    template<size_t n>
    Matrix<n,n>
    Identity(){
        Matrix<n,n> I;
        for(int i = 0; i < n; i++)
        I[i][i]=1;
        return I;
    }

    template<size_t n, size_t m>
    Matrix<n,m>
    Zeros(){
        Matrix<n,m> M;
        return M;
    }

}