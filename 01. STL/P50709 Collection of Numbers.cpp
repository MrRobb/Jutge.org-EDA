//
//  main.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 15/09/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <queue>
#include <iostream>

using namespace std;

int		main() {
	char op;
	int x;
	priority_queue<int> q;
	while (cin >> op) {
		switch (op) {
			case 'S':
				cin >> x;
				q.push(x);
				break;
				
			case 'A':
				if (q.empty())
					cout << "error!" << endl;
				else
					cout << q.top() << endl;
				break;
				
			case 'R':
				if (q.empty())
					cout << "error!" << endl;
				else
					q.pop();
				break;
				
			case 'I':
				cin >> x;
				if (q.empty())
					cout << "error!" << endl;
				else {
					x += q.top();
					q.pop();
					q.push(x);
				}
				break;
				
			case 'D':
				cin >> x;
				if (q.empty())
					cout << "error!" << endl;
				else {
					x = q.top() - x;
					q.pop();
					q.push(x);
				}
				
				break;
				
			default:
				cout << "error!" << endl;
				break;
		}
	}
}
