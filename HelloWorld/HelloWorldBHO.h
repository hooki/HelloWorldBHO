// HelloWorldBHO.h : CHelloWorldBHO�� �����Դϴ�.

#pragma once
#include <ShlGuid.h>
#include <ExDispid.h>	// DISPID_DOCUMENTCOMPLETE, etc.
#include "resource.h"       // �� ��ȣ�Դϴ�.



#include "HelloWorld_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "���� ������ COM ��ü�� ��ü DCOM ������ �������� �ʴ� Windows Mobile �÷����� ���� Windows CE �÷������� ����� �������� �ʽ��ϴ�. ATL�� ���� ������ COM ��ü�� ������ �����ϰ� ���� ������ COM ��ü ������ ����� �� �ֵ��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA�� �����Ͻʽÿ�. rgs ������ ������ ���� DCOM Windows CE�� �ƴ� �÷������� �����Ǵ� ������ ������ ���̹Ƿ� 'Free'�� �����Ǿ� �ֽ��ϴ�."
#endif

using namespace ATL;


// CHelloWorldBHO

class ATL_NO_VTABLE CHelloWorldBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelloWorldBHO, &CLSID_HelloWorldBHO>,
	public IObjectWithSiteImpl<CHelloWorldBHO>,
	public IDispatchImpl<IHelloWorldBHO, &IID_IHelloWorldBHO, &LIBID_HelloWorldLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<1, CHelloWorldBHO, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1>
{
public:
	CHelloWorldBHO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLOWORLDBHO)

DECLARE_NOT_AGGREGATABLE(CHelloWorldBHO)

BEGIN_COM_MAP(CHelloWorldBHO)
	COM_INTERFACE_ENTRY(IHelloWorldBHO)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SetSite)(IUnknown *pUnkSite);

	BEGIN_SINK_MAP(CHelloWorldBHO)
		SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOCUMENTCOMPLETE, OnDocumentComplete)
	END_SINK_MAP()

	void STDMETHODCALLTYPE OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL);


private:
	CComPtr<IWebBrowser2> m_spWebBrowser;
	BOOL m_fAdvised;
};

OBJECT_ENTRY_AUTO(__uuidof(HelloWorldBHO), CHelloWorldBHO)
