// Windows 窗口编程核心文件，和ds123核心文件和头文件，以及com组件库 链接dx12核心dll

#include<Windows.h>
#include<d3d12.h>
#include<dxgi1_6.h>

#include<wrl.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")

using namespace Microsoft;
using namespace Microsoft::WRL;


class DX12Engine {
private:
	int WindowsWidth = 640;
	int WindowsHeight = 480;
	HWND m_hwnd;

public:
	void InitWindow(HINSTANCE hins) {

	}

	void RnderLoop() {

	}

	static LRESULT CALLBACK CallBackFunc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM) {

	}
	static void Run(HINSTANCE hins) {

	}
};

int WINAPI WinMain(HINSTANCE hins, HINSTANCE hPrev, LPSTR cmdLind, int cmdShow) {
	DX12Engine::Run(hins);
	return 0;
};