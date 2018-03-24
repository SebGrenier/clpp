#include "clUtils.hpp"
#include "clLib.hpp"

bool cl::initLibrary()
{
    auto *clLib = ClLib::instance();
    const auto success = clLib->initialize();
	return success;
}

bool cl::freeLibrary()
{
    auto *clLib = ClLib::instance();
    clLib->uninitialize();
	return true;
}
