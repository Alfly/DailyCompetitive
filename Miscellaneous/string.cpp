// 手写 string 类：实现构造函数、析构函数、拷贝构造函数、重载=操作符
// 参考 https://www.cnblogs.com/nujer/p/14323019.html

#include <iostream>
#include <string>

class String
{
public:
    String(const char * = nullptr);
    String(const String &);
    String &operator=(const String &); // 设置为成员函数
    ~String();
    String operator+(const String &);                                // 设置为成员函数
    friend std::ostream &operator<<(std::ostream &, const String &); // 友元重载
    unsigned int Strlen(const char *);
    char *Strcpy(char *, const char *);
    char *Memcpy(char *, const char *, int); // 检查内存的重叠问题
    unsigned int Getlen() const;
    char *Getdata() const;

private:
    char *data; // 指向存储字符串的内存空间
    int length; // 保存字符串长度
};

inline String::String(const char *str)
{
    if (str)
    {
        length = Strlen(str);
        data = new char[length + 1];
        Strcpy(data, str);
    }
    else
    {
        length = 0;
        data = new char[1];
        data[length] = '\0';
    }
}

// 拷贝构造
inline String::String(const String &str)
{
    data = new char[str.length + 1];
    Strcpy(data, str.data);
}

// 拷贝赋值
// https://blog.csdn.net/annjeff/article/details/108952294
inline String &String::operator=(const String &str)
{
    // 检测自我赋值以提高效率
    if (this == &str)
    {
        return *this;
    }
    delete[] data;                   // 回收空间
    data = new char[str.length + 1]; // 开辟空间
    Strcpy(data, str.data);
    return *this;                    // 返回自身的引用
}

String::~String()
{
    delete[] data;
    data = nullptr;
}

inline String String::operator+(const String &str)
{
    String res;
    unsigned int new_length = length + str.Getlen();
    res.data = new char[new_length + 1];
    // 实现拼接
    Strcpy(res.data, data);
    Strcpy(res.data + Strlen(res.data), str.Getdata());
    res.data[new_length] = '\0';
    return res;
}

inline std::ostream &operator<<(std::ostream &out, const String &str)
{
    out << str.data;
    return out;
}

inline unsigned int String::Strlen(const char *str)
{
    const char *t = str;
    while (*t)
        t++;
    return t - str;
}

inline char *String::Strcpy(char *dst, const char *src)
{
    if (dst == nullptr || src == nullptr)
    {
        return nullptr;
    }
    char *ret = dst;
    if (Memcpy(dst, src, Strlen(src) + 1))
    {
        return ret;
    }
    else
    {
        return nullptr;
    }
}

// cnt是源字符串的长度，利用内存连续的特点计算是否出现重叠
inline char *String::Memcpy(char *dst, const char *src, int cnt)
{
    if (dst == nullptr || src == nullptr)
    {
        return nullptr;
    }
    char *ret = dst;
    if (dst >= src && dst <= src + cnt - 1) // 内存重叠，从高地址开始复制
    {
        dst = dst + cnt - 1;
        src = src + cnt - 1;
        while (cnt--)
        {
            *dst-- = *src--;
        }
    }
    else // 正常情况，从低地址开始复制
    {
        while (cnt--)
        {
            *dst++ = *src++;
        }
    }
    return ret;
}

inline unsigned int String::Getlen() const
{
    return length;
}

inline char *String::Getdata() const
{
    return data;
}

int main() {
    String a = String("hello");
    String b = a;
    std::cout << b << std::endl;

    return 0;
}