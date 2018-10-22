#include <iostream>
#include <vector>

int main()
{
	size_t lines;
	int _x, _y;
	std::cin >> lines;

	std::vector<int> results;     
	while(lines--)
	{
		std::cin >> _x >> _y;
		results.push_back(_x+_y);
	}

	// put your code here
	for (size_t i = 0; i != results.size(); ++i)
		std::cout << results[i] << std::endl;

	return 0;
}
