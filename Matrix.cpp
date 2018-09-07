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

Matrix::Matrix(const Matrix &matrix) {
    
    for(int i = 0; i < this->length; i++) {
        for(int j = 0; j < this->height; j++) {
            setPosition(i, j, this->getPosition(i, j));
        }
    }
}

Matrix::~Matrix() {
}

void swap(Matrix& matrix1, Matrix& matrix2) {
    
    std::swap(matrix1.length, matrix2.length);
    std::swap(matrix1.height, matrix2.height);
    std::swap(matrix1.vectorMatrix, matrix2.vectorMatrix);
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
        for (int y = 0; y < height; y++) {
            std::cout << y << " ";
        }

        std::cout << std::endl;

        //Y axis
        for (int y = 0; y < height; y++) {
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

Matrix::ProxyMatrix Matrix::operator[](int x) {
    if (x < this->length) {
		return ProxyMatrix(this, x);
    }
	throw "Index Out of Bounds Exception";

}

<<<<<<< HEAD
=======
Matrix& Matrix::operator=(Matrix matrix) {
    swap(*this, matrix);
    return *this;
}
>>>>>>> a6e995621e9efe38ece47f61165a666037453b09

Matrix Matrix::operator+(const Matrix &matrix) {
	if (this->length == matrix.length && this->height == matrix.height) {
		
		Matrix newMatrix(this->length, this->height);

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < this->height; j++) {
				newMatrix.setPosition(i, j, this->getPosition(i, j) + matrix.getPosition(i, j));
			}
		}
		newMatrix.printMatrix();
		return newMatrix;
	}
	throw "Matrices Have Incompatible Dimensions Exception";
}

Matrix Matrix::operator-(const Matrix &matrix) {
    if (this->length == matrix.length && this->height == matrix.height) {

        Matrix newMatrix(this->length, this->height);

        for(int i = 0; i < this->length; i++) {
            for(int j = 0; j < this->height; j++) {
                newMatrix.setPosition(i, j, this->getPosition(i, j) - matrix.getPosition(i, j));
            }
        }
        return newMatrix;
    }
    throw "Matrices Have Incompatible Dimensions Exception";
}

Matrix Matrix::operator*(const Matrix &matrix) {
	if (this->length == matrix.height) {

		Matrix newMatrix(this->height, matrix.length);

		for (int i = 0; i < this->length; i++) {
			for (int j = 0; j < matrix.height; j++) {
				for (int k = 0; k < matrix.length; k++) {
					newMatrix.setPosition(i, j, newMatrix.getPosition(i, j) + (this->getPosition(i, k) * matrix.getPosition(k, j)));
                }
			}
		}
		return newMatrix;
		}
	throw "Matrices Have Incompatible Dimensions Exception";
}

void Matrix::operator*(int scalar) {

    for(int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->height; j++) {
            this->setPosition(i, j, scalar * this->getPosition(i, j));
        }
    }
}