//
//  P84219 First Occurrence.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 16/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
	int middle = (right - left)/2 + left;
	//cout << left << ' ' << middle << ' ' << right << endl;
	if (left > right) return -1;
	if (left == right) return (v[left] == x) ? left : -1;
	
	if (v[middle] == x) return position(x, v, left, middle);
	else if (v[middle] > x) return position(x, v, left, middle);
	else return position(x, v, middle+1, right);
}

int first_occurrence(double x, const vector<double>& v) {
	return position(x, v, 0, int(v.size()-1));
}

int main() {
	vector<double> v (2);
	v[0] = 0;
	v[1] = 2;
	cout << first_occurrence(2, v) << endl;
}

