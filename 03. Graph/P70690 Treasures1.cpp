//
//  P70690 Treasures1.cpp
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

bool treasure(vector< vector<char> > &v, int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m) {
		if (v[x][y] == 'X') return false;
		if (v[x][y] == 't') return true;
		v[x][y] = 'X';
		return (treasure(v, x, y + 1) or
				treasure(v, x, y - 1) or
				treasure(v, x + 1, y) or
				treasure(v, x - 1, y));
	}
	else return false;
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
	cout << (treasure(v, x - 1, y - 1) ? "yes" : "no") << endl;
	
}
