#include <iostream>
#include <cstring>

char *getline()
{
    size_t size = 64;
    char *c = new char[size];
    int i = 0;
    for(; std::cin.get(c[i]) && c[i] != '\n'; ++i)
    {
        if (size == 1 + i)
        {
            size *= 3;
            c = (char*)realloc(c, size);
        }
    }
    c[i] = 0;
    return c;
}
