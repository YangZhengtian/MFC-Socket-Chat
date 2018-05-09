#pragma once
class CChatServerDlg;
// CChatSocket ÃüÁîÄ¿±ê

class CChatSocket : public CAsyncSocket
{
public:
	CChatSocket();
	virtual ~CChatSocket();
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void SetParent(CChatServerDlg * pDlg);
private:
	CChatServerDlg * m_pDlg;
};


