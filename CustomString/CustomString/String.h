#ifndef __CUSTOM_STRING_H__
#define __CUSTOM_STRING_H__
#include <iostream>
class String
{
    //��������
public:
    String();
    String(const char *str);
    String(const String &other);
    ~String();

    //���������
public:
    String& operator=(const String &other); //��ֵ������
    String& operator=(const char* str); //��ֵ������
    char& operator[](int index);
    String operator+(const char *rhs);
    String operator+(const String &rhs);
    bool operator>(const String &rhs);
    bool operator<(const String &rhs);
    bool operator==(const String &rhs);
    bool operator!=(const String &rhs);
    operator char*() const; //ǿ������ת����

    friend std::istream& operator>>(std::istream &in, String &str);
    friend std::ostream& operator<<(std::ostream &out, const String &str);
    friend String operator+(const char *lhs, const String &rhs);

    //��Ա����
public:
    int length() const;
    String substr(unsigned int start, unsigned int length) const;

protected:
    char * m_str;
};

#endif


