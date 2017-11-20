//
//  P90766 Treasures3.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 13/11/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
int m;

int treasure(vector< vector<char> > &v, int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m) {
		if (v[x][y] == 'X') return 0;
		bool here = v[x][y] == 't';
		v[x][y] = 'X';
		int r = (treasure(v, x, y + 1) +
				 treasure(v, x, y - 1) +
				 treasure(v, x + 1, y) +
				 treasure(v, x - 1, y));
		return r + here;
	}
	else return 0;
}

int main(){
	// Initialize
	cin >> n;
	cin >> m;
	
	vector< vector<char> > v(n, vector<char> (m));
	
	// Read
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	
	// Computer and print
	int x; cin >> x;
	int y; cin >> y;
	cout << treasure(v, x - 1, y - 1) << endl;
	
}
