#include "clApi.hpp"
#include "libImport/lib.hpp"

// Global instance of the imported library
cl::lib_import::Lib *LIB = nullptr;

#ifdef WINDOWS_PLATFORM
constexpr const char *LIB_NAME = "OpenCL.dll";
#endif


#define CL_FUNC_IMPLEMENT(func) \
    func = LIB->loadFunction<decltype(::func)>(#func);

cl::ClApi* cl::ClApi::_instance = nullptr;


cl::ClApi* cl::ClApi::instance()
{
    if (nullptr == _instance) {
        _instance = new ClApi();
    }
    return _instance;
}

bool cl::ClApi::initialize()
{
    LIB = new cl::lib_import::Lib(LIB_NAME);
    initializeFunctions();
    return LIB->isLoaded();
}

void cl::ClApi::uninitialize() const
{
    delete LIB;
}

void cl::ClApi::initializeFunctions()
{
    CL_FUNC_IMPLEMENT(clGetPlatformIDs);
    CL_FUNC_IMPLEMENT(clGetPlatformInfo);
    CL_FUNC_IMPLEMENT(clBuildProgram);
    CL_FUNC_IMPLEMENT(clCloneKernel);
    CL_FUNC_IMPLEMENT(clCompileProgram);
    CL_FUNC_IMPLEMENT(clCreateBuffer);
    CL_FUNC_IMPLEMENT(clCreateCommandQueue);
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithProperties);
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithPropertiesKHR);
    CL_FUNC_IMPLEMENT(clCreateContext);
    CL_FUNC_IMPLEMENT(clSetDefaultDeviceCommandQueue);
}

