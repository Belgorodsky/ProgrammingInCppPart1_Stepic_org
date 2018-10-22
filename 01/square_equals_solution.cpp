#include <cmath>
#include <iostream>

int main()
{
	int a, b, c;

	std::cin >> a >> b >> c ;

	double d = b*b - 4*a*c;

	if ( 0 <= d )
	{
		double sqrtD = sqrt(d);
		std::cout << (-b + sqrtD) / (2. * a) << " " << (-b - sqrtD) / (2. * a) << std::endl;
	}
	else
	{
		std::cout << "No real roots\n";
	}

	return 0;
}
