#include <iostream>

void rio()
{
	int _t;
	if (std::cin >> _t)
	{
		if (_t)
		{
			rio();
			std::cout << _t << ' ';
		}
	} 

}

int main()
{
	rio();
	std::cout << '\n';

	return 0;
}
