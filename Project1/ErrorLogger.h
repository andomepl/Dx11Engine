#pragma once
#include"StringConverter.h"
#include<Windows.h>

#include<ostream>
#include<istream>

class ErrorLogger {


public :


	static void Log(std::string message);

	//static void Log(std::string& message);

	//static void Log(std::string&& message);

	static void Log(HRESULT hr, std::string message);

};