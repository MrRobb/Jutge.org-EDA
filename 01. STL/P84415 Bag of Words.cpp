//
//  P84415 Bag of Words.cpp
//  EDA
//
//  Created by Roberto Ariosa Hernández on 19/09/2017.
//  Copyright © 2017 Mr.Robb. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

//store p
//delete p
//maximum?
//minimum?


int main()
{
    map <string, int> m;
    string op;
    string x;
    
    while (cin >> op)
    {
        if (op == "store")
        {
            cin >> x;
            if (m.find(x) != m.end()) ++m[x];
            else m[x] = 1;
        }
        else if (op == "delete")
        {
            cin >> x;
            if (m.find(x) != m.end())
            {
                if (m[x] > 1) --m[x];
                else m.erase(x);
            }
        }
        else if (op == "minimum?")
        {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else
            {
                map<string, int>::iterator it= m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else //maximum?
        {
            if (m.empty()) cout << "indefinite maximum" << endl;
            else
            {
                map<string, int>::iterator it = m.end();
                --it;
                cout << "maximum:" << " " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}
