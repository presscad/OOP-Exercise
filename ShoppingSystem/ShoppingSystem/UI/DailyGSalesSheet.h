#pragma once
#include "afxcmn.h"


// CDailyGSalesSheet �Ի���

class CDailyGSalesSheet : public CDialog
{
	DECLARE_DYNAMIC(CDailyGSalesSheet)

public:
	CDailyGSalesSheet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDailyGSalesSheet();

// �Ի�������
	enum { IDD = IDD_DAILYGSALES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    void queryData(void);
    CListCtrl m_listView;
public:
    void Init(void);
};
