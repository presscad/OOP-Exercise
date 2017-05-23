#pragma once

class GSales
{
public:
    GSales(int gId, int sId, int sNum);
    GSales(CString gName, double gPrice, int gNum, int allSNum);
    GSales(int gId, CString gName, double gPrice, int amount);
    GSales() {};
    ~GSales() {};

public:
    int getGId();
    void setGId(int gId);
    int getSId();
    void setSId(int sId);
    int getSNum();
    void setSNum(int sNum);
    CString getGName();
    void setGName(CString gName);
    double getGPrice();
    void setGPrice(double gPrice);
    int getGNum();
    void setGNum(int gNum);
    int getAllSNum();
    void setAllSNum(int allSNum);

private:
    int gId;  //��ƷId
    int sId;  //�ۻ�ԱId
    int sNum; //��������

    CString gName;  //��Ʒ����
    double gPrice;  //��Ʒ����
    int gNum;       //��Ʒ����
    int allSNum;    //������Ʒ�����ܺ�
};
