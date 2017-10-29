//
//  P80595 Inversions.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 27/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int e, int m, int d, int &inversions) {
	vector<int> aux(d - e + 1);
	int i = e, j = m + 1, k = 0;
	
	while(i <= m and j <= d) {
		if (v[i] <= v[j])
			aux[k++] = v[i++];
		else {
			// v[i] > v[j]
			inversions = inversions + (m + 1) - i;
			aux[k++] = v[j++];
		}
	}
	while(i <= m)
		aux[k++] = v[i++];
	
	while(j <= d)
		aux[k++] = v[j++];
	
	for (k = 0; k < (d - e + 1); ++k)
		v[e + k] = aux[k];
}

void mergesort(vector<int> &v, int e, int d, int &inversions) {
	if(e < d) {
		int m = (d+e)/2;
		mergesort(v, e, m, inversions);
		mergesort(v, m+1, d, inversions);
		merge(v, e, m, d, inversions);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int inversions = 0;
		mergesort(v, 0, n - 1, inversions);
		cout << inversions << endl;
	}
}
