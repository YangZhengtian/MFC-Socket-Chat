
// ChatServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ChatSocket.h"


// CChatServerDlg �Ի���
class CChatServerDlg : public CDialogEx
{
// ����
public:
	void OnClose();
	void OnAccept();
	void OnReceive();
	CChatSocket m_sListenSocket;
	CChatSocket m_sConnectSocket;
	CChatServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

	enum{IDD=IDD_CHATSERVER_DIALOG};

	CString m_ServerName;
	int m_ServerPort;
	CString m_SendMsg;
	CListBox m_Msg;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
