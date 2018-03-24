#include "clLib.hpp"

#ifdef WINDOWS_PLATFORM
constexpr const char *LIB_NAME = "OpenCL.dll";
#endif

#define CL_FUNC_IMPLEMENT_NULL(func) \
    decltype(::func)* cl::ClLib::func = nullptr;
#define CL_FUNC_IMPLEMENT(func) \
    func = _lib->loadFunction<decltype(::func)>(#func);

cl::ClLib* cl::ClLib::_instance = nullptr;
CL_FUNC_IMPLEMENT_NULL(clBuildProgram);
CL_FUNC_IMPLEMENT_NULL(clCloneKernel);
CL_FUNC_IMPLEMENT_NULL(clCompileProgram);
CL_FUNC_IMPLEMENT_NULL(clCreateBuffer);
CL_FUNC_IMPLEMENT_NULL(clCreateCommandQueue);
CL_FUNC_IMPLEMENT_NULL(clCreateCommandQueueWithProperties);
CL_FUNC_IMPLEMENT_NULL(clCreateCommandQueueWithPropertiesKHR);
CL_FUNC_IMPLEMENT_NULL(clCreateContext);

cl::ClLib::ClLib()
    : _lib(nullptr)
{}

cl::ClLib* cl::ClLib::instance()
{
    if (nullptr == _instance) {
        _instance = new ClLib();
    }
    return _instance;
}

bool cl::ClLib::initialize()
{
    _lib = new cl::lib_import::Lib(LIB_NAME);
    return _lib->isLoaded();
}

void cl::ClLib::uninitialize() const
{
    delete _lib;
}

void cl::ClLib::initializeFunctions() const
{
    CL_FUNC_IMPLEMENT(clBuildProgram);
    CL_FUNC_IMPLEMENT(clCloneKernel);
    CL_FUNC_IMPLEMENT(clCompileProgram);
    CL_FUNC_IMPLEMENT(clCreateBuffer);
    CL_FUNC_IMPLEMENT(clCreateCommandQueue);
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithProperties);
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithPropertiesKHR);
    CL_FUNC_IMPLEMENT(clCreateContext);
}

