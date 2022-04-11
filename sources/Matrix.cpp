//
// Created by 97252 on 4/1/2022.
//


#include "Matrix.hpp"
#include "vector"
#include "stdexcept"

using namespace std;
using namespace zich;


//c - tor
Matrix::Matrix(const std::vector<double> &matrix, int n, int m) {
    vector<vector<double>> new_matrix;
    this->row = n;
    this->col = m;

    for (int i = 0; i < this->row; i++) {
        vector<double> init;
        init.reserve(this->col);
        for (int j = 0; j < this->col; j++) {
            init.push_back(matrix.at(this->col * i + j));
        }
        new_matrix.push_back(init);
    }
    this->matrix = new_matrix;

}

/**------------------operators( +,-,*,const* ,*const)---------------------------*/


/**
 *  regular matrix 1 + matrix 2
 *
 *  @return result of the operator .
 */
Matrix zich::operator+(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    vector<double> new_matrix;
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            new_matrix.push_back(matrix1.matrix.at(i).at(j) + matrix2.matrix.at(i).at(j));
        }
    }
    return Matrix(new_matrix, matrix1.row, matrix1.col);
}

/**
 *In this method we implement the operator minus between two matrix .
 *
 * @return result of the operator .
 */
Matrix zich::operator-(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    vector<double> new_matrix;
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            new_matrix.push_back(matrix1.matrix.at(i).at(j) - matrix2.matrix.at(i).at(j));
        }
    }
    return Matrix(new_matrix, matrix1.row, matrix1.col);
}

/**
 *In this method we implement the operator multiply between two matrix
 * when the column of matrix 1 must be have equal to the row of matrix 2.
 *
 * @return result of the operator .
 */
Matrix zich::operator*(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.col != matrix2.row) {
        throw invalid_argument("Column of matrix1 must be equal to row or matrix2 !");
    }

    vector<double> new_matrix;
    double sum = 0;
    for (int i = 0; i < matrix1.row; ++i) {

        for (int j = 0; j < matrix2.row; ++j) {
            sum = 0;
            for (int k = 0; k < matrix1.col; ++k) {
                sum += matrix1.matrix.at(i).at(k) * matrix2.matrix.at(k).at(j);
            }
            new_matrix.push_back(sum);
        }

    }

    return Matrix(new_matrix, matrix1.row, matrix2.col);
}

/**
 *In this method, we implement the operator of multiplying a matrix in scalar
 * when scalar from the left side .
 * @return result of the operator .
 */
Matrix zich::operator*(const Matrix &matrix1, const double &num) {
    vector<double> new_matrix;
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            if (matrix1.matrix.at(i).at(j) == 0) {
                new_matrix.push_back(0);
            } else {
                new_matrix.push_back(matrix1.matrix.at(i).at(j) * num);
            }
        }
    }
    return Matrix(new_matrix, matrix1.row, matrix1.col);
}

/**
 *In this method, we implement the operator of multiplying a matrix in scalar
 * when scalar from the right side .
 * @return result of the operator .
 */
Matrix zich::operator*(const double &num, const Matrix &matrix1) {
    vector<double> new_matrix;
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            if (matrix1.matrix.at(i).at(j) == 0) {
                new_matrix.push_back(0);
            } else {


                new_matrix.push_back(num * matrix1.matrix.at(i).at(j));
            }
        }
    }
    return Matrix(new_matrix, matrix1.row, matrix1.col);
}



/**------------------operators( +=,-=, *= ,*=const )---------------------------*/

/**
 *In this method, we implement the operator of  +=
 * Matrix increases each value of the matrix by the value of the other matrix index .
 * @return pointer to the matrix .
 */
Matrix &Matrix::operator+=(const Matrix &other) {
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }


    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j) += other.matrix.at(i).at(j);
        }
    }

    return *this;

}

/**
 *In this method, we implement the operator of  -=
 * Matrix decreases each value of the matrix by the value of the other matrix index .
 * @return pointer to the matrix .
 */
Matrix &Matrix::operator-=(const Matrix &other) {
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }


    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j) -= other.matrix.at(i).at(j);
        }
    }

    return *this;
}

/**
 *In this method, we implement the operator of multiplying a matrix in scalar
 *
 * @return pointer to the matrix .
 */
Matrix &Matrix::operator*=(const double &num) {

    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            if (this->matrix.at(i).at(j) == 0) {
                continue;
            } else {
                this->matrix.at(i).at(j) *= num;
            }
        }
    }
    return *this;

}

Matrix &Matrix::operator*=(const Matrix &other) {
    if (this->col != other.row) {
        throw invalid_argument(" Row  must be equal to  column!");
    }

    vector<double> multi;
    double sum = 0;
    for (int i = 0; i < this->row; ++i) {

        for (int j = 0; j < other.row; ++j) {
            sum = 0;
            for (int k = 0; k < this->col; ++k) {
                sum += this->matrix.at(i).at(k) * other.matrix.at(k).at(j);
            }
            multi.push_back(sum);
        }
    }
    this->col = other.col;
    vector<vector<double>> new_matrix;

    for (int i = 0; i < this->row; i++) {
        vector<double> init;
        init.reserve(this->col);
        for (int j = 0; j < this->col; j++) {
            init.push_back(multi.at(this->col * i + j));
        }
        new_matrix.push_back(init);
    }
    this->matrix = new_matrix;
    return *this;
}

/**------------------operators( ++,--, postfix and prefix)---------------------------*/


//prefix
Matrix &Matrix::operator++() {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j)++;
        }
    }
    return *this;
}




//prefix
Matrix &Matrix::operator--() {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j)--;
        }
    }
    return *this;
}

//postfix
Matrix Matrix::operator++(int dummy) {

    vector<double> new_matrix;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            new_matrix.push_back(this->matrix.at(i).at(j) +1);
        }
    }
    return Matrix(new_matrix , this->row , this->col);
}
//postfix
Matrix Matrix::operator--(int dummy) {
    vector<double> new_matrix;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            new_matrix.push_back(this->matrix.at(i).at(j) -1);
        }
    }
    return Matrix(new_matrix , this->row , this->col);
}


///**------------------operators(<,>,==,!= ,>= , <= )---------------------------*/


/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is smaller then matrix 2
 *
 * check_sum: Calculate the sum of all the values in the matrix
 */
bool zich::operator<(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (Matrix::check_sum(matrix1)) < (Matrix::check_sum(matrix2));
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is bigger then matrix 2
 *
 * check_sum: Calculate the sum of all the values in the matrix
 */
bool zich::operator>(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (Matrix::check_sum(matrix1)) > (Matrix::check_sum(matrix2));
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix1 is equal to matrix2
 */
bool zich::operator==(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    for (int i = 0; i < matrix1.row; ++i) {
        for (int j = 0; j < matrix1.col; ++j) {
            if (matrix1.matrix.at(i).at(j) != matrix2.matrix.at(i).at(j)) {
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
 *
 * check_sum: Calculate the sum of all the values in the matrix
 */
bool zich::operator>=(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (Matrix::check_sum(matrix1)) >= (Matrix::check_sum(matrix2));
}

/**
 * @param matrix1
 * @param matrix2
 * @return true if matrix 1 is equal or smaller to matrix 2
 *
 * check_sum: Calculate the sum of all the values in the matrix
 */
bool zich::operator<=(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        throw invalid_argument("Matrix must have the same size !!");
    }
    return (Matrix::check_sum(matrix1)) <= (Matrix::check_sum(matrix2));
}




/**
 *
 * @param os - output stream
 * @param matrix1
 * @return view of the matrix in the console
 */
ostream &zich::operator<<(ostream &os, const Matrix &matrix1) {
    for (int i = 0; i < matrix1.matrix.size(); ++i) {
        os << "[";
        for (int j = 0; j < matrix1.matrix.at(i).size(); ++j) {
            os << matrix1.matrix.at(i).at(j) << "";
            if (j == matrix1.col - 1) {
                break;
            }
            os << " ";
        }
        os << "]\n";
    }

    return os;
}

double Matrix::check_sum(const Matrix &matrix) {
    double counter = 0;
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.col; ++j) {
            counter += matrix.matrix.at(i).at(j);
        }
    }
    return counter;
}


















istream &zich::operator>>(istream &os, Matrix &matrix1) {

    string input;
    getline(os, input);




    return os;

}





//
//vector<string> delete_sym(string input, char sym) {
//    int index = 0;
//    vector<string> row_;
//
//    while (index < input.size()) {
//        string s;
//        for (int j = index; input.at(j) != sym && j < input.size() - 1; j++) {
//            s += input.at(j);
//            index = j;
//        }
//        index++;
//
//        if (index == input.size() - 1) {
//
//            s += input.at(index);
//        }
//
//
//        row_.push_back(s);
//    }
//
//    return row_;
//}

//istream &zich::operator>>(istream &os, Matrix &matrix1) {
//
//    string input;
//    getline(os, input);
//    vector<string> row_;
//    row_ = delete_sym(input, ',');
//    int row = row_.size();
//    int col = 0;
//    for (int i = 0; i < row_.size(); ++i) {
//        for (int j = 0; j < row_.at(i).size(); ++j) {
//            if (row_.at(i).at(j) != '[' || row_.at(i).at(j) != ']' || row_.at(i).at(j) != ' ')
//                col++;
//        }
//    }
//
//    //row_ = delete_sym(input, ']');
//    int index = 0;
//
//
////    while (index < input.size()) {
////        string s;
////        for (int j = index; input.at(j) != ',' && j < input.size() - 1; j++) {
////            s += input.at(j);
////            index = j;
////        }
////        index ++ ;
////
////        if (index == input.size() - 1) {
////
////            s += input.at(index);
////        }
////
////
////        row_.push_back(s);
////    }
//
//
//    for (int i = 0; i < row_.size(); ++i) {
//        for (int j = 0; j < row_.at(i).size(); ++j) {
//            cout << row_.at(i).at(j);
//        }
//        cout << '\n';
//    }
//
////
////    for (int i = 0; i < input.size(); ++i) {
////
////        if (bad_input(input.at(i))){
////            throw invalid_argument("Bad input !!");
////        }
////        if (input.at(i) == '[' || input.at(i) == ']' || input.at(i) == ','|| input.at(i) == ' '){
////            continue;
////    }
////        else{
////            string ss;
////            ss += input.at(i);
////            double d = stod(ss);
////            matrix1.matrix.at(index++) = d;
////        }
////
////
////    }
//
//
//
//
//
//    return os;
//}









