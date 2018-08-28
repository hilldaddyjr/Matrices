#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

//using namespace std;

class Matrix {

private:
    int length;
    int height;
    std::vector<std::vector<int> > vectorMatrix;
    
public:
    Matrix();
    Matrix(int length, int height);
    ~Matrix();

    //Returns element in matrix at position [x,y] (returns 0 if OOB)
    int getPosition(int x, int y) const;

    //Sets element in matrix at position [x,y] to value (ignored if OOB)
    void setPosition(int x, int y, int value);

    //Sets element in matrix at position [x,y] to 0 (ignored if OOB)
    void clearPosition(int x, int y);

    //Prints matrix in the form: x1y1 x2y1 ... x1yn \n for all yß
    void printMatrix() const;

	Matrix operator+(const Matrix &matrix);
	Matrix operator*(const Matrix &matrix);
	
};

#endif