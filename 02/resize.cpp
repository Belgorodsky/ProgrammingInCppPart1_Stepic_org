#include <algorithm>
#include <cstring>

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = 0;
    if (new_size)
    {
        new_str = new char[new_size];
        memcpy(new_str, str, std::min(size,new_size));
    }
    delete [] str;
    return new_str;
}
