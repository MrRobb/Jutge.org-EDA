//
//  P61833 Powers Matrix.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 24/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>

using namespace std;

typedef int Matrix[2][2];
int mod;

void modMatrix(Matrix& m) {
	m[0][0] %= mod;
	m[0][1] %= mod;
	m[1][0] %= mod;
	m[1][1] %= mod;
}

bool readMatrix(Matrix& m) {
	return (cin >> m[0][0] and cin >> m[0][1] and cin >> m[1][0] and cin >> m[1][1]);
}

void matrixSquared(Matrix m, Matrix& sqr) {
	sqr[0][0] = m[0][0] * m[0][0] + m[0][1] * m[1][0];
	sqr[0][1] = m[0][0] * m[0][1] + m[1][1] * m[0][1];
	sqr[1][0] = m[0][0] * m[1][0] + m[1][1] * m[1][0];
	sqr[1][1] = m[1][1] * m[1][1] + m[0][1] * m[1][0];
	modMatrix(sqr);
}

void copyMatrix(const Matrix m, Matrix& cpy) {
	cpy[0][0] = m[0][0];
	cpy[0][1] = m[0][1];
	cpy[1][0] = m[1][0];
	cpy[1][1] = m[1][1];
	modMatrix(cpy);
}

void multiplyMatrix(const Matrix m1, const Matrix m2, Matrix& m) {
	m[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
	m[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
	m[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
	m[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
	modMatrix(m);
}

void printMatrix(const Matrix& m) {
	cout << m[0][0] << ' ' << m[0][1] << endl << m[1][0] << ' ' << m[1][1] << endl;
}

int main() {
	Matrix m1;
	while (readMatrix(m1)) {
		// Read data
		int n;
		cin >> n >> mod;
		
		// Compute
		Matrix result = {{1,0},{0,1}};
		
		while (n > 0) {
			if (n % 2 == 1) {
				Matrix aux;
				copyMatrix(result, aux);
				multiplyMatrix(m1, aux, result);
			}
			Matrix aux;
			copyMatrix(m1, aux);
			matrixSquared(aux, m1);
			n /= 2;
		}
		
		// Print
		printMatrix(result);
		cout << "----------" << endl;
	}
}
