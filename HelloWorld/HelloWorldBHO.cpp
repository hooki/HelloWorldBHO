// HelloWorldBHO.cpp : CHelloWorldBHO의 구현입니다.

#include "stdafx.h"
#include "HelloWorldBHO.h"


// CHelloWorldBHO
STDMETHODIMP CHelloWorldBHO::SetSite(IUnknown *pUnkSite)
{
	if (pUnkSite != NULL)
	{
		HRESULT hr = pUnkSite->QueryInterface(IID_IWebBrowser2, (void **)&m_spWebBrowser);
		if (SUCCEEDED(hr))
		{
			hr = DispEventAdvise(m_spWebBrowser);
			if (SUCCEEDED(hr))
			{
				m_fAdvised = TRUE;
			}
		}
	}
	else
	{
		if (m_fAdvised)
		{
			DispEventUnadvise(m_spWebBrowser);
			m_fAdvised = FALSE;
		}
		m_spWebBrowser.Release();
	}

	return IObjectWithSiteImpl<CHelloWorldBHO>::SetSite(pUnkSite);
}

void STDMETHODCALLTYPE CHelloWorldBHO::OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL)
{
	HWND hwnd;
	HRESULT hr = m_spWebBrowser->get_HWND((LONG_PTR *)&hwnd);
	if (SUCCEEDED(hr))
	{
		MessageBox(hwnd, L"Hello World!", L"BHO", MB_OK);
	}
}