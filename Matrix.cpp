#include "Matrix.h"

Matrix::Matrix() {
        height = 3;
        width = 3;
        vectorMatrix.resize(width, std::vector<int>(height, 0));
}

Matrix::Matrix(int height, int width) {
        this->height = height;
        this->width = width;
        vectorMatrix.resize(width, std::vector<int>(height, 0));
}

Matrix::~Matrix() {
}

int Matrix::getPosition(int x, int y) {
    if (x >= height || y >= width) {
        return 0;
    }

    return vectorMatrix[x][y];
}

void Matrix::setPosition(int x, int y, int value) {
    if (x < height && y < width) {
        vectorMatrix[x][y] = value;
    }
}

void Matrix::clearPosition(int x, int y) {
    if (x < height && y < width) {
        vectorMatrix[x][y] = 0;
    }
}

void Matrix::printMatrix() {

        //Y axis spacing buffer
        std::cout << "   ";
        
        //Y axis label
        for(int y = 0; y < width; y++) {
            std::cout << y << " ";
        }

        std::cout << std::endl;

        //Y axis
        for(int y = 0; y < width; y++) {
            std::cout << "--";
        }

        std::cout << std::endl;

        for (int x = 0; x < height; x++) {

                //X axis label and spacing buffer
                std::cout << x << " | ";
                for (int y = 0; y < width; y++) {
                        std::cout << vectorMatrix[x][y] << " ";
                }
                std::cout << std::endl;
        }
}