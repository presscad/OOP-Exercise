// DailyGSalesSheet.cpp : ʵ���ļ�
//

#include "..\Framework\stdafx.h"
#include "..\Framework\ShoppingSystem.h"
#include "DailyGSalesSheet.h"
#include "..\BLL\GSalesManager.h"
#include "..\Entity\GSales.h"
#include "..\Tools\Tools.h"


// CDailyGSalesSheet �Ի���

IMPLEMENT_DYNAMIC(CDailyGSalesSheet, CDialog)

CDailyGSalesSheet::CDailyGSalesSheet(CWnd* pParent /*=NULL*/)
	: CDialog(CDailyGSalesSheet::IDD, pParent)
{

}

CDailyGSalesSheet::~CDailyGSalesSheet()
{
}

void CDailyGSalesSheet::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, DGS_LISTVIEW, m_listView);
}


BEGIN_MESSAGE_MAP(CDailyGSalesSheet, CDialog)
END_MESSAGE_MAP()


// CDailyGSalesSheet ��Ϣ�������

BOOL CDailyGSalesSheet::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��

    //ListView������ʽ
    m_listView.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CDailyGSalesSheet::queryData(void)
{
    m_listView.DeleteAllItems();
    GSalesManager gSalesMgr;
    CArray<GSales> *pArrayGSales = gSalesMgr.dailyGSales();
    for (int i = pArrayGSales->GetCount() - 1; i >= 0; --i) {
        GSales gsales(pArrayGSales->GetAt(i));
        m_listView.InsertItem(0, gsales.getGName());
        m_listView.SetItemText(0, 1, toCString(gsales.getGPrice()));
        m_listView.SetItemText(0, 2, toCString(gsales.getGNum()));
        m_listView.SetItemText(0, 3, toCString(gsales.getAllSNum()));
    }
    delete pArrayGSales;
}

void CDailyGSalesSheet::Init(void)
{
    //ListView�ڴ����е�λ��
    CRect rcClient;
    GetClientRect(&rcClient);
    int topLeftRightMargin = 5;
    int bottomMargin = 5;
    rcClient.left += topLeftRightMargin;
    rcClient.right -= topLeftRightMargin;
    rcClient.top += topLeftRightMargin;
    rcClient.bottom -= bottomMargin;
    m_listView.MoveWindow(&rcClient);


    //����ListView����
    while (m_listView.DeleteColumn(0));
    m_listView.InsertColumn(0, _T("����"), LVCFMT_LEFT, 80);
    m_listView.InsertColumn(0, _T("���"), LVCFMT_LEFT, 80);
    m_listView.InsertColumn(0, _T("����"), LVCFMT_LEFT, 80);
    m_listView.InsertColumn(0, _T("����"), LVCFMT_LEFT, 80);

    //��ѯ����
    queryData();
}
