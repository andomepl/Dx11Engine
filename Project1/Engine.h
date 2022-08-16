#pragma once

#include<memory>

#include"WindowWrap.h"
class Engine {





private:


	 std::unique_ptr<WindowWrap> windowwrap{std::make_unique<WindowWrap>()};





public :




	void WindowsContext(UINT32 num,void**);


	bool Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height);


	bool ProcessMessage();


};