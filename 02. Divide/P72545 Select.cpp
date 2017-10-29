//
//  P72545 Select.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 28/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int select(int k, const vector<int>& v1, const vector<int>& v2)
{
//	if (v1.size() > 0)
//		return v2[k - 1];
//	if (v2.size() > 0)
//		return v1[k - 1];
//	if (k == 1)
//		return min(v1[0], v2[0]);
	
	int i = k / 2;
	int j = k - i;
	int step = k / 4;
	while (step > 0) {
		if (v1[i - 1] > v2[j - 1]) {
			i -= step;
			j += step;
		}
		else {
			i += step;
			j -= step;
		}
		step /= 2;
	}
	if (v1[i] > v2[j])
		return v1[i];
	else
		return v2[j];
}

int main()
{
	vector<int> v1 = {5, 7, 9, 10};
	vector<int> v2 = {5, 6, 8};
	cout << select(4, v1, v2) << endl;
}
