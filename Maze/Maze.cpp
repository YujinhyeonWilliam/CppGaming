#include <iostream>
#include "Vector.h"

int main()
{
	Vector v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	int a = v[2];

	v.pop_back();
	v.pop_back();
	v.clear();
	v.push_back(6);

}
