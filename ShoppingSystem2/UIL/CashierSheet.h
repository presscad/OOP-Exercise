#pragma once
//#include "afxcmn.h"
//#include "afxwin.h"
//#include "..\Entity\GSales.h"

// CCashierSheet �Ի���

class CCashierSheet : public CDialog
{
	DECLARE_DYNAMIC(CCashierSheet)

public:
	CCashierSheet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCashierSheet();

// �Ի�������
	enum { IDD = IDD_CASHIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
    virtual BOOL OnInitDialog();
    CListCtrl m_LV_Goods;
    CListCtrl m_LV_Cart;
    CString m_strName;
    int m_nQuantity;
    CString m_strAmount;  //�ַ�����ʽ��ʾӦ�ս��
    double m_fAmount;  //��������ʽ�洢Ӧ�ս��
    double m_fPaid;  //ʵ�ս��
    CString m_strCharge;
    CArray<GSales> *m_pArrayOrder;

    void moveCtrl(void);
    afx_msg void OnDeltaposSpinQuantity(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedBtnQuery();
    afx_msg void OnBnClickedBtnPurchase();
    afx_msg void OnBnClickedBtnCancel();
    afx_msg void OnBnClickedBtnCash();

public:
    void Init(void);
public:
    afx_msg void OnLvnItemchangedLvGoods(NMHDR *pNMHDR, LRESULT *pResult);
};
