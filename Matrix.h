#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

//using namespace std;

class Matrix {

	struct ProxyMatrix {
		Matrix * matrix;
		int x;

		ProxyMatrix(Matrix * matrix, int x) {
			this->matrix = matrix;
			this->x = x;
		}

		int operator[](int y) {

			if (y < matrix->height) {
				return matrix->getPosition(x, y);
			}

			throw "Index Out of Bounds Exception";
		}
	};

private:
    int length;
    int height;
    std::vector<std::vector<int> > vectorMatrix;
    
public:
    Matrix();
    Matrix(int length, int height);
    Matrix(const Matrix &matrix);
    ~Matrix();

    friend void swap(Matrix& matrix1, Matrix& matrix2);

    //Returns element in matrix at position [x,y] (returns 0 if OOB)
    int getPosition(int x, int y) const;

    //Sets element in matrix at position [x,y] to value (ignored if OOB)
    void setPosition(int x, int y, int value);

    //Sets element in matrix at position [x,y] to 0 (ignored if OOB)
    void clearPosition(int x, int y);

    //Prints matrix in the form: x1y1 x2y1 ... x1yn \n for all yß
    void printMatrix() const;


	ProxyMatrix operator[](int x);
   
	Matrix& operator=(Matrix matrix);


	Matrix operator+(const Matrix &matrix) const;
    Matrix operator-(const Matrix &matrix) const;

	Matrix operator*(const Matrix &matrix) const;
    Matrix operator*(int scalar);


	
};

#endif