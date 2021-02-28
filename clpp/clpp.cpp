#include "clpp.hpp"
#include "clApi.hpp"

bool cl::initLibrary()
{
    auto *clLib = ClApi::instance();
    const auto success = clLib->initialize();
	return success;
}

bool cl::freeLibrary()
{
    auto *clLib = ClApi::instance();
    clLib->uninitialize();
	return true;
}
