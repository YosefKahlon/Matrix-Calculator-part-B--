//
// Created by 97252 on 4/1/2022.
//


#include "Matrix.hpp"
#include "vector"
#include "stdexcept"

using namespace std;
using namespace zich;



/**
 * constructor
 * from one vector to 2D vector .
 * @param matrix = values
 * @param n  = row  
 * @param m  = column
 */
Matrix::Matrix(const std::vector<double> &matrix, int n, int m) {

    if (n * m != matrix.size()) {
        throw invalid_argument("m and n positive integers,but m*n!=arr.size");
    }
    if (n < 0 || m < 0) {
        throw invalid_argument("m and n  must be positive integers !");
    }

    vector<vector<double>> new_matrix;
    this->row = n;
    this->col = m;

    for (size_t i = 0; i < this->row; i++) {
        vector<double> init;
        init.reserve((unsigned long) this->col);
        for (size_t j = 0; j < this->col; j++) {
            init.push_back(matrix.at((unsigned long) (this->col) * i + j));
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
    for (size_t i = 0; i < matrix1.row; ++i) {
        for (size_t j = 0; j < matrix1.col; ++j) {
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
    for (size_t i = 0; i < matrix1.row; ++i) {
        for (size_t j = 0; j < matrix1.col; ++j) {
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
    for (size_t i = 0; i < matrix1.row; ++i) {

        for (size_t j = 0; j < matrix2.col; ++j) {
            sum = 0;
            for (size_t k = 0; k < matrix1.col; ++k) {
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
    for (size_t i = 0; i < matrix1.row; ++i) {
        for (size_t j = 0; j < matrix1.col; ++j) {
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
    for (size_t i = 0; i < matrix1.row; i++) {
        for (size_t j = 0; j < matrix1.col; j++) {
//            if (matrix1.matrix.at(i).at(j) == 0) {
//                new_matrix.push_back(0);
//            } else {
            new_matrix.push_back(num * matrix1.matrix.at(i).at(j));
            //}
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


    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
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


    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
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

    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            if (this->matrix.at(i).at(j) == 0) {
                continue;
            }
            this->matrix.at(i).at(j) *= num;

        }
    }
    return *this;

}

/**
 *In this method we implement the operator multiply between two matrix
 * when the column of matrix 1 must be have equal to the row of matrix 2.
 *
 * @return pointer of the matrix .
 */
Matrix &Matrix::operator*=(const Matrix &other) {
    if (this->col != other.row) {
        throw invalid_argument(" Row  must be equal to  column!");
    }

    vector<double> multi;
    double sum = 0;
    for (size_t i = 0; i < this->row; ++i) {

        for (size_t j = 0; j < other.col; ++j) {
            sum = 0;
            for (size_t k = 0; k < this->col; ++k) {
                sum += this->matrix.at(i).at(k) * other.matrix.at(k).at(j);
            }
            multi.push_back(sum);
        }
    }
    this->col = other.col;
    vector<vector<double>> new_matrix;

    for (size_t i = 0; i < this->row; i++) {
        vector<double> init;
        init.reserve((unsigned long) this->col);
        for (size_t j = 0; j < this->col; j++) {
            init.push_back(multi.at((unsigned long) (this->col) * i + j));
        }
        new_matrix.push_back(init);
    }
    this->matrix = new_matrix;
    return *this;
}

/**------------------operators( ++,--, postfix and prefix)---------------------------*/




/**
 *-- prefix --
 *
 *In this method we implement the operator ++matrix
 * the matrix increasing each value by 1 .
 * @return pointer to matrix.
 */
Matrix &Matrix::operator++() {
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j)++;
        }
    }
    return *this;
}


/**
 *-- prefix --
 *
 *In this method we implement the operator --matrix
 * the matrix decreasing each value by 1 .
 * @return pointer to matrix.
 */
Matrix &Matrix::operator--() {
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            this->matrix.at(i).at(j)--;
        }
    }
    return *this;
}


/**
 *-- postfix --
 *
 *In this method we implement the operator ++matrix
 * the matrix increasing each value by 1 .
 * @return copy of the matrix after the increasing.
 */

Matrix Matrix::operator++(int dummy) {
    Matrix matrix = *this;
    ++(*this);
    return matrix;
}

/**
 *-- postfix --
 *
 *In this method we implement the operator ++matrix
 * the matrix decreasing each value by 1 .
 * @return copy of the matrix after the decreasing.
 */
Matrix Matrix::operator--(int dummy) {
    Matrix matrix = *this;
    --(*this);
    return matrix;
}


///**------------------operators(unary + , -)---------------------------*/

//
Matrix Matrix::operator-() {
    return -1 * *(this);
}


Matrix Matrix::operator+()  {
    return *this;
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
    for (size_t i = 0; i < matrix1.row; ++i) {
        for (size_t j = 0; j < matrix1.col; ++j) {
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
    bool flag = false;
    for (size_t i = 0; i < matrix1.matrix.size(); ++i) {
        os << "[";
        for (size_t j = 0; j < matrix1.matrix.at(i).size(); ++j) {
            os << matrix1.matrix.at(i).at(j) << "";
            if (j == matrix1.col - 1) {
                if (i == matrix1.row - 1) {
                    flag = true;
                } else {
                    os << "]\n";
                }
                break;
            }
            os << " ";

        }
        if (flag) {
            os << "]";
        }
    }

    return os;
}


/**
 * Static method
 * @param matrix
 * @return  The sum of the matrix values
 */
double Matrix::check_sum(const Matrix &matrix) {
    double counter = 0;
    for (size_t i = 0; i < matrix.row; ++i) {
        for (size_t j = 0; j < matrix.col; ++j) {
            counter += matrix.matrix.at(i).at(j);
        }
    }
    return counter;
}




/**
 *
 * In this method, we go over the string
 * and we get the matrix values
 * @param os stream of the input
 * @param matrix1
 */
istream &zich::operator>>(istream &os, Matrix &matrix1) {

    string input;
    getline(os, input);
    string save;

    int counter_row = 1;
    int counter_col = 1;
    bool flag = false;
    for (size_t i = 0; i < input.size() - 1; ++i) {


        if (input.at(i) == ',') {
            if (input.at(i + 1) != ' ') {
                throw invalid_argument("must be  space !");
            }

        } else if (input.at(i) == '[') {
            if (isdigit(input.at(i + 1)) == 0) {
                throw invalid_argument("must be number !");
            }


        } else if (input.at(i) == ' ') {
            if (input.at(i + 1) != '[') {
                if (isdigit(input.at(i + 1)) == 0) {
                    throw invalid_argument("bad input !");
                }
                if (!flag) {
                    counter_col++;
                }
            }


        } else if (isdigit(input.at(i)) != 0 || input.at(i) == '.') {
            save.push_back(input.at(i));


        } else if (input.at(i) == ']') {
            if (input.at(i + 1) != ',') {
                throw invalid_argument("bad input !");
            }
            flag = true;
            counter_row++;

        } else {
            throw invalid_argument("bad input !");
        }

    }



    matrix1.col = counter_col;
    matrix1.row = counter_row;
    vector<vector<double>> new_matrix;
    vector<double> vec;



    for (char i: save) {
        string str;
        str = i;
        vec.push_back(stod(str));
    }


    for (size_t i = 0; i < counter_row; ++i) {
        vector<double> temp;
        for (size_t j = 0; j < counter_col; ++j) {
            temp.push_back(vec.at((unsigned long) counter_col * i + j));
        }
        new_matrix.push_back(temp);
    }

    matrix1.matrix = new_matrix;
    return os;
}













