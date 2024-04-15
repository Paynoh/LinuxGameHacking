#include "Utils.hpp"
namespace Utils
{
	uintptr_t GetModuleBaseAddress(const std::string& ProcessName)
	{
		std::ifstream MapsFile("/proc/self/maps");
    	std::string line;
		while (std::getline(MapsFile, line))
		{
			if (line.find(ProcessName) != std::string::npos)
			{
            	std::istringstream iss(line);
            	uintptr_t StartAddress;
            	iss >> std::hex >> StartAddress;
            	return StartAddress;
			}
    	}
    	return 0; // Base address not found
	}	
} // namespace Utils
