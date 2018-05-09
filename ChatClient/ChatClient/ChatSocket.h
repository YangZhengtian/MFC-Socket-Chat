#pragma once

// CChatSocket ÃüÁîÄ¿±ê
class CChatClientDlg;

class CChatSocket : public CAsyncSocket
{
public:
	CChatSocket();
	virtual ~CChatSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//void SetParent();
	void SetParent(CChatClientDlg * pDlg);
private:
	CChatClientDlg * m_pDlg;
public:
	//CChatSocket m_sConnectSocket;
	void OnClose();
	void OnConnect();
	void OnReceive();
};


