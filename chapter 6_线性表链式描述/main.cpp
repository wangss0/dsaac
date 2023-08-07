

#include <iostream>
#include "chain.h"
using namespace std;


int main()
{
	chain<int> ch;

	ch.insert(0, 1);
	ch.insert(0, 2);
	ch.insert(0, 3);
	ch.insert(0, 4);
	ch.insert(0, 5);
	ch.insert(0, 6);

	chain<int> ch2 = ch;
	cout << "ch.size() = " << ch.size() << endl;
	cout << "ch = " << ch << endl;
	cout << endl;
	cout << "ch2.size() = " << ch2.size() << endl;
	cout << "ch2 = " << ch2 << endl;

	cout << endl;

	cout << "ch.indexOf() = " << ch.indexOf(3) << endl;
	
	ch.earse(0);
	cout << "After earse, ch.size() = " << ch.size() << endl;
	cout << "ch = " << ch << endl;


	cout << "ch.empty() = " << ch.empty() << endl;
	cout << "hello world" << endl;
	return 0;
}