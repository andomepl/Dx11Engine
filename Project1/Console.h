#pragma once
#include<stdio.h>

#include<stdlib.h>
#include<Windows.h>
#include<string>

namespace Log {

	class Console {


	public:


		static void Write(std::string message) {
			 


			fprintf_s(outstream, message.c_str());


			//fclose(outstream);


		}


		static void Initalize() {

			AllocConsole();

			SetConsoleTitle(consoleTitle.c_str());


			_wfreopen_s(&instream, L"CONIN$", L"r+t", stdin);
			_wfreopen_s(&outstream, L"CONOUT$", L"r+t", stdout);








		}


		~Console() {



			fclose(instream);
			fclose(outstream);
			FreeConsole();

		}



	private:


		errno_t errorflag;



		static FILE* instream;

		static FILE* outstream;

		bool is_initalizeSucceed = false;

		static  const std::wstring consoleTitle;


	};

}
