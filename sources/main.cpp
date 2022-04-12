#include <iostream>
#include <sstream>
#include "Matrix.hpp"

using namespace zich;
using namespace std;

int main() {

    vector<double> v2 = {2, 0, 0, 0, 4, 0, 0, 0, 1};
    Matrix matrix1(v2, 3, 3);

    vector<double> v1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix2(v1, 3, 3);
   // bool b = matrix2 + <= matrix1 ;

  // matrix1*=matrix2;


    std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{unit_matrix,3,3};
    std::vector<double> arr1 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix mat_un{arr1,3,3};


        istringstream s{"[1.2 0 0], [0 1 0], [0 0 1]"};
        s >> matrix1 ;
        cout<< matrix1 <<endl;
//    ostringstream os1;
//    os1 << matrix1;
//    os1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]");

    return 0;
}