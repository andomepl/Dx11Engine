#include"Console.h"


FILE* Log::Console::instream=nullptr;
FILE* Log::Console::outstream = nullptr;

const std::wstring Log::Console::consoleTitle= L"Dx11 Engine Status";