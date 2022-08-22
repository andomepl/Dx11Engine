#include"WindowWrap.h"


LRESULT WindowWrap::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {



	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}