
// ChatClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ChatSocket.h"


// CChatClientDlg �Ի���
class CChatClientDlg : public CDialogEx
{
// ����
public:
	CChatClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void OnDisconnect();
	void OnReceive();
	void OnClose();
	void OnConnect();
	CChatSocket m_sConnectSocket;

	enum { IDD = IDD_CHATCLIENT_DIALOG};


// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATCLIENT_DIALOG };
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
