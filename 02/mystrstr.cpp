int strstr(const char *text, const char *pattern)
{
    if (text && pattern)
    {
        int len = 0;
        for (const char *p = pattern;*p; ++p) ++len;
        int text_len = 0;
        for (const char *t = text; *t; ++t) ++text_len;
		
        if (!len) return 0;
        else if (text_len < len) return -1;
		else
		{
			for (const char *t = text; *t; ++t)
			{
				bool find = true;
				const char *t2 = t;
				for (const char *p = pattern; *p; ++p, ++t2) find &= *p == *t2;
				if (find) return t2 - text - len;
			}
		}
    }

    return -1;
}
