#include <iostream>
using namespace std;

void printString(const char* str)
{
	while (*str != '\0')
	{
		std::cout << *str;
		++str;
	}

	return;
}

int main()
{
	printString("Wanna go Home!");
	return 0;
}
