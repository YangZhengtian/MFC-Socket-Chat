// ChatSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatSocket.h"
#include "ChatClientDlg.h"


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
BEGIN_MESSAGE_MAP(CChatSocket, CAsyncMonikerFile)
{

}

END_MESSAGE_MAP()
# endif

// CChatSocket 成员函数


void CChatSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnClose();


	//CAsyncSocket::OnClose(nErrorCode);
}


void CChatSocket::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnConnect();

	//CAsyncSocket::OnConnect(nErrorCode);
}


void CChatSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnReceive();
	//CAsyncSocket::OnReceive(nErrorCode);
}


void CChatSocket::SetParent(CChatClientDlg * pDlg)
{
	m_pDlg = pDlg;
}


void CChatSocket::OnClose()
{
}


void CChatSocket::OnConnect()
{
}


void CChatSocket::OnReceive()
{
}
