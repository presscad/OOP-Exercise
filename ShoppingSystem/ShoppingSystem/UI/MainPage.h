// ShoppingSystemDlg.h : ͷ�ļ�
//
#pragma once
#include "SidebarSheet.h"
#include "QuerySheet.h"
#include "DailyGSalesSheet.h"
#include "CashierSheet.h"

// MainPage �Ի���
class MainPage : public CDialog
{
// ����
public:
	MainPage(CWnd* pParent = NULL);	// ��׼���캯��
    ~MainPage();

// �Ի�������
	enum { IDD = IDD_MAIN };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg LRESULT OnSidebarMenuItem(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
    CSidebarSheet m_sidebar;
    CStatusBar m_statusBar;
    CQuerySheet *m_pQuerySheet;
    CDailyGSalesSheet *m_pDailyGSSheet;
    CCashierSheet *m_pCashierSheet;
    int m_userId;

public:
    int getUserId() {return m_userId;} //�û�Id��רָ�ۻ�ԱId
};
