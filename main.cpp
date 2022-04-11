#include <iostream>
#include <sstream>
#include "sources//Matrix.hpp"

using namespace zich;
using namespace std;

int main() {
    vector<double> v1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};

    vector<double> v2 = {1, 0, 0, 1, 0, 1, 0, 1, 0};
    Matrix matrix1(v2, 3, 3);


        istringstream s{"[2 0 0], [1 0 1], [0 1 0]"};
      s >> matrix1 ;

    return 0;
}