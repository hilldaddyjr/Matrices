#include "Matrix.h"

Matrix::Matrix() {
        length = 3;
        height = 3;
        vectorMatrix.resize(height, std::vector<int>(length, 0));
}

Matrix::Matrix(int length, int height) {
        this->length = length;
        this->height = height;
        vectorMatrix.resize(height, std::vector<int>(length, 0));
}

Matrix::~Matrix() {
}

int Matrix::getPosition(int x, int y) const {
    if (x >= length || y >= height) {
        return 0;
    }

    return vectorMatrix[x][y];
}

void Matrix::setPosition(int x, int y, int value) {
    if (x < length && y < height) {
        vectorMatrix[x][y] = value;
    }
}

void Matrix::clearPosition(int x, int y) {
    if (x < length && y < height) {
        vectorMatrix[x][y] = 0;
    }
}

void Matrix::printMatrix() const {

        //Y axis spacing buffer
        std::cout << "   ";
        
        //Y axis label
        for(int y = 0; y < height; y++) {
            std::cout << y << " ";
        }

        std::cout << std::endl;

        //Y axis
        for(int y = 0; y < height; y++) {
            std::cout << "--";
        }

        std::cout << std::endl;

        for (int x = 0; x < length; x++) {

                //X axis label and spacing buffer
                std::cout << x << " | ";
                for (int y = 0; y < height; y++) {
                        std::cout << vectorMatrix[x][y] << " ";
                }
                std::cout << std::endl;
        }
}

Matrix Matrix::operator+(const Matrix &matrix) {
	if (this->length == matrix.length && this->height == matrix.height) {
		
		Matrix newMatrix(this->length, this->height);

		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < length; j++) {
				newMatrix.setPosition(i, j, this->getPosition(i, j) + matrix.getPosition(i, j));
			}
		}

		return newMatrix;
		}
	throw "Matrices Have Incompatible Dimensions";
}

Matrix Matrix::operator*(const Matrix &matrix) {
	if (this->length == matrix.height) {

		Matrix newMatrix(this->height, matrix.length);

		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < this->length; j++) {
				//Finish Implementation
			}
		}
			

		return newMatrix;
		}

	throw "Matrices Have Incompatible Dimensions";
}