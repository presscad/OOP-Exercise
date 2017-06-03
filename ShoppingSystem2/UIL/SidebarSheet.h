#pragma once
//#include "afxwin.h"
//#include "afxcmn.h"

//SidebarShee��MainPage������Ϣ
#define WM_SBMENUITEM  (WM_USER+10)

//��Ϣ���ݣ�WPARAM����
#define SB_XPWH        1  //��ǰѡ����Ʒά���˵�
#define SB_GWJS        2  //��ǰѡ�������˵�
#define SB_DRMCSP      3  //��ǰѡ����������Ʒ�˵�
#define SB_SHYGL       4  //��ǰѡ���ۻ�Ա����˵�

// CSidebarSheet �Ի���

class CSidebarSheet : public CDialog
{
	DECLARE_DYNAMIC(CSidebarSheet)

public:
	CSidebarSheet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSidebarSheet();

// �Ի�������
	enum { IDD = IDD_SIDEBAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
    CButton m_btn_spwh;
    CButton m_btn_qtsy;
    CButton m_btn_spgl;
    CTreeCtrl m_tree_menu;
    void moveCtrl(int nIDClickedBtn);
    // ���ݵ����İ�ť���ò�����˵���
    void setMenu(int nIDClickedBtn);

public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnBnClickedBtnSpwh();

private:
    // �����������İ�ť�ƶ��ؼ�
    afx_msg void OnBnClickedBtnQtsy();
    afx_msg void OnBnClickedBtnSpgl();
    virtual BOOL OnInitDialog();
    afx_msg void OnNMClickTreeMenu(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult);
};
