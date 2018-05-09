
// ChatClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatClientDlg 对话框



CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHATCLIENT_DIALOG, pParent)
	, m_ServerName(_T(""))
	, m_ServerPort(0)
	, m_SendMsg(_T(""))
{
	m_ServerName = _T("");
	m_SendMsg = _T("");
	m_ServerPort = 0;
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SERVERNAME, m_ServerName);
	DDX_Text(pDX, IDC_EDIT_SERVERPORT, m_ServerPort);
	DDX_Text(pDX, IDC_EDIT_SENDMSG, m_SendMsg);
	DDX_Control(pDX, IDC_LIST_MSG, m_Msg);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CChatClientDlg::OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CChatClientDlg::OnButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CChatClientDlg::OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatClientDlg::OnButtonSend)
END_MESSAGE_MAP()


// CChatClientDlg 消息处理程序

BOOL CChatClientDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_ServerName = "localhost";
	m_ServerPort = 3030;
	UpdateData(FALSE);
	m_sConnectSocket.SetParent(this);

	GetDlgItem(IDC_EDIT_SENDMSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);

	//ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatClientDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChatClientDlg::OnButtonConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVERNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVERPORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(TRUE);
	m_sConnectSocket.Create();
	m_sConnectSocket.Connect(m_ServerName, m_ServerPort);


}


void CChatClientDlg::OnButtonDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	OnClose();
}


void CChatClientDlg::OnButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void CChatClientDlg::OnButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
	int nLen=0;
	int nSent=0;
	UpdateData(TRUE);
	if (!m_SendMsg.IsEmpty())
	{
		//int nLen;
		char * wsabuf = NULL;
#ifdef _UNICODE
		//CString转换成char*
		USES_CONVERSION;
		wsabuf = W2A(m_SendMsg);//m_strMsg为CString消息
		nLen = strlen(wsabuf);
		nSent = m_sConnectSocket.Send(wsabuf, nLen);//发送数据
#else
		nLen = m_strMsg.GetLength();
		nSent = m_sConnectSocket.Send(LPCTSTR(m_SendMsg), nLen);//发送数据
#endif
		//nLen = m_SendMsg.GetLength();
		//nSent = m_sConnectSocket.Send(LPCTSTR(m_SendMsg), nLen);
		if (nSent != SOCKET_ERROR)
		{
			CTime  time = CTime::GetCurrentTime();
			CString m_Time = time.Format("%Y-%m-%d %H:%M:%S");
			m_Msg.AddString(m_Time);
			m_Msg.AddString(_T("Client：")+m_SendMsg);
			UpdateData(FALSE);

		}
		else {
			AfxMessageBox(_T("发送失败！"), MB_OK | MB_ICONSTOP);
		}
		m_SendMsg.Empty();
		UpdateData(FALSE);

	}
}

void CChatClientDlg::OnConnect()
{
	GetDlgItem(IDC_EDIT_SENDMSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	m_Msg.AddString(_T("与服务器的通信连接已经建立"));

}

void CChatClientDlg::OnClose()
{
	m_sConnectSocket.Close();
	GetDlgItem(IDC_EDIT_SENDMSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(FALSE);
	while (m_Msg.GetCount() != 0)
		m_Msg.DeleteString(0);
	GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SERVERNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SERVERPORT)->EnableWindow(TRUE);
}

void CChatClientDlg::OnReceive()
{
	char * pBuf = new char[1025];
	int nBufSize = 1024;
	int nReceived;
	CString strReceived;
	nReceived = m_sConnectSocket.Receive(pBuf, nBufSize,0);
	if (nReceived != SOCKET_ERROR)
	{
		pBuf[nReceived] = NULL;
		strReceived = pBuf;
		CTime  time = CTime::GetCurrentTime();
		CString m_Time = time.Format("%Y-%m-%d %H:%M:%S");
		m_Msg.AddString(m_Time);
		m_Msg.AddString(_T("Server：")+strReceived);
		UpdateData(FALSE);

	}
	else {
		AfxMessageBox(_T("接收失败！"), MB_OK | MB_ICONSTOP);
	}
}