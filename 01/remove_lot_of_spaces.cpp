#include <iostream>

int main()
{
	/* ... */
	char c = '\0';
	char prev = c;
	while (std::cin.get(c)) {
		/* ... */
		if ( !std::isspace(c) || !std::isspace(prev) )
			std::cout << c;
		prev = c;
	}

	return 0;
}
