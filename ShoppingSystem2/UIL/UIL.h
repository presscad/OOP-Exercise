// UIL.h : UIL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUILApp
// �йش���ʵ�ֵ���Ϣ������� UIL.cpp
//

class CUILApp : public CWinApp
{
public:
	CUILApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


int showWnd();

HICON getIcon();
