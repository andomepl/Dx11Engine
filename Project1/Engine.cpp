#include"Engine.h"

bool Engine::Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {


	ErrorLogger Debug;
	if (windowwrap != nullptr) {

		auto WindowWrapStatus=windowwrap->Initalize(windowwrap.get(), hInstace, window_title, window_class, width, height);

		auto WindowWrapStatusLambda = [&]()->std::string&& {return WindowWrapStatus.second ? WindowWrapStatus.first+"Status : {Success} " : WindowWrapStatus.first + "Status : {Failed} "; };


		std::cout << WindowWrapStatusLambda() << std::endl;

		return 	WindowWrapStatus.second;
	}
	
	return false;

}

bool Engine::ProcessMessage() {


	return windowwrap->Get_RenderWindow().ProcessMessages();
}