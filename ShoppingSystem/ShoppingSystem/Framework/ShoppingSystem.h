// ShoppingSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CShoppingSystemApp:
// �йش����ʵ�֣������ ShoppingSystem.cpp
//

class CShoppingSystemApp : public CWinApp
{
public:
	CShoppingSystemApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CShoppingSystemApp theApp;