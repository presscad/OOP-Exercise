#include "StudentSystem.h"
#include <iostream>
using namespace std;

int main()
{
    CStudentSystem stuSys;
    int num, ret;
    Student stu;

    while (1) {
        system("cls");
        stuSys.mainPage();
        cout << "��ѡ����Ŀ���в���:";
        if (!(cin >> num)) {
            cin.clear();
            cin.sync();
            cout << "ѡ����Ŀ����������ѡ��" << endl;
            system("pause");
        }
        else {
            cout << endl;
            switch (num) {
                case 1:
                    cout << "������ѧ����Ϣ����ѧ�� ���� �Ա� ���� �꼶�ķ�ʽ����" << endl;
                    if (!(cin >> stu.Id >> stu.Name >> stu.Sex >> stu.Age >> stu.Grade)) {
                        cin.clear();
                        cin.sync();
                        cout << "ѧ����Ϣ�������������¼��" << endl;
                        system("pause");
                        break;
                    }
                    ret = stuSys.insert(stu);
                    if (ret == ERROR_OPENFILE)
                        cout << "Error." << ERROR_OPENFILE << ": �ļ���ʧ��" << endl;
                    else if (ret == ERROR_STUDENTEXIST)
                        cout << "Error." << ERROR_STUDENTEXIST << ": ��ѧ�ŵ�ѧ���Ѵ���" << endl;
                    else
                        cout << "�ɹ�����һ��ѧ����Ϣ" << endl;

                    cout << endl;
                    system("pause");
                    break;

                case 2:
                    ret = stuSys.display();
                    if (ret == ERROR_OPENFILE)
                        cout << "Error." << ERROR_OPENFILE << ": �ļ���ʧ��" << endl;

                    cout << endl;
                    system("pause");
                    break;

                case 3:
                    return 0;

                default:
                    cout << "��ѡ�����Ŀ����������Χ�ڣ��������������ֽ��в���" << endl;

                    cout << endl;
                    system("pause");
                    break;
            }
        }
    }

    return 0;
}