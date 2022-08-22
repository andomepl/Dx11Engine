#pragma once
#include"ErrorLogger.h"

#include<utility>
#include<vector>
#include<iostream>

//#include<string>

class WindowWrap;


class RenderWindow {

public:

	using WIDTH = UINT;

	using HEIGHT = UINT;


	bool Initalize(WindowWrap* pWindowContainer,HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height);


	HWND GetHandle()const noexcept{ return handle; }


	HINSTANCE GetHinstance() const noexcept { return hInstance; }

	std::pair<WIDTH, HEIGHT> Get_Screen()const noexcept {

		return std::pair<WIDTH, HEIGHT>{width, height};
	}

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

	int width{ 0 };
	int height{ 0 };

};