//
//  P29212 Modular Exponenciation.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 23/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>

using namespace std;

int modular_pow(int base, int exponent, int modulus)
{
	int result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

int main() {
	int n, k, m;
	while (cin >> n >> k >> m) {
		cout << modular_pow(n, k, m) << endl;
	}
}
