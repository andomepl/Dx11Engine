#pragma once

#include"RenderWindow.h"

#include<functional>

class WindowWrap {

public :
	 RenderWindow& Get_RenderWindow()  {


		return render_window;
		
	}


	 HINSTANCE Get_HINSTANCE() {

		 return render_window.GetHinstance();

	 }


	 std::pair<RenderWindow::WIDTH,RenderWindow::HEIGHT>Get_Screen() {
		 return render_window.Get_Screen();
	 }



protected:

	RenderWindow render_window;

};