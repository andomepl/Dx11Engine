#pragma once
#include<stdio.h>

#include<stdlib.h>
#include<Windows.h>
#include<string>

namespace Log {

	class Console {


	public:


		void Write(std::string message) {



			fprintf_s(outstream, message.c_str());


			fclose(outstream);


		}


		void Initalize() {

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



		FILE* instream = nullptr;

		FILE* outstream = nullptr;

		bool is_initalizeSucceed = false;

		const std::wstring consoleTitle{ L"Dx11Engine Debug" };


	};

}