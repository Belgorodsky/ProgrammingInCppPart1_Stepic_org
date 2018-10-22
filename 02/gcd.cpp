template<class Int>
Int gcd(Int a, Int b)
{
	Int current_gcd = 1;
	if (!a) current_gcd = b;
	else if (!b) current_gcd = a;
	else if (a <= b) current_gcd = gcd(a, b % a);
	else current_gcd = gcd(a % b, b);

	return current_gcd;
}
