#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void Print()
{
	cout << "Hello World" << endl;
}

int main()
{
	//typedef void FuncType();
	using FuncType = void();
	FuncType* ptr = &Print;

}