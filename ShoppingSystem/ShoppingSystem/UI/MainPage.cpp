// ShoppingSystemDlg.cpp : ʵ���ļ�
//

#include "..\framework\stdafx.h"
#include "..\framework\ShoppingSystem.h"
#include "MainPage.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MainPage �Ի���




MainPage::MainPage(CWnd* pParent /*=NULL*/)
	: CDialog(MainPage::IDD, pParent),
    m_pQuerySheet(NULL), m_pDailyGSSheet(NULL),
    m_pCashierSheet(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

MainPage::~MainPage() {
    if (m_pQuerySheet) delete m_pQuerySheet;
    if (m_pDailyGSSheet) delete m_pDailyGSSheet;
    if (m_pCashierSheet) delete m_pCashierSheet;
}

void MainPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MainPage, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_MESSAGE(WM_SBMENUITEM, &MainPage::OnSidebarMenuItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// MainPage ��Ϣ�������

BOOL MainPage::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

    CRect rcClient;

    //���Ƶ�¼�����Ƿ�ɹ���¼
    CLoginDlg loginDlg;
    if (IDOK != loginDlg.DoModal()) {
        PostQuitMessage(0);
        return TRUE;
    }

    //�����û�Id��רָ�ۻ�Ա��
    m_userId = loginDlg.m_userId;

    //����״̬��
    m_statusBar.CreateEx(this);
    GetClientRect(&rcClient);
    UINT indicator[2] = {2000, 2001};
    m_statusBar.SetIndicators(indicator, sizeof(indicator)/sizeof(UINT));
    m_statusBar.SetPaneInfo(0, indicator[0], SBPS_STRETCH, 200);
    m_statusBar.SetPaneInfo(1, indicator[1], SBPS_STRETCH, 0);

    CString paneText = _T("��ǰ�û���") + loginDlg.m_userName + _T("��") + loginDlg.m_roleName + _T("��");
    m_statusBar.SetPaneText(0, _T("����"));
    m_statusBar.SetPaneText(1, paneText);

    m_statusBar.MoveWindow(rcClient.left, rcClient.bottom-20, rcClient.Width(), 20, FALSE);
    
    //���������
    m_sidebar.Create(IDD_SIDEBAR, this);
    GetClientRect(&rcClient);
    rcClient.right = 170;
    rcClient.bottom -= 20;
    m_sidebar.MoveWindow(&rcClient, FALSE);
    m_sidebar.ShowWindow(SW_NORMAL);

    //��ʼ�������
    int clickedBtnId;
    if (loginDlg.m_roleName == _T("����Ա")) {
        clickedBtnId = m_sidebar.m_btn_spwh.GetDlgCtrlID();
        m_sidebar.setMenu(clickedBtnId);
        m_sidebar.moveCtrl(clickedBtnId);
        m_sidebar.m_btn_qtsy.EnableWindow(FALSE);
    }
    else if (loginDlg.m_roleName == _T("�ۻ�Ա")) {
        clickedBtnId = m_sidebar.m_btn_qtsy.GetDlgCtrlID();
        m_sidebar.setMenu(clickedBtnId);
        m_sidebar.moveCtrl(clickedBtnId);
        m_sidebar.m_btn_spwh.EnableWindow(FALSE);
        m_sidebar.m_btn_spgl.EnableWindow(FALSE);
    }


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void MainPage::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR MainPage::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT MainPage::OnSidebarMenuItem(WPARAM wParam, LPARAM lParam)
{
    CRect rcClient;
    int cy;
    m_sidebar.GetClientRect(&rcClient);
    cy = rcClient.right;
    this->GetClientRect(&rcClient);
    rcClient.left = cy;
    rcClient.bottom -= 20;

    switch (wParam) {
        case SB_XPWH:
        case SB_SHYGL:
            if (m_pDailyGSSheet) {
                delete m_pDailyGSSheet;
                m_pDailyGSSheet = NULL;
            }
            if (m_pCashierSheet) {
                delete m_pCashierSheet;
                m_pCashierSheet = NULL;
            }
            if (!m_pQuerySheet) {
                m_pQuerySheet = new CQuerySheet;
                m_pQuerySheet->Create(IDD_QUERY, this);
                m_pQuerySheet->MoveWindow(&rcClient);
                m_pQuerySheet->ShowWindow(SW_NORMAL);
            }
            
            CQuerySheet::querySheetStyle sheetStyle;
            if (SB_XPWH == wParam) sheetStyle = CQuerySheet::sheetGoods;
            else if (SB_SHYGL == wParam) sheetStyle = CQuerySheet::sheetSalesman;
            
            m_pQuerySheet->Init(sheetStyle);

            break;

        case SB_GWJS:
            if (m_pQuerySheet) {
                delete m_pQuerySheet;
                m_pQuerySheet = NULL;
            }
            if (m_pDailyGSSheet) {
                delete m_pDailyGSSheet;
                m_pDailyGSSheet = NULL;
            }
            if (!m_pCashierSheet) {
                m_pCashierSheet = new CCashierSheet;
                m_pCashierSheet->Create(IDD_CASHIER, this);
                m_pCashierSheet->MoveWindow(&rcClient);
                m_pCashierSheet->ShowWindow(SW_NORMAL);
            }
            m_pCashierSheet->Init();
            break;

        case SB_DRMCSP:
            if (m_pQuerySheet) {
                delete m_pQuerySheet;
                m_pQuerySheet = NULL;
            }
            if (m_pCashierSheet) {
                delete m_pCashierSheet;
                m_pCashierSheet = NULL;
            }
            if (!m_pDailyGSSheet) {
                m_pDailyGSSheet = new CDailyGSalesSheet;
                m_pDailyGSSheet->Create(IDD_DAILYGSALES, this);
                m_pDailyGSSheet->MoveWindow(&rcClient);
                m_pDailyGSSheet->ShowWindow(SW_NORMAL);
            }
            m_pDailyGSSheet->Init();
            break;

        default: break;
    }

    return 0;
}

