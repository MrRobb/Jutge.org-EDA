//
//  P37064 Dynamic Median.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 04/10/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> s7;
	string s;
	bool odd = false;
	auto med = s7.end();
	while (cin >> s && s != "END") {
		auto it = s7.insert(s).first;
		odd = !odd;
		if (med == s7.end()) med = it;
		else if (not odd and s < *med) --med;
		else if (odd and s > *med) ++med;
		cout << *med << endl;
	}
}
