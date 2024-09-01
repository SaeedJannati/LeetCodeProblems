#include <iostream>

#include "Problems/LeetCode48RotateImage.h"
#include "Problems/LeetCode54SpiralMatrix.h"
#include "Problems/LeetCode73SetMatrixZeroes.h"

int main(int argc, char* argv[])
{
    const auto problem = new LeetCode54SpiralMatrix();
    problem->Run();
    delete problem;
}
