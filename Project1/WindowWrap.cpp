#include"WindowWrap.h"


Console WindowWrap::console;


LRESULT WindowWrap::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {


	OutputDebugStringW(L"Window Proc From Window Container\n");
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}