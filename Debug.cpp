#include "Debug.h"

int main() {
        //Matrix * matrix = new Matrix(5, 5);
        Matrix matrix(3, 3);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix.setPosition(i, j, rand() % 10);
			}
		}

		Matrix matrix2(3, 3);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix2.setPosition(i, j, rand() % 10);
			}
		}
        matrix.printMatrix();
		std::cout << std::endl;

		matrix2.printMatrix();
		std::cout << std::endl;
	
		std::cout << matrix[1][2];
		std::cout << std::endl;

		Matrix matrix3 = matrix + matrix2;

		std::cout << "addition has occured" << std::endl;

		//matrix.printMatrix();
		std::cout << std::endl;

		//matrix2.printMatrix();
		std::cout << std::endl;

		matrix3.printMatrix();
		
		int x;
		std::cin >> x;
        return 0;
}