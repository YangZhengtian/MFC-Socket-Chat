
// ChatServerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ChatSocket.h"


// CChatServerDlg 对话框
class CChatServerDlg : public CDialogEx
{
// 构造
public:
	void OnClose();
	void OnAccept();
	void OnReceive();
	CChatSocket m_sListenSocket;
	CChatSocket m_sConnectSocket;
	CChatServerDlg(CWnd* pParent = NULL);	// 标准构造函数

	enum{IDD=IDD_CHATSERVER_DIALOG};

	CString m_ServerName;
	int m_ServerPort;
	CString m_SendMsg;
	CListBox m_Msg;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATSERVER_DIALOG };
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
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonSend();
	afx_msg void OnButtonExit();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLbnSelchangeListMsg();
};
