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

enum ErrorHandler
{
    ERROR_SUCCESSFUL = 0,  //�޴���
    ERROR_OPENFILE,        //���ļ�ʧ��
    ERROR_STUDENTEXIST     //���ӵ�ѧ��Id�ظ�
};

class CStudentSystem
{
public:
    CStudentSystem() {};
    ~CStudentSystem() {};
    
public:
    void mainPage();
    int insert(const Student& stu);
    int display();

private:
    bool readFile();
    bool writeFile(const Student& stu);
    void displayHead();

private:
    vector<Student> m_stuInfo;
};
