#include <iostream>
#include <array>
#include <numeric>

using namespace std;
enum Items
{
	potion,
	torch,
	arrow,
	max_index
};

using pocket = array<int, Items::max_index>;

int countTotalItems(const pocket& inven)
{
	int sum{ 0 };
	for (int i{ 0 }; i < size(inven); i++)
		sum += inven[i];
	return sum;
}

int main()
{
	pocket inventory {2,5,10};
	
	std::cout << "Total items : " << countTotalItems(inventory) << endl;
	std::cout << "# of Torch  : " << inventory[Items::torch] << endl;
	return 0;
}