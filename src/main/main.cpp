﻿/* Hello GLFW
*  Based on https://www.glfw.org/docs/3.3/quick.html
*/

#include "main.hpp"
#include "me518/matrix.hpp"
#include <thread>


int main()
{
    using namespace ME518;
    Matrix<3,3> I = Identity<3>();
    auto I2 = I*I;
}
