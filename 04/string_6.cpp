#include <cstddef> // size_t
#include <cstring>

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);

    struct SubstrProxy
    {
        explicit SubstrProxy(const char*p, size_t off) : str(p), offset(off) {}
        
        String operator[](int idx) const
        {
            size_t size = idx-offset + 1;
            size_t len = size - 1;
            char *tmp_str = new char[size];
            tmp_str[len] = 0;
            memcpy(tmp_str, str+offset, len);
            String ret_val(tmp_str);
            delete[] tmp_str;
            return ret_val;
        }
        
        const char *str;
        size_t offset;
    };
    
    SubstrProxy operator[](int idx) const
    {
        return SubstrProxy(str,idx);
    }
    
	size_t size;
	char *str;
};
