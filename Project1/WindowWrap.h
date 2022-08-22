#pragma once

#include"RenderWindow.h"

#include<functional>

#include"Console.h"

using Log::Console;

class WindowWrap {




public :
	inline RenderWindow& Get_RenderWindow()  {


		return render_window;
		
	}


	void CreateConsole() {

		 
		console.Initalize();

		console.Write("test\n");

	}



	 std::pair<std::string,bool>  Initalize(WindowWrap* pWindowWarp,HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {

		 CreateConsole();



		 bool windowInitalize = render_window.Initalize(pWindowWarp, hInstace, window_title, window_class, width, height);

		 return { CompoentName ,windowInitalize };
		  

	 }


	 LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


private:

	std::string CompoentName{ "WindowWarp" };


	RenderWindow render_window;

	
	Console console;
};