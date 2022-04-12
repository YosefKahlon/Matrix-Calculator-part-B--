//
// Created by 97252 on 4/1/2022.
//

#ifndef MATRIX_CALCULATOR_A_MATRIX_HPP
#define MATRIX_CALCULATOR_A_MATRIX_HPP

#include "vector"
#include "iostream"

using namespace std;
namespace zich {

    class Matrix {

    private:


        vector<vector<double>> matrix;
        int row;
        int col;
    public:
        //constructor
        Matrix(const std::vector<double> &matrix, int n, int m);


        //arithmetic assignment operator
        //return the matrix reference
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix &operator*=(const double &num);
        Matrix &operator*=(const Matrix &other);


        //create new matrix from arithmetic operator between 2 matrix
        friend Matrix operator+(const Matrix &matrix1,const Matrix &matrix2);
        friend Matrix operator-(const Matrix &matrix1,const Matrix &matrix2);
        friend Matrix operator*(const Matrix &matrix1,const Matrix &matrix2);
        friend Matrix operator*(const Matrix &matrix1,const double &num);
        friend Matrix operator*(const double &num,const Matrix &matrix1);


        //postfix --> i++
        Matrix operator++(int dummy);
        Matrix operator--(int dummy);

        //prefix --> ++i
        Matrix& operator++();
        Matrix& operator--();

        //Unary
        Matrix operator-() const;
        Matrix operator+() const;

        //boolean operators
        friend bool operator>(const Matrix &matrix1,const Matrix &matrix2);
        friend bool operator<(const Matrix &matrix1,const Matrix &matrix2);
        friend bool operator==(const Matrix &matrix1,const Matrix &matrix2);
        friend bool operator!=(const Matrix &matrix1,const Matrix &matrix2);
        friend bool operator>=(const Matrix &matrix1,const Matrix &matrix2);
        friend bool operator<=(const Matrix &matrix1,const Matrix &matrix2);



        //output
        friend ostream &operator<<(ostream &os, const Matrix &matrix1);

        //input
        friend istream &operator>>(istream &os,  Matrix &matrix1);


        static double check_sum(const Matrix &matrix);
    };


}
#endif //MATRIX_CALCULATOR_A_MATRIX_HPP
