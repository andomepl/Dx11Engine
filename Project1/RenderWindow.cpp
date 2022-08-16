#include"RenderWindow.h"


bool RenderWindow::Initalize(WindowWrap* pWindowContainer,HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {


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
		NULL




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


	ZeroMemory(&msg,sizeof(MSG));

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

std::vector<std::string> eventbuffer;

template<typename T>
void EventTest(UINT num = 0, void* ptr = nullptr) {

	for (UINT i = 0; i < num; i++) {





		eventbuffer.push_back(std::string{ static_cast<char*>(ptr)});

		
	}


}




LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_NCCREATE: {
		OutputDebugStringA("Tthe windos carea.\n");


		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
	default:
		DefWindowProc(hwnd, uMsg, wParam, lParam);



	}


}


void RenderWindow::RegisterWindowClass() {

	WNDCLASSEX wc;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	wc.lpfnWndProc = WindowProc;

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

