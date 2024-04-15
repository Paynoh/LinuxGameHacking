#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <istream>
#include <sstream>
#include <dlfcn.h>
#include "Utils.hpp"

void MainThread()
{
    using fnConsoleOut = bool(*)(int Type, ...);
    std::cout << "Hello from MainThread!\n";


	//asm("int3"); Testing 

    uintptr_t ModuleBaseAdress = Utils::GetModuleBaseAddress("linux_client");
    if (ModuleBaseAdress == 0)
    {
		std::cout << "Bad, NULL!\n";
    }


    fnConsoleOut ConsoleOut = reinterpret_cast<fnConsoleOut>(ModuleBaseAdress + 0x495A0);
    if(!ConsoleOut)
    {
        std::cout << "Call, NULL!\n";
    }

	std::cout << "Good " << std::hex << ModuleBaseAdress << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(5));
	ConsoleOut(0x400, "2Hacked!");

	std::this_thread::sleep_for(std::chrono::seconds(5));

	ConsoleOut(0xD, "Hacked!");
	std::cout << "Called\n";
}

// Entry point function that will be called when the shared object is loaded
extern "C" __attribute__((constructor)) void EntryPoint()
{
	
    std::thread t(MainThread);
    t.detach();
}

// Function to detach the thread when the shared object is unloaded
extern "C" __attribute__((destructor)) void Destroy()
{


}