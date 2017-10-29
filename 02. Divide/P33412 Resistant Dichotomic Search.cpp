//
//  P33412 Resistant Dichotomic Search.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 23/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool i_resistant_search(double x, const vector<double> &v, int i, int j) {
	int m = (j - i - 1)/ 2 + i;
	if (j < i) return false;
	if (v[m] == x) return true;
	else if (m > 0 and v[m - 1] == x) return true;
	else if (m < v.size() - 1 and v[m + 1] == x) return true;
	else if (v[m] > x) return i_resistant_search(x, v, i, m - 1);
	else return i_resistant_search(x, v, m + 1, j);
}

bool resistant_search(double x, const vector<double>& v) {
	return i_resistant_search(x, v, 0, int(v.size()-1));
}

/*
int main() {
	vector<double> v(10);
	v[0] = 2;
	v[1] = 0;
	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	v[5] = 6;
	v[6] = 7;
	v[7] = 8;
	v[8] = 9;
	v[9] = 10;
	cout << resistant_search(2, v) << endl;
}*/
