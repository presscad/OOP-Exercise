// UIL.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "UIL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CUILApp

BEGIN_MESSAGE_MAP(CUILApp, CWinApp)
END_MESSAGE_MAP()


// CUILApp ����

CUILApp::CUILApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CUILApp ����

CUILApp theApp;


// CUILApp ��ʼ��

BOOL CUILApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int showWnd() {

    AFX_MANAGE_STATE(AfxGetStaticModuleState());  //����Ӵ˾���룬��exe��dll���л���Դ���
    MainPage mainPage;
    return mainPage.DoModal();
}

