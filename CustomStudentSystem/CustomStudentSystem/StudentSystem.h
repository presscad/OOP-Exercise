#pragma once
#include <string>
#include <vector>
using namespace std;

struct Student
{
    unsigned int Id;  //ѧ��
    unsigned int Age; //����
    string Name;      //����
    string Sex;       //�Ա�
    string Grade;     //�꼶
};

enum RESULT
{
    ERROR_SUCCESSFUL = 0x00000001,      //�޴���
    ERROR_OPENFILE = 0x00000010,        //���ļ�ʧ��
    ERROR_STUDENTEXIST = 0x00000100,    //���ӵ�ѧ��Id�ظ�
    ERROR_NOFINDRESULT = 0x00001000     //δ���ҵ�ָ��Id��ѧ��
};

class CStudentSystem
{
public:
    CStudentSystem() {};
    ~CStudentSystem() {};
    
public:
    void mainPage();
    void display();
    RESULT read();
    RESULT insert(const Student& stu);
    RESULT find(int Id);
    RESULT update(const Student& stu);
    RESULT remove(int Id);

private:
    bool readFile();
    bool writeFile(const Student& stu);
    bool writeFile();
    void displayHead();

private:
    vector<Student> m_stuInfo;
};
