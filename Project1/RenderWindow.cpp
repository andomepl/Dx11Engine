#include"RenderWindow.h"
#include"WindowWrap.h"

bool RenderWindow::Initalize(WindowWrap* pWindowCWarp,HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {


	hInstace = hInstace;
	this->width = width;
	this->height = height;

	this->window_title = window_title;
	this->window_class = window_class;

	this->window_class_wide = StringConverter::StringToWide(window_class);

	this->window_title_wide = StringConverter::StringToWide(window_title);


	RegisterWindowClass();



	this->handle = CreateWindowEx(0,
		this->window_class_wide.c_str(),
		this->window_title_wide.c_str(),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		0,
		0,
		this->width,
		this->height,
		NULL,
		NULL,
		this->hInstance,
		pWindowCWarp




	);

	if (this->handle == NULL) {

		ErrorLogger::Log(GetLastError(), "CreateWindowEx Failed for window: " + this->window_title);
		return false;
	}

	ShowWindow(this->handle, SW_SHOW);

	SetForegroundWindow(this->handle);
	SetFocus(this->handle);

	return true;

}



RenderWindow::~RenderWindow() {

	if (this->handle != NULL) {

		UnregisterClass(this->window_class_wide.c_str(), this->hInstance);

		DestroyWindow(handle);
	}

}
bool RenderWindow::ProcessMessages() {

	MSG msg;



	memset(&msg, 0, sizeof(MSG));


	if (PeekMessage(
		&msg,
		this->handle,
		0,
		0,
		PM_REMOVE

	)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (msg.message == WM_NULL) {

		if (!IsWindow(this->handle)) {

			this->handle = NULL;
			UnregisterClass(this->window_class_wide.c_str(), this->hInstance);
			return false;
		}


	}


	return true;

}



LRESULT CALLBACK HandleMsgRedirect(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {




	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;


	default: {
		WindowWrap* const windowWrap = reinterpret_cast<WindowWrap*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));


		return windowWrap->WindowProc(hwnd, uMsg, wParam, lParam);

	}
		
	}
}





LRESULT CALLBACK HandleMessageSetup(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_NCCREATE: {

		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);

		WindowWrap* pWindow = reinterpret_cast<WindowWrap*>(pCreate->lpCreateParams);


		if (pWindow == nullptr) {

			Log::Console::Write("Critical Error: Pointer to window container is null during WM_NCCREATE");

		//	ErrorLogger::Log("Critical Error: Pointer to window container is null during WM_NCCREATE");

			exit(-1);

		}


		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));

		//WindowWrap* const pWindow = reinterpret_cast<WindowWrap*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

		SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(HandleMsgRedirect));




		return pWindow->WindowProc(hwnd,uMsg,wParam,lParam);


		//return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
	default:
		DefWindowProc(hwnd, uMsg, wParam, lParam);



	}


}


void RenderWindow::RegisterWindowClass() {

	WNDCLASSEX wc;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	wc.lpfnWndProc = HandleMessageSetup;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = this->window_class_wide.c_str();
	wc.hIconSm = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);

}

