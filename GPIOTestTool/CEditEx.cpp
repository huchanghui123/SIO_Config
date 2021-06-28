#include "pch.h"
#include "CEditEx.h"

//ֻ��������16�����ַ���
BOOL CEditEx::PreTranslateMessage(MSG* pMsg)
{
	if (WM_CHAR == pMsg->message)
	{
		if (pMsg->wParam == VK_BACK)//��Ӧback��
			return CEdit::PreTranslateMessage(pMsg);
		TCHAR ch = (TCHAR)pMsg->wParam;
		if ((ch >= '0' && ch <= '9'))
			return CEdit::PreTranslateMessage(pMsg);
		if ((ch >= 'A' && ch <= 'F'))
			return CEdit::PreTranslateMessage(pMsg);
		if ((ch >= 'a' && ch <= 'f'))
			return CEdit::PreTranslateMessage(pMsg);
		return TRUE;
	}
	return CEdit::PreTranslateMessage(pMsg);
}