#include<Windows.h>

#pragma comment(lib,"d3d11.lib")

#pragma comment(lib,"DirectXTK.lib")


#include<iostream>

#include"Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow) {


	Engine engine;

	engine.Initalize(hInstance, "title", "MyWindowClass", 800, 600);

	while (engine.ProcessMessage()) {

		
	}




	return 0;


}