#pragma once
#include "afxwin.h"
#include "Add_ModifyDlg.h"

// CQuerySheet �Ի���

class CQuerySheet : public CDialog
{
	DECLARE_DYNAMIC(CQuerySheet)

public:
	CQuerySheet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQuerySheet();

// �Ի�������
	enum { IDD = IDD_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    enum querySheetStyle {sheetGoods, sheetSalesman};  //CQuerySheet�Ի�����;/���
    // �����ͽ��г�ʼ��
    void Init(querySheetStyle sheetStyle);
private:
    CListCtrl m_listView;
    CString m_static_queryName;
    CString m_edit_queryName;
    CButton m_query;
    CButton m_add;
    CButton m_update;
    CButton m_delete;
    querySheetStyle m_sheetStyle;
    void moveCtrl(void);
    afx_msg void OnBnClickedBtnQuery();
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedBtnAdd();
    afx_msg void OnBnClickedBtnUpdate();
    afx_msg void OnLvnItemchangedLvView(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedBtnDelete();
};
