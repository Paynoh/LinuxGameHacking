#include <thread>
#include <fstream>
#include <istream>
#include <sstream>
#include <dlfcn.h>
#pragma once
namespace Utils
{
    uintptr_t GetModuleBaseAddress(const std::string& ProcessName);
} // namespace Utils
