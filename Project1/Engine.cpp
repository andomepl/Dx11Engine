#include"Engine.h"


bool Engine::Initalize(HINSTANCE hInstace, std::string window_title, std::string window_class, int width, int height) {


	


		auto WindowWrapStatus=windowwrap->Initalize(windowwrap.get(), hInstace, window_title, window_class, width, height);

		auto WindowWrapStatusLambda = [&]()->std::string {return WindowWrapStatus.second ? WindowWrapStatus.first+"Status : {Initalize Success} " : WindowWrapStatus.first + "Status : {Failed} "; };


		windowwrap->Getconsole().Write(WindowWrapStatusLambda());

	

		return 	WindowWrapStatus.second;
	


}

bool Engine::ProcessMessage() {


	return windowwrap->Get_RenderWindow().ProcessMessages();
}

void Engine::Upadte() {



}