#include "StudentSystem.h"
#include <iostream>
using namespace std;

void printError(RESULT fRet)
{
    switch (fRet) {
        case ERROR_NOFINDRESULT:
            cout << "Error." << ERROR_NOFINDRESULT << ": δ�ҵ���ѧ�ŵ�ѧ����Ϣ" << endl;
            break;
        case ERROR_OPENFILE:
            cout << "Error." << ERROR_OPENFILE << ": �ļ���ʧ��" << endl;
            break;
        case ERROR_STUDENTEXIST:
            cout << "Error." << ERROR_STUDENTEXIST << ": ��ѧ�ŵ�ѧ���Ѵ���" << endl;
            break;
        default:
            break;
    }
}

int main()
{
    CStudentSystem stuSys;
    int num;
    RESULT ret;
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
                case 1:  //¼��
                    cout << "������ѧ����Ϣ����ѧ�� ���� �Ա� ���� �꼶�ķ�ʽ����" << endl;
                    if (!(cin >> stu.Id >> stu.Name >> stu.Sex >> stu.Age >> stu.Grade)) {
                        cin.clear();
                        cin.sync();
                        cout << "ѧ����Ϣ�������������¼��" << endl;
                        system("pause");
                        break;
                    }
                    ret = stuSys.insert(stu);
                    if (ret & ERROR_SUCCESSFUL)
                        cout << "�ɹ�����һ��ѧ����Ϣ" << endl;
                    else
                        printError(ret);

                    cout << endl;
                    system("pause");
                    break;

                case 2:  //��ȡ
                    ret = stuSys.read();
                    if (ret & ERROR_SUCCESSFUL)
                        stuSys.display();
                    else
                        printError(ret);

                    cout << endl;
                    system("pause");
                    break;

                case 3:  //����
                    cout << "������ѧ�ţ�";
                    if (!(cin >> num)) {
                        cin.clear();
                        cin.sync();
                        cout << "ѧ���������������¼��" << endl;
                        system("pause");
                        break;
                    }
                    ret = stuSys.find(num);
                    if (ret & ERROR_SUCCESSFUL)
                        stuSys.display();
                    else
                        printError(ret);

                    cout << endl;
                    system("pause");
                    break;

                case 4:  //����
                    cout << "��������Ҫ���µ�ѧ����Ϣ����ѧ�� ���� �Ա� ���� �꼶�ķ�ʽ����" << endl;
                    if (!(cin >> stu.Id >> stu.Name >> stu.Sex >> stu.Age >> stu.Grade)) {
                        cin.clear();
                        cin.sync();
                        cout << "ѧ����Ϣ�������������¼��" << endl;
                        system("pause");
                        break;
                    }
                    ret = stuSys.update(stu);
                    if (ret & ERROR_SUCCESSFUL)
                        cout << "�ɹ�����һ��ѧ����Ϣ" << endl;
                    else
                        printError(ret);

                    cout << endl;
                    system("pause");
                    break;

                case 5:  //ɾ��
                    cout << "������ѧ�ţ�";
                    if (!(cin >> num)) {
                        cin.clear();
                        cin.sync();
                        cout << "ѧ���������������¼��" << endl;
                        system("pause");
                        break;
                    }
                    ret = stuSys.remove(num);
                    if (ret & ERROR_SUCCESSFUL)
                        cout << "�ɹ�ɾ��һ��ѧ����Ϣ��ѧ��Ϊ" << num << endl;
                    else
                        printError(ret);

                    cout << endl;
                    system("pause");
                    break;

                case 6:  //�˳�
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