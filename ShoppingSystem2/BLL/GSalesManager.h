#pragma once

class BLL_API GSalesManager
{
public:
    GSalesManager() {};
    ~GSalesManager() {};

public:
    CArray<GSales> * dailyGSales();
    BOOL cashierByOnce(CArray<GSales> *pArrayOrder, int gId, unsigned int amount); //ÿ��ɨ������
    BOOL uncashierAll(CArray<GSales> *pArrayOrder);  //ȡ�����ε���
    BOOL settleAccount(CArray<GSales> *pArrayOrder, int sId); //�������ĵ������ݲ������۱�
};