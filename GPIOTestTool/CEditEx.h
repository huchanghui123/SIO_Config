#pragma once
#include <afxwin.h>
class CEditEx :
	public CEdit
{
	BOOL PreTranslateMessage(MSG* pMsg);
};

