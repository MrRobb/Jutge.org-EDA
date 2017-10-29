//
//  P40902 Casino.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 15/09/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
	string who;
	string what;
	map<string, int> m;
	while (cin >> who >> what) {
		int x;
		if (what == "wins") {
			cin >> x;
			if (m.find(who) == m.end()) {
				cout << who << " is not in the casino" << endl;
			}
			else {
				m[who] += x;
			}
		}
		else if (what == "leaves") {
			if (m.find(who) == m.end()) cout << who << " is not in the casino" << endl;
			else {
				cout << who << " has won " << m[who] << endl;
				m.erase(who);
			}
		}
		else {
			if (m.find(who) != m.end()) cout << who << " is already in the casino" << endl;
			else m[who] = 0;
		}
	}
	cout << "----------" << endl;
	for (auto it : m) {
		cout << it.first << " is winning " << it.second << endl;
	}
}
