int strstr(const char *text, const char *pattern)
{
	if (*pattern)
    {
        for (int i = 0; *text; ++text, ++i)
        {
            const char* t = text;
            const char* p = pattern;
            while (*p++ == *t++) {
                if (!*p) {
                    return i;
                }
            }
        }
    }
    else
    {
        return 0;
    }

    return -1;
}
