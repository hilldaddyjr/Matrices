#include "Debug.h"

int main() {

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

		Matrix matrix3(3, 3);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				matrix3.setPosition(i, j, rand() % 10);
			}
		}

		std::cout << "Matrix One" << std::endl;
        matrix.printMatrix();
		std::cout << std::endl;

		std::cout << "Matrix Two" << std::endl;
		matrix2.printMatrix();
		std::cout << std::endl;
	
		std::cout << "Matrix Three" << std::endl;
		matrix3.printMatrix();
		std::cout << std::endl;

		//Matrix operator[][] test
		std::cout << "Element [1][2] of Matrix 1: " << matrix[1][2] << std::endl;
		std::cout << std::endl;

		//Matrix operator+ test
		std::cout << "Matrix 1 + Matrix 2: " << std::endl;
		Matrix matrix12 = matrix + matrix2;
		matrix12.printMatrix();
		std::cout << std::endl;


		//Matrix operator- test
		std::cout << "Matrix 2 - Matrix 3: " << std::endl;
		Matrix matrix23 = matrix2 - matrix3;
		matrix23.printMatrix();
		std::cout << std::endl;

		//Matrix operator* test (Matrix * Matrix)
		std::cout << "Matrix 1 * Matrix 3: " << std::endl;
		Matrix matrix13 = matrix * matrix3;
		matrix13.printMatrix();
		std::cout << std::endl;

		//Matrix operator* test (Matrix * Scalar)
		std::cout << "Matrix3 * Scalar 5: " << std::endl;
		Matrix matrix35 = matrix3 * 5;
		matrix35.printMatrix();
		std::cout << std::endl;

//		std::cout << "Scalar 5 * Matrix 3: " << std::endl;
//		Matrix matrix53 = 5 * matrix3;
//		matrix53.printMatrix();
//		std::cout << std::endl;

		int x;
		std::cin >> x;
        return 0;
}