#include"Engine.h"

bool Engine::Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {

	if (windowwrap != nullptr) {

		return 	windowwrap->Get_RenderWindow().Initalize(windowwrap.get(), hInstace, window_title, window_class, width, height);
	}
	
	return false;

}

bool Engine::ProcessMessage() {


	return windowwrap->Get_RenderWindow().ProcessMessages();
}