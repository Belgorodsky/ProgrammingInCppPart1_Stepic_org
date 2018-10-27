#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

   	String(const char *str_ = "")
	    : size {strlen(str_)}
	    , str  {strcpy(new char[size + 1], str_ )}
    {}

	size_t size;
	char *str;
};
