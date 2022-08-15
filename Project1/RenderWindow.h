#pragma once
#include"ErrorLogger.h"

class RenderWindow {

public:
	bool Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height);


	HWND GetHandle()const noexcept{ return handle; };


	bool ProcessMessages();

	~RenderWindow();


private:

	void RegisterWindowClass();

	HWND handle = NULL;

	HINSTANCE hInstance = NULL;

	std::string window_title = "";
	std::wstring window_title_wide = L"";

	std::string window_class = "";

	std::wstring window_class_wide = L"";

	int width = 0;
	int height = 0;

};