// ChatSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ChatSocket.h"
#include "ChatServerDlg.h"


// CChatSocket

CChatSocket::CChatSocket()
	: m_pDlg(NULL)
{
	m_pDlg = NULL;
}

CChatSocket::~CChatSocket()
{
	m_pDlg = NULL;
}

# if 0
BEGIN_MESSAGE_MAP(CChatSocket,CAsyncSocket)
END_MESSAGE_MAP
# endif


// CChatSocket 成员函数


void CChatSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnAccept();
	//CAsyncSocket::OnAccept(nErrorCode);
}


void CChatSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnReceive();
	//CAsyncSocket::OnReceive(nErrorCode);
}


void CChatSocket::SetParent(CChatServerDlg * pDlg)
{
	m_pDlg = pDlg;
}
