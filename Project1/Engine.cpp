#include"Engine.h"

bool Engine::Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {

	if (windowcontainer != nullptr) {

		return 	windowcontainer->Get_RenderWindow().Initalize(windowcontainer.get(), hInstace, window_title, window_class, width, height);
	}
	
	return false;

}

bool Engine::ProcessMessage() {


	return windowcontainer->Get_RenderWindow().ProcessMessages();
}