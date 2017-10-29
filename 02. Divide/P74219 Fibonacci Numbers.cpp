//
//  P74219 Fibonacci Numbers.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 24/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef int Matrix[2][2];

int mod;

void multiply(int F[2][2], int M[2][2])
{
	int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
	int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
	int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
	
	F[0][0] = x % mod;
	F[0][1] = y % mod;
	F[1][0] = z % mod;
	F[1][1] = w % mod;
}

void power(Matrix &m, int n)
{
	if (n == 0 || n == 1)
		return;
	
	Matrix a = {{1,1},{1,0}};
	power(m, n / 2);
	multiply(m, m);
	
	if (n % 2 != 0)
		multiply(m, a);
}

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else
	{
		Matrix m = {{1,1},{1,0}};
		power(m, n - 1);
		return m[0][0];
	}
}

int main()
{
	int n;
	while (cin >> n >> mod)
	{
		cout << fibonacci(n) << endl;
	}
}

