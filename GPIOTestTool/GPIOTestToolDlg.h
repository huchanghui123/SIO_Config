
// GPIOTestToolDlg.h: 头文件
//

#pragma once
#include "GPIOTool.h"
#include "CEditEx.h"

// CGPIOTestToolDlg 对话框
class CGPIOTestToolDlg : public CDialog
{
// 构造
public:
	CGPIOTestToolDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPIOTESTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	GPIOTool m_gpio;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEditEx sfEdit1;
	CEditEx sfEdit2;
	CEditEx regEdit;
	CEditEx regFunEdit;
	CEditEx outEdit;
	CEditEx outFunEdit;
	CEditEx pinEdit;
	CEditEx pinFunEdit;
	afx_msg void SetRegFunctionClick();
	afx_msg void SetPinPolClick();
	CEditEx redEdit;
	afx_msg void ReadRegValue();
	afx_msg void SetSFRClick();
	CEditEx sfrEdit;
	CEditEx sfrFunEdit;
};
