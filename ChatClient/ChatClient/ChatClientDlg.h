
// ChatClientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ChatSocket.h"


// CChatClientDlg 对话框
class CChatClientDlg : public CDialogEx
{
// 构造
public:
	CChatClientDlg(CWnd* pParent = NULL);	// 标准构造函数
	void OnDisconnect();
	void OnReceive();
	void OnClose();
	void OnConnect();
	CChatSocket m_sConnectSocket;

	enum { IDD = IDD_CHATCLIENT_DIALOG};


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonDisconnect();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonSend();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ServerName;
	int m_ServerPort;
	CString m_SendMsg;
	CListBox m_Msg;
	
};
