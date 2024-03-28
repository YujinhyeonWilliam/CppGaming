#include <iostream>
using namespace std;
#include "Vector.h"
#include <queue>


int main()
{
	{
		Vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		Vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			cout << data << endl;
		}
	}


}