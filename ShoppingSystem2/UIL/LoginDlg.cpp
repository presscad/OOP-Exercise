// ..\UI\Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
//#include "..\Framework\ShoppingSystem.h"
//#include "..\UI\LoginDlg.h"
//#include "..\BLL\AdminManager.h"
//#include "..\Entity\Admin.h"
//#include "..\BLL\SalesmanManager.h"
//#include "..\Entity\Salesman.h"
//#include "..\Tools\Tools.h"

// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent), m_pLoginManager(NULL)
{

}

CLoginDlg::~CLoginDlg()
{
    if (m_pLoginManager) delete m_pLoginManager;
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������

void CLoginDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int roleId = ((CComboBox*) GetDlgItem(LGIN_COMB_ROLE))->GetCurSel();
    CString userName;
    CString password;
    BOOL fRet;
    GetDlgItemText(LGIN_EDT_USERNAME, userName);
    GetDlgItemText(LGIN_EDT_PWD ,password);

    if (userName == _T("") || password == _T("")) {
        SetDlgItemText(LGIN_STATIC_TIPS, _T("�û��������벻��Ϊ��"));
        return;
    }

    if (roleId == 0) {
        m_pLoginManager = new SalesmanManager();
        m_roleName = _T("�ۻ�Ա");
    }
    else {
        m_pLoginManager = new AdminManager();
        m_roleName = _T("����Ա");
    }
    fRet = m_pLoginManager->validateLogin(m_userId, userName, password);
    if (fRet) {
        m_userName = userName;
        OnOK();
    }
    else {
        int chance = m_pLoginManager->getInstanceCount();
        if (chance >= 3) OnCancel();
        else
            SetDlgItemText(LGIN_STATIC_TIPS, _T("�û��������벻��ȷ��������") + toCString(3-chance) + _T("�λ���"));

        delete m_pLoginManager;
        m_pLoginManager = NULL;
    }
}

void CLoginDlg::OnBnClickedCancel()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    OnCancel();
}

BOOL CLoginDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    SetIcon(hIcon, TRUE);
    SetIcon(hIcon, FALSE);

    ((CComboBox*) GetDlgItem(LGIN_COMB_ROLE))->SetCurSel(0);
    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}
