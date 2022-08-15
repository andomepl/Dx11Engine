#pragma once

#include<memory>

#include"WindowContainer.h"
class Engine {





private:


	 std::unique_ptr<WindowContainer> windowcontainer{std::make_unique<WindowContainer>()};


public :
	bool Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height);


	bool ProcessMessage();


};