void strcat(char *to, const char *from)
{
    if (from)
    {
        while (*to) ++to;
        for (;*from;++from,++to) *to = *from; 
        *to = 0;
    }
}
