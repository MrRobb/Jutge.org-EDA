//
//  P59282 Statistical Measures.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 04/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
	string s;
	multiset<int> set;
	while (cin >> s) {
		if (s == "number") {
			int x; cin >> x;
			set.insert(x);
		}
		else if (s == "delete") {
			if (not set.empty()) set.erase(set.begin());
		}
		
		if (not set.empty()) {
			cout << "minimum: " << set.lower_bound() << ", maximum: " << ", average: " << endl;
		}
		else cout << "no elements" << endl;
	}
}
