// dllmain.h : 모듈 클래스의 선언입니다.

class CHelloWorldModule : public ATL::CAtlDllModuleT< CHelloWorldModule >
{
public :
	DECLARE_LIBID(LIBID_HelloWorldLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HELLOWORLD, "{9717CCDF-2E05-40E7-8571-E256CAA0BF2F}")
};

extern class CHelloWorldModule _AtlModule;
