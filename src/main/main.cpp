﻿/* Hello GLFW
*  Based on https://www.glfw.org/docs/3.3/quick.html
*/

#include "main.hpp"
#include "me518/matrix.hpp"
#include "me518/matrix_transformation.hpp"
#include <thread>


int main()
{
    using namespace ME518;
    using namespace std;


    
   Matrix<3,3> I = Identity<3>();
   auto I2 = I*I;
   I2 = I2 + 1;
   matrix_unit t = I2.get(1, 1);
   auto I3 = I2.row(2);

   cout << sizeof(I.data) << endl;

   RotationMatrix R;
   RotationMatrix R2 = R.inverse();
   R = R2.transpose();
   R = R.rotate(RotationMatrix::Direction::X, M_PI/2);

   TransformationMatrix T1;
   T1.rotate(R);
   TransformationMatrix T2 = T1 * T1;

   TranslationMatrix p(1,1,1);
   p = T1.transform(p);
   T2 = T1.inverse();
   p = T2.transform(p);


    return 0;
}
