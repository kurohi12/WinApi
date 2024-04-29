#pragma once
class CCore
{
public:
	//╫л╠шео
	static CCore* GetInstance() {
		if (nullptr == g_Inst) {
			g_Inst = new CCore;
		}

		return g_Inst;
	}

	static void Release() {
		if (nullptr != g_Inst) {
			delete g_Inst;
			g_Inst = nullptr;
		}
	}


private:
	static CCore* g_Inst;
	CCore();
	~CCore();
};

