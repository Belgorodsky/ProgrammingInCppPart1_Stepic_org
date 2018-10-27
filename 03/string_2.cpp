#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <algorithm>

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c)
    {
        size = n;
        str = new char[n+1];
        str[n] = 0;
        std::fill(str, str + n, c);
    }

    /* и деструктор */
	~String()
    {
        delete[] str;
    }


	size_t size;
	char *str;
};
