#include "Debug.h"

int main() {
        //Matrix * matrix = new Matrix(5, 5);
        Matrix matrix(5, 5);
        matrix.setPosition(0,0,10);
        matrix.printMatrix();
        return 0;
}