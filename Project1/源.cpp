#include<Windows.h>

#pragma comment(lib,"d3d11.lib")

#pragma comment(lib,"DirectXTK.lib")


#include<iostream>

#include"RenderWindow.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow) {


	RenderWindow rw;

	rw.Initalize(hInstance, "Title", "My WindowClass", 800, 600);






	return 0;


}