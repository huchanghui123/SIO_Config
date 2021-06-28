
// GPIOTestToolDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "GPIOTestTool.h"
#include "GPIOTestToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGPIOTestToolDlg 对话框
CGPIOTestToolDlg::CGPIOTestToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_GPIOTESTTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGPIOTestToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, SF_ET_01, sfEdit1);
	sfEdit1.SetLimitText(2);
	DDX_Control(pDX, SF_ET_02, sfEdit2);
	sfEdit2.SetLimitText(2);
	DDX_Control(pDX, reg01, regEdit);
	regEdit.SetLimitText(2);
	DDX_Control(pDX, reg_fun_01, regFunEdit);
	regFunEdit.SetLimitText(2);
	DDX_Control(pDX, out01, outEdit);
	outEdit.SetLimitText(2);
	DDX_Control(pDX, out_fun_01, outFunEdit);
	outFunEdit.SetLimitText(2);
	DDX_Control(pDX, pin01, pinEdit);
	pinEdit.SetLimitText(2);
	DDX_Control(pDX, pin_fun_01, pinFunEdit);
	pinFunEdit.SetLimitText(2);
	DDX_Control(pDX, RD_REG1, redEdit);

	DDX_Control(pDX, SFR_IDC, sfrEdit);
	DDX_Control(pDX, SFR_VAL_IDC, sfrFunEdit);
	sfrEdit.SetLimitText(4);
	sfrFunEdit.SetLimitText(2);
}

BEGIN_MESSAGE_MAP(CGPIOTestToolDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(SF_BUTTON1, &CGPIOTestToolDlg::OnBnClickedButton1)
	ON_BN_CLICKED(GP_M_BTN1, &CGPIOTestToolDlg::SetRegFunctionClick)
	ON_BN_CLICKED(GP_P_BTN1, &CGPIOTestToolDlg::SetPinPolClick)
	ON_BN_CLICKED(IDC_BUTTON1, &CGPIOTestToolDlg::ReadRegValue)
	ON_BN_CLICKED(IDC_BUTTON2, &CGPIOTestToolDlg::SetSFRClick)
END_MESSAGE_MAP()


// CGPIOTestToolDlg 消息处理程序

BOOL CGPIOTestToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	int chip_name = m_gpio.GetChipName();
	CString name;
	name.Format(_T("IT%04x"), chip_name);
	SetDlgItemText(IDC_STATIC, name);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGPIOTestToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGPIOTestToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGPIOTestToolDlg::OnBnClickedButton1()
{
	CString str1;
	CString str2;
	sfEdit1.GetWindowTextW(str1);
	sfEdit2.GetWindowTextW(str2);
	//AfxMessageBox(str1 +" "+ str2);	
	byte reg = wcstol(str1, NULL, 16);
	byte val = wcstol(str2, NULL, 16);
	m_gpio.MyWriteIoPortByte(reg, val);
}


void CGPIOTestToolDlg::SetRegFunctionClick()
{
	//配置寄存器
	CString rStr;
	CString rvStr;
	regEdit.GetWindowTextW(rStr);
	regFunEdit.GetWindowTextW(rvStr);
	byte reg1 = wcstol(rStr, NULL, 16);
	byte val1 = wcstol(rvStr, NULL, 16);
	m_gpio.MyWriteIoPortByte(reg1, val1);

	//配置寄存器功能
	CString oStr;
	CString ovStr;
	outEdit.GetWindowTextW(oStr);
	outFunEdit.GetWindowTextW(ovStr);
	byte reg2 = wcstol(oStr, NULL, 16);
	byte val2 = wcstol(ovStr, NULL, 16);
	m_gpio.MyWriteIoPortByte(reg2, val2);
}


void CGPIOTestToolDlg::SetPinPolClick()
{
	//配置引脚电压
	CString pStr;
	CString pvStr;
	pinEdit.GetWindowTextW(pStr);
	pinFunEdit.GetWindowTextW(pvStr);
	WORD reg = wcstol(pStr, NULL, 16);
	byte val = wcstol(pvStr, NULL, 16);
	m_gpio.MyWriteIoPortByte(reg, val);
}


void CGPIOTestToolDlg::ReadRegValue()
{
	//读取寄存器
	CString rStr;
	redEdit.GetWindowTextW(rStr);
	byte reg = wcstol(rStr, NULL, 16);
	BYTE reg_val = m_gpio.MyReadIoPortByte(reg);
	CString str;
	str.Format(_T("0x%x"), reg_val);
	SetDlgItemText(RED_VALUE, str);
}


void CGPIOTestToolDlg::SetSFRClick()
{
	
	CString rStr;
	sfrEdit.GetWindowTextW(rStr);
	WORD reg = wcstol(rStr, NULL, 16);
	CString pStr;
	sfrFunEdit.GetWindowTextW(pStr);
	byte val = wcstol(pStr, NULL, 16);
	m_gpio.MyWriteIoPortByteEx(reg, val);
	
}
