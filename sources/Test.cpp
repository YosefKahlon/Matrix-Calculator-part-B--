//
// Created by 97252 on 4/2/2022.
//
#include "Matrix.hpp"
#include "vector"
#include "doctest.h"

using namespace std;
using namespace zich;


TEST_CASE ("ROW = 1 OR COL = 1 ") {
    vector<double> v;
    vector<double> v2;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        v2.push_back(i * i);
        Matrix matrix(v, 1, i);
        Matrix matrix2(v2, 1, i);
        bool test;
        test = matrix <= matrix2;
                CHECK(test == true);
    }
    vector<double> v3;
    vector<double> v4;
    for (int i = 1; i <= 10; i++) {
        v3.push_back(i);
        v4.push_back(i * i);
        Matrix matrix(v3, i, 1);
        Matrix matrix2(v4, i, 1);
        bool test;
        test = matrix2 >= matrix;
                CHECK(test == true);

    }
    vector<double> v5 = {1};
    Matrix matrix5(v5, 1, 1);
    vector<double> v6;
    for (int i = 1; i < 30; ++i) {
        v6.push_back(i);
        Matrix matrix(v6, 1, i);
        if (i == 1) {
            continue;
        } else {
                    CHECK_THROWS(matrix + matrix5);
                    CHECK_THROWS(matrix - matrix5);
                    CHECK_THROWS(matrix += matrix5);
                    CHECK_THROWS(matrix -= matrix5);

        }
    }

    vector<double> v10;
    vector<double> v11;
    vector<double> v12;
    vector<double> v13;

    for (int i = 1; i < 50; ++i) {
        v10.push_back(i);
        v12.push_back(i+1);
        Matrix matrix10(v10, 1, i);
        Matrix matrix12(v12, 1, i);
        ++matrix10;
       bool test = (matrix10 == matrix12);
        CHECK(test == true);

    }
    for (int i = 0; i < 50; ++i) {
        v11.push_back(i);
        v13.push_back(i-1);
        Matrix matrix11(v11, 1, i);
        Matrix matrix13(v13, 1, i);
        --matrix11;
        bool test = (matrix11 == matrix13);
                CHECK(test == true);

    }



}

TEST_CASE ("Arithmetic operator ") {
    bool test;
    vector<double> v1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix(v1, 3, 3);

    // self + self
    vector<double> v2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix matrix2(v2, 3, 3);
    test = (matrix + matrix) == matrix2;
            CHECK(test == true);



    //self - self
    vector<double> v0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix matrix0(v0, 3, 3);
    test = (matrix - matrix) == matrix0;
            CHECK(test == true);







    vector<double> a;
    vector<double> a2;
    for (int i = 1; i < 10; ++i) {
        a.push_back(i);
        a2.push_back(-1*i);
        Matrix matrix5(a,1,i);
        Matrix matrix6(a2,1,i);
        test = (-1 * matrix5) == matrix6;
                CHECK(test == true);
    }

}

TEST_CASE ("COMPERE OPERATOR ") {

    vector<double> v1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix(v1, 3, 3);

    Matrix matrix7(v1, 3, 3);
    // <
     ++matrix;
            CHECK_EQ(matrix7 <  matrix, true);



    vector<double> v2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix matrix2(v2, 3, 3);
    // <=
            CHECK_EQ(matrix2 <= (matrix + matrix + matrix), true);


            CHECK_EQ(matrix <= (matrix * matrix), true);

    // >
    vector<double> v0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix matrix0(v0, 3, 3);
            CHECK_EQ(matrix2 + matrix> (matrix0), true);

    -matrix;
            CHECK_EQ(matrix0 > (matrix), true);



}


TEST_CASE ("Power") {
    vector<double> v2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix matrix2(v2, 3, 3);
    // A * A  + A
            CHECK_EQ((matrix2 * matrix2) + matrix2 >= matrix2, true);

    vector<double> v4 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix matrix4(v4, 3, 3);


    //   (A - A) + ( C * A ) THROW
    Matrix matrix3(v2, 15, 15);
    CHECK_THROWS((matrix2 + matrix2) + (matrix2 * matrix3));
    CHECK_THROWS((matrix2 + matrix2) - (matrix2 * matrix3));


}





