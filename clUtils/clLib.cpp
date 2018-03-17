#include "clLib.hpp"

#ifdef WINDOWS_PLATFORM
constexpr const char *LIB_NAME = "OpenCL.dll";
#endif

cl::ClLib::ClLib()
    : _lib(nullptr)
{
    _lib = new cl::lib_import::Lib(LIB_NAME);
}

cl::ClLib::~ClLib()
{
    delete _lib;
}


