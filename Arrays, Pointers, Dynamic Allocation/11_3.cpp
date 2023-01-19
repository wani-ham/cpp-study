#include <iostream>
using namespace std;

void mySwap(int& a, int& b)
{
	int temp{};
	temp = a;
	a = b;
	b = temp;
	return;
}


int main()
{
	int a{ 1 }, b{ 2 };
	cout << "a: " << a << ", b: " << b << endl << "swap!"<<endl;
	mySwap(a, b);
	cout << "a: " << a << ", b: " << b << endl;
	return 0;
}