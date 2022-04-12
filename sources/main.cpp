//#include <iostream>
//#include <sstream>
//#include "Matrix.hpp"
//
//using namespace zich;
//using namespace std;
//
//int main() {
//    bool b;
//    vector<double> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
//    Matrix matrix1(v2, 3, 3);
//
//    vector<double> v1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//    Matrix matrix2(v1, 3, 3);
//
//    cout << matrix1 + matrix2 << '\n' << endl;
//    cout << matrix1 - matrix2 << '\n' << endl;
//    cout << matrix1 * matrix2 << '\n' << endl;
//
//
//    istringstream s{"[1 2 3], [4 5 6], [7 8 9]"};
//        s >> matrix1 ;
//    cout << matrix1 << '\n' << endl;
//
//    --matrix1;
//    cout <<matrix1 <<'\n' <<endl;
//
//    matrix1++;
//    cout <<matrix1 <<'\n' <<endl;
//
//    b = matrix1 > matrix2;
//    cout << b << endl;
//    b = matrix1 == matrix2;
//    cout << b << endl;
//    b = matrix1 <= matrix2;
//    cout << b << endl;
//
//
//
//    return 0;
//}