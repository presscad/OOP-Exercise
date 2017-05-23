#pragma once
#include "..\BLL\LoginManager.h"

// CLoginDlg �Ի���

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    LoginManager *m_pLoginManager;
    CString m_roleName;
    CString m_userName;
    int m_userId;
public:
    afx_msg void OnBnClickedOk();
public:
    afx_msg void OnBnClickedCancel();
public:
    virtual BOOL OnInitDialog();
};
