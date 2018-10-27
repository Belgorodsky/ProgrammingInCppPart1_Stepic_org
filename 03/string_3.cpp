#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();
	void append(String &other);
	size_t size;
	char *str;
};

void String::append(String &other) {
    size += other.size;
    char* n_str = strcat(strcat(new char[size+1], str), other.str);
    delete[] str;
    str = n_str;
}
