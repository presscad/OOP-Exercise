#pragma once
#include "afxwin.h"

// CAdd_ModifyDlg �Ի���


class CAdd_ModifyDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdd_ModifyDlg)

public:
	CAdd_ModifyDlg(int sheetStyle, BOOL bAdd, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdd_ModifyDlg();

// �Ի�������
	enum { IDD = IDD_ADD_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
    CStatic m_group;
    CStatic m_static[4];
    CEdit m_edit[4];

    int m_sheetStyle;
    BOOL m_bAdd;
    void Init(int sheetStyle, BOOL bAdd);

public:
    CString m_strLabel[4][2];
    
public:
    virtual BOOL OnInitDialog();
public:
    afx_msg void OnBnClickedOk();
};
