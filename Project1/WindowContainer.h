#pragma once
#include"RenderWindow.h"
class WindowContainer {

public :
	 RenderWindow& Get_RenderWindow()  {


		return render_window;
		
	}





protected:

	RenderWindow render_window;

};