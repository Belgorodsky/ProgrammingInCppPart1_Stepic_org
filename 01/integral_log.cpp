#include <iostream>
#include <vector>

int custom_log2(int num)
{
	int res = 0;
	while (num /= 2)
	{
		++res;
	}
	return res;
}

int main()
{
	size_t n;
	std::cin >> n;
	std::vector<int> results;
	int _x;

	while (n--)
	{
		std::cin >> _x;
		results.push_back(custom_log2(_x));
	}

	for ( size_t i = 0 ; i != results.size(); ++i)
		std::cout << results[i] << std::endl;

	return 0;
}
