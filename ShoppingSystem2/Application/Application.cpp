#include "stdafx.h"
#include "..\UIL\UIL.h"

int APIENTRY _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd )
{
    //��ʼ��COM
    if (!AfxOleInit()) {
        AfxMessageBox(_T("COM��ʼ������"));
        return -1;
    }

    showWnd();
    return 0;
}