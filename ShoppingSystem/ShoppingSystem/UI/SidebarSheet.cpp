// SidebarSheet.cpp : ʵ���ļ�
//

#include "..\Framework\stdafx.h"
#include "..\Framework\ShoppingSystem.h"
#include "SidebarSheet.h"


// CSidebarSheet �Ի���

IMPLEMENT_DYNAMIC(CSidebarSheet, CDialog)

CSidebarSheet::CSidebarSheet(CWnd* pParent /*=NULL*/)
	: CDialog(CSidebarSheet::IDD, pParent)
{
}

CSidebarSheet::~CSidebarSheet()
{
}

void CSidebarSheet::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, SB_BTN_SPWH, m_btn_spwh);
    DDX_Control(pDX, SB_BTN_QTSY, m_btn_qtsy);
    DDX_Control(pDX, SB_BTN_SPGL, m_btn_spgl);
    DDX_Control(pDX, SB_TREE_MENU, m_tree_menu);
}

BEGIN_MESSAGE_MAP(CSidebarSheet, CDialog)
ON_WM_SIZE()
ON_BN_CLICKED(SB_BTN_SPWH, &CSidebarSheet::OnBnClickedBtnSpwh)
ON_BN_CLICKED(SB_BTN_QTSY, &CSidebarSheet::OnBnClickedBtnQtsy)
ON_BN_CLICKED(SB_BTN_SPGL, &CSidebarSheet::OnBnClickedBtnSpgl)
ON_NOTIFY(NM_CLICK, SB_TREE_MENU, &CSidebarSheet::OnNMClickTreeMenu)
ON_NOTIFY(TVN_SELCHANGED, SB_TREE_MENU, &CSidebarSheet::OnTvnSelchangedTreeMenu)
END_MESSAGE_MAP()


void CSidebarSheet::OnSize(UINT nType, int cx, int cy)
{
    CDialog::OnSize(nType, cx, cy);

    // TODO: �ڴ˴������Ϣ����������
    //if (!m_btn_spwh || !m_btn_spgl || !m_btn_qtsy || !m_tree_menu) return;

    //moveCtrl(SB_BTN_SPWH);
    //setMenu(SB_BTN_SPWH);
}

void CSidebarSheet::OnBnClickedBtnSpwh()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    moveCtrl(SB_BTN_SPWH);
    setMenu(SB_BTN_SPWH);
    InvalidateRect(NULL);

}

void CSidebarSheet::OnBnClickedBtnQtsy()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    moveCtrl(SB_BTN_QTSY);
    setMenu(SB_BTN_QTSY);
    InvalidateRect(NULL);
}

void CSidebarSheet::OnBnClickedBtnSpgl()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    moveCtrl(SB_BTN_SPGL);
    setMenu(SB_BTN_SPGL);
    InvalidateRect(NULL);
}

void CSidebarSheet::moveCtrl(int nIDClickedBtn) {
    CRect rcClient;
    GetClientRect(&rcClient);

    int xOrg = 5, yOrg = 10, yBtm = rcClient.bottom-5;  //�������Ͻ�����͵ײ�Ԥ���հ�
    int cx = rcClient.right-2*xOrg, cyBtn = 22,
        cyGapTree = 5, cyGapBtn = 2,
        cyTree = yBtm-3*cyBtn-yOrg-cyGapTree-3*cyGapBtn;  //���ó���Ϳؼ��ײ���϶
    int yOrg_btn_qtsy, yOrg_btn_spgl, yOrg_tree_menu;  //�ؼ�����Ľǵ�������


    switch (nIDClickedBtn) {
        case SB_BTN_SPWH:
            yOrg_tree_menu = yOrg+cyBtn+cyGapBtn;
            yOrg_btn_qtsy = yOrg_tree_menu+cyTree+cyGapTree;
            yOrg_btn_spgl = yOrg_btn_qtsy+cyBtn+cyGapBtn;
            break;

        case SB_BTN_QTSY:
            yOrg_btn_qtsy = yOrg+cyBtn+cyGapBtn;
            yOrg_tree_menu = yOrg_btn_qtsy+cyBtn+cyGapBtn;
            yOrg_btn_spgl = yOrg_tree_menu+cyTree+cyGapTree;
            break;

        case SB_BTN_SPGL:
            yOrg_btn_qtsy = yOrg+cyBtn+cyGapBtn;
            yOrg_btn_spgl = yOrg_btn_qtsy+cyBtn+cyGapBtn;
            yOrg_tree_menu = yOrg_btn_spgl+cyBtn+cyGapBtn;
            break;

        default:
            break;
    }

    m_btn_spwh.MoveWindow(xOrg, yOrg, cx, cyBtn);
    m_btn_qtsy.MoveWindow(xOrg, yOrg_btn_qtsy, cx, cyBtn);
    m_btn_spgl.MoveWindow(xOrg, yOrg_btn_spgl, cx, cyBtn);
    m_tree_menu.MoveWindow(xOrg, yOrg_tree_menu, cx, cyTree);
}

void CSidebarSheet::setMenu(int nIDClickedBtn) {
    m_tree_menu.DeleteAllItems();
    switch (nIDClickedBtn) {
        case SB_BTN_SPWH:
            m_tree_menu.InsertItem(_T("��Ʒά��"));
            break;

        case SB_BTN_QTSY:
            m_tree_menu.InsertItem(_T("�������"));
            break;

        case SB_BTN_SPGL:
           m_tree_menu.InsertItem(_T("����������Ʒ"));
           m_tree_menu.InsertItem(_T("�ۻ�Ա����"));
            break;

        default:
            break;
    }
}

BOOL CSidebarSheet::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    //�޸����οؼ���ʽ
    m_tree_menu.SetItemHeight(25);
    m_tree_menu.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CSidebarSheet::OnNMClickTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CPoint pt;
    UINT uFlag = 0;
    GetCursorPos(&pt);
    m_tree_menu.ScreenToClient(&pt);
    HTREEITEM hItemSel = m_tree_menu.GetSelectedItem();
    HTREEITEM hItemHistTest = m_tree_menu.HitTest(pt, &uFlag);

    if (hItemHistTest) {
        if (hItemHistTest == hItemSel) return;

        WPARAM wParam = 0;
        if (TVHT_ONITEM & uFlag) {
            CString strItemName = m_tree_menu.GetItemText(hItemHistTest);
            if (_T("��Ʒά��") == strItemName)
                wParam = SB_XPWH;
            else if (_T("�������") == strItemName)
                wParam = SB_GWJS;
            else if (_T("����������Ʒ") == strItemName)
                wParam = SB_DRMCSP;
            else if (_T("�ۻ�Ա����") == strItemName)
                wParam = SB_SHYGL;
        }
            
        ::SendMessage(GetParent()->GetSafeHwnd(), WM_SBMENUITEM, wParam, 0);
    }
    
    *pResult = 0;
}

void CSidebarSheet::OnTvnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //AfxMessageBox(m_tree_menu.GetItemText(pNMTreeView->itemNew.hItem));

    *pResult = 0;
}
