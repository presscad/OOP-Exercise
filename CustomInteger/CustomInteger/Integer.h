#ifndef __CUSTOM_INTEGER_H__
#define __CUSTOM_INTEGER_H__
#include <string>
using namespace std;
class Integer
{
    //��������
public:
    Integer(int value) :m_iValue(value) {};
    Integer() :m_iValue(0) {};
    ~Integer() {};

    //�Ǿ�̬��Ա����
public:
    int getValue() const { return m_iValue; };
    void setValue(int value) { m_iValue = value; };
    bool isEven() const;
    bool isOdd() const;
    bool isPrime() const;
    bool equals(int value) const;
    bool equals(const Integer& value) const;
    string toString() const;
    
    //��̬��Ա����
public:
    static bool isEven(int value);
    static bool isOdd(int value);
    static bool isPrime(int value);
    static bool isEven(const Integer& value);
    static bool isOdd(const Integer& value);
    static bool isPrime(const Integer& value);
    static int parseInt(const string& value);

protected:
    int m_iValue;
};

#endif

