//
// Created by 97252 on 4/1/2022.
//


#include "Matrix.hpp"
#include "vector"
#include "stdexcept"

using namespace std;
using namespace zich;

// todo throw  exp , comper , test , unary , mulltiply , minus , plus
double check_sum(vector<double> vector1) {
    double counter = 0;
    for (int i = 0; i < vector1.size(); i++) {

        counter += vector1.at((unsigned long) i);
    }
    return counter;
}


//c - tor
Matrix::Matrix(const std::vector<double> &matrix, int n, int m) {
    this->matrix = matrix;
    this->row = n;
    this->col = m;
}


/**
 *  regular matrix 1 + matrix 2
 */
Matrix zich::operator+(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    vector<double> new_matrix;
    int length = matrix1.col * matrix1.row;
    for (int i = 0; i < length; ++i) {
        new_matrix.push_back(matrix1.matrix[(unsigned long) i] + matrix2.matrix[(unsigned long) i]);
    }
    return Matrix(new_matrix, matrix1.row, matrix1.col);
}
//
///**
// *
// */
//Matrix Matrix::operator+=(const Matrix &other) {
//    if (this->row != other.row || this->col != other.col) {
//        throw invalid_argument("Matrix must have the same size !!");
//    }
//    for (int i = 0; i < this->row; i++) {
//        for (int j = 0; j < this->col; j++) {
//            int index = (this->col * i + j);
//            this->matrix.at((unsigned long) index) += other.matrix.at((unsigned long) index);
//        }
//    }
//    return Matrix(this->matrix, this->row, this->col);
//}
//
///**
// * In this method every index in the matrix increasing by  1 .
// */
//Matrix Matrix::operator++() {
//    for (int i = 0; i < this->row; i++) {
//        for (int j = 0; j < this->col; j++) {
//            int index = (this->col * i + j);
//            this->matrix.at((unsigned long) index) += 1;
//        }
//    }
//    return Matrix(this->matrix, this->row, this->col);
//
//}
//
///**
// *In this method we implication the operator minus between two matrix .
// */
//Matrix Matrix::operator-(const Matrix &other) {
//    if (this->row != other.row || this->col != other.col) {
//        throw invalid_argument("Matrix must have the same size !!");
//    }
//    for (int i = 0; i < this->row; i++) {
//        for (int j = 0; j < this->col; j++) {
//            int index = (this->col * i + j);
//            this->matrix.at((unsigned long) index) =
//                    this->matrix.at((unsigned long) index) - other.matrix.at((unsigned long) index);
//        }
//    }
//    return Matrix(this->matrix, this->row, this->col);
//}
//
///**
// *In this method every index in the  matrix decreasing by  1 .
// */
//Matrix Matrix::operator--() {
//    for (int i = 0; i < this->row; i++) {
//        for (int j = 0; j < this->col; j++) {
//            int index = (this->col * i + j);
//            this->matrix.at((unsigned long) index) -= 1;
//        }
//    }
//    return Matrix(this->matrix, this->row, this->col);
//}
//
///**
// * In this method we implication the operator -=
// * for matrix .
// * every index in our matrix decreasing the same index from matrix other .
// */
//Matrix Matrix::operator-=(const Matrix &other) {
//    if (this->row != other.row || this->col != other.col) {
//        throw invalid_argument("Matrix must have the same size !!");
//    }
//    for (int i = 0; i < this->row; i++) {
//        for (int j = 0; j < this->col; j++) {
//            int index = (this->col * i + j);
//            this->matrix.at((unsigned long) index) -=other.matrix.at((unsigned long) index);
//
//        }
//    }
//    return Matrix(this->matrix, this->row, this->col);
//
//}


/**------------------operators(<,>,==,!= ,>= , <= )---------------------------*/


/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is smaller then matrix 2
 */
bool zich::operator<(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (check_sum(matrix1.matrix)) < (check_sum(matrix2.matrix));
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is bigger then matrix 2
 */
bool zich::operator>(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (check_sum(matrix1.matrix)) > (check_sum(matrix2.matrix));
}


/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is equal to matrix 2
 */
bool zich::operator==(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            int index = (matrix1.col * i + j);
            if (matrix1.matrix[(unsigned long) index] != matrix2.matrix[(unsigned long) index]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is not equal to matrix 2
 */
bool zich::operator!=(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return !(matrix1 == matrix2);
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is equal or bigger then to matrix 2
 */
bool zich::operator>=(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (check_sum(matrix1.matrix)) >= (check_sum(matrix2.matrix));
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is equal or smaller to matrix 2
 */
bool zich::operator<=(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (check_sum(matrix1.matrix)) <= (check_sum(matrix2.matrix));
}





//Matrix zich::operator*(double num, Matrix &other) {
//    for (int i = 0; i < other.row; i++) {
//        for (int j = 0; j < other.col; ++j) {
//            other.matrix.at((unsigned long) (other.col * i + j)) =
//                    num * other.matrix.at((unsigned long) (other.col * i + j));
//        }
//
//    }
//    return Matrix(other.matrix, other.row, other.col);
//}
//
//
//Matrix zich::operator-(Matrix &matrix1) {
//    if (matrix1.row != matrix1.col) {
//        throw invalid_argument("row or col no equal to real");
//    }
//
//    return -1 * matrix1;
//}


// -------------------- output --------------------
ostream &zich::operator<<(ostream &os, const Matrix &matrix1) {
    for (int i = 0; i < matrix1.row; ++i) {
        os << "[";
        for (int j = 0; j < matrix1.col; ++j) {
            int index = (matrix1.col * i + j);
            if (j == matrix1.col - 1) {
                os << matrix1.matrix.at((unsigned long) index) << "";
            } else {
                os << matrix1.matrix.at((unsigned long) index) << " ";
            }
        }
        os << "]\n";
    }


    return os;
}
vector<string> delete_sym(string input,char sym){
    int index = 0;
    vector<string> row_;

    while (index < input.size()) {
        string s;
        for (int j = index; input.at(j) != sym && j < input.size() - 1; j++) {
            s += input.at(j);
            index = j;
        }
        index ++ ;

        if (index == input.size() - 1) {

            s += input.at(index);
        }


        row_.push_back(s);
    }

    return row_;
}

istream &zich::operator>>(istream &os, Matrix &matrix1) {

    string input;
    getline(os, input);
    vector<string> row_ ;
     row_ = delete_sym(input,',');
    int row = row_.size();
    int col = 0;
    for (int i = 0; i < row_.size(); ++i) {
        for (int j = 0; j < row_.at(i).size(); ++j) {
            if(row_.at(i).at(j) != '[' ||row_.at(i).at(j) != ']' || row_.at(i).at(j) != ' ')
            col++;
        }
    }

    //row_ = delete_sym(input, ']');
    int index = 0;


//    while (index < input.size()) {
//        string s;
//        for (int j = index; input.at(j) != ',' && j < input.size() - 1; j++) {
//            s += input.at(j);
//            index = j;
//        }
//        index ++ ;
//
//        if (index == input.size() - 1) {
//
//            s += input.at(index);
//        }
//
//
//        row_.push_back(s);
//    }


    for (int i = 0; i < row_.size(); ++i) {
        for (int j = 0; j < row_.at(i).size(); ++j) {
            cout << row_.at(i).at(j);
        }
        cout << '\n';
    }

//
//    for (int i = 0; i < input.size(); ++i) {
//
//        if (bad_input(input.at(i))){
//            throw invalid_argument("Bad input !!");
//        }
//        if (input.at(i) == '[' || input.at(i) == ']' || input.at(i) == ','|| input.at(i) == ' '){
//            continue;
//    }
//        else{
//            string ss;
//            ss += input.at(i);
//            double d = stod(ss);
//            matrix1.matrix.at(index++) = d;
//        }
//
//
//    }





    return os;
}









