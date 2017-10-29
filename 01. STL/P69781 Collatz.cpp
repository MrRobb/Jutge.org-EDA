//
//  P69781 Collatz.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 15/09/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <map>

#define LIMIT 100000000

using namespace std;

int main() {
	int n, x, y;
	map<int, int> m;
	while (cin >> x >> y >> n) {
		bool repeated = false;
		int result = 0;
		while (not repeated && n <= LIMIT) {
			if (m.find(n) != m.end()) {
				result = result - m[n];
				repeated = true;
			}
			result++;
			m[n] = result;
			n = (n % 2) ? 3 * n + y : n / 2 + x;
		}
		m.clear();
		cout << (repeated ? result : n)  << endl;
	}
}
