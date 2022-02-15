#include <gtest/gtest.h>
#include "me518/matrix.hpp"
#include "me518/matrix_transformation.hpp"

#define PRINT_MAT( M ) { \
std::cout << std::endl \
          << "\x1B[96m" /*ANSI escape color code for bright cyan*/ \
          << #M \
          << " (" \
          << __FILE__ \
          << ":" \
          << __LINE__ \
          << ")" \
          << "\x1B[34m" /*ANSI escape color code for cyan*/ \
          << M \
          << std::endl \
          << "\x1B[30m"; /*ANSI escape color code for black*/ \
}\

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(ME518, TransformOps){
  
    using namespace ME518;
    using namespace std;


    //Creating a matrix
    Matrix<3,3> I = Identity<3>();
    PRINT_MAT(I);
 
    //Matrix multiplication
    auto I2 = I*I;
    PRINT_MAT(I2);
 
    //Matrix-scalar addition
    I2 = I2 + 1;
 
    //Extracting scalars and submatrices
    matrix_unit t = I2.get(1, 1);
    auto I3 = I2.row(2);
 
    //Application: rotation matrices
    RotationMatrix R;
    PRINT_MAT(R);
    //Inverting a matrix
    RotationMatrix R2 = R.inverse();
    PRINT_MAT(R2);
    //Rotating a matrix
    R = R.rotate(RotationMatrix::Direction::X, M_PI);
    PRINT_MAT(R);
 
    //Application: transformation matrix
    TransformationMatrix T1;
    PRINT_MAT(T1);
    //Rotating a transformation
    T1 = T1.rotate(R);
    PRINT_MAT(T1);
 
    //Application: Transforming a point
    TranslationMatrix p(1,1,1);
    PRINT_MAT(p);
    p = T1.transform(p);
    PRINT_MAT(p);
    //Returning a point to its original state
    T1 = T1.inverse();
    p = T1.transform(p);
    PRINT_MAT(p);
}
