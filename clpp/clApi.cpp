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
    // 1.0
    CL_FUNC_IMPLEMENT(clGetPlatformIDs);
    CL_FUNC_IMPLEMENT(clGetPlatformInfo);
    CL_FUNC_IMPLEMENT(clGetDeviceIDs);
    CL_FUNC_IMPLEMENT(clGetDeviceInfo);
    CL_FUNC_IMPLEMENT(clBuildProgram);
    CL_FUNC_IMPLEMENT(clCreateBuffer);
    CL_FUNC_IMPLEMENT(clCreateContext);
    CL_FUNC_IMPLEMENT(clCreateContextFromType);
    CL_FUNC_IMPLEMENT(clRetainContext);
    CL_FUNC_IMPLEMENT(clReleaseContext);
    CL_FUNC_IMPLEMENT(clGetContextInfo);
    CL_FUNC_IMPLEMENT(clRetainCommandQueue);
    CL_FUNC_IMPLEMENT(clReleaseCommandQueue);
    CL_FUNC_IMPLEMENT(clGetCommandQueueInfo);
    CL_FUNC_IMPLEMENT(clEnqueueReadBuffer);
    CL_FUNC_IMPLEMENT(clEnqueueWriteBuffer);
    CL_FUNC_IMPLEMENT(clEnqueueCopyBuffer);
    CL_FUNC_IMPLEMENT(clEnqueueMapBuffer);
    CL_FUNC_IMPLEMENT(clGetSupportedImageFormats);
    CL_FUNC_IMPLEMENT(clEnqueueReadImage);
    CL_FUNC_IMPLEMENT(clEnqueueWriteImage);
    CL_FUNC_IMPLEMENT(clEnqueueCopyImage);
    CL_FUNC_IMPLEMENT(clEnqueueCopyImageToBuffer);
    CL_FUNC_IMPLEMENT(clEnqueueCopyBufferToImage);
    CL_FUNC_IMPLEMENT(clEnqueueMapImage);
    CL_FUNC_IMPLEMENT(clGetImageInfo);
    CL_FUNC_IMPLEMENT(clRetainMemObject);
    CL_FUNC_IMPLEMENT(clReleaseMemObject);
    CL_FUNC_IMPLEMENT(clEnqueueUnmapMemObject);
    CL_FUNC_IMPLEMENT(clGetMemObjectInfo);
    CL_FUNC_IMPLEMENT(clRetainSampler);
    CL_FUNC_IMPLEMENT(clReleaseSampler);
    CL_FUNC_IMPLEMENT(clGetSamplerInfo);
    CL_FUNC_IMPLEMENT(clCreateProgramWithSource);
    CL_FUNC_IMPLEMENT(clCreateProgramWithBinary);
    CL_FUNC_IMPLEMENT(clRetainProgram);
    CL_FUNC_IMPLEMENT(clReleaseProgram);
    CL_FUNC_IMPLEMENT(clGetProgramInfo);
    CL_FUNC_IMPLEMENT(clGetProgramBuildInfo);
    CL_FUNC_IMPLEMENT(clCreateKernel);
    CL_FUNC_IMPLEMENT(clCreateKernelsInProgram);
    CL_FUNC_IMPLEMENT(clRetainKernel);
    CL_FUNC_IMPLEMENT(clReleaseKernel);
    CL_FUNC_IMPLEMENT(clSetKernelArg);
    CL_FUNC_IMPLEMENT(clGetKernelInfo);
    CL_FUNC_IMPLEMENT(clGetKernelWorkGroupInfo);
    CL_FUNC_IMPLEMENT(clEnqueueNDRangeKernel);
    CL_FUNC_IMPLEMENT(clEnqueueNativeKernel);
    CL_FUNC_IMPLEMENT(clWaitForEvents);
    CL_FUNC_IMPLEMENT(clGetEventInfo);
    CL_FUNC_IMPLEMENT(clRetainEvent);
    CL_FUNC_IMPLEMENT(clReleaseEvent);
    CL_FUNC_IMPLEMENT(clGetEventProfilingInfo);
    CL_FUNC_IMPLEMENT(clFlush);
    CL_FUNC_IMPLEMENT(clFinish);

    // 1.1
    CL_FUNC_IMPLEMENT(clCreateSubBuffer);
    CL_FUNC_IMPLEMENT(clEnqueueReadBufferRect);
    CL_FUNC_IMPLEMENT(clEnqueueWriteBufferRect);
    CL_FUNC_IMPLEMENT(clEnqueueCopyBufferRect);
    CL_FUNC_IMPLEMENT(clSetMemObjectDestructorCallback);
    CL_FUNC_IMPLEMENT(clCreateUserEvent);
    CL_FUNC_IMPLEMENT(clSetUserEventStatus);
    CL_FUNC_IMPLEMENT(clSetEventCallback);

    // 1.2
    CL_FUNC_IMPLEMENT(clCompileProgram);
    CL_FUNC_IMPLEMENT(clCreateCommandQueue);
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithPropertiesKHR);
    CL_FUNC_IMPLEMENT(clCreateSubDevices);
    CL_FUNC_IMPLEMENT(clEnqueueFillBuffer);
    CL_FUNC_IMPLEMENT(clCreateImage);
    CL_FUNC_IMPLEMENT(clEnqueueFillImage);
    CL_FUNC_IMPLEMENT(clEnqueueMigrateMemObjects);
    CL_FUNC_IMPLEMENT(clCreateProgramWithBuiltInKernels);
    CL_FUNC_IMPLEMENT(clLinkProgram);
    CL_FUNC_IMPLEMENT(clUnloadPlatformCompiler);
    CL_FUNC_IMPLEMENT(clGetKernelArgInfo);
    CL_FUNC_IMPLEMENT(clEnqueueMarkerWithWaitList);
    CL_FUNC_IMPLEMENT(clEnqueueBarrierWithWaitList);

    // 2.0
    CL_FUNC_IMPLEMENT(clCreateCommandQueueWithProperties);
    CL_FUNC_IMPLEMENT(clCreatePipe);
    CL_FUNC_IMPLEMENT(clGetPipeInfo);
    CL_FUNC_IMPLEMENT(clSVMAlloc);
    CL_FUNC_IMPLEMENT(clSVMFree);
    CL_FUNC_IMPLEMENT(clEnqueueSVMFree);
    CL_FUNC_IMPLEMENT(clEnqueueSVMMemcpy);
    CL_FUNC_IMPLEMENT(clEnqueueSVMMemFill);
    CL_FUNC_IMPLEMENT(clEnqueueSVMMap);
    CL_FUNC_IMPLEMENT(clEnqueueSVMUnmap);
    CL_FUNC_IMPLEMENT(clCreateSamplerWithProperties);
    CL_FUNC_IMPLEMENT(clSetKernelArgSVMPointer);
    CL_FUNC_IMPLEMENT(clSetKernelExecInfo);

    // 2.1
    CL_FUNC_IMPLEMENT(clSetDefaultDeviceCommandQueue);
    CL_FUNC_IMPLEMENT(clCloneKernel);
    CL_FUNC_IMPLEMENT(clGetDeviceAndHostTimer);
    CL_FUNC_IMPLEMENT(clGetHostTimer);
    CL_FUNC_IMPLEMENT(clEnqueueSVMMigrateMem);
    CL_FUNC_IMPLEMENT(clCreateProgramWithIL);
    CL_FUNC_IMPLEMENT(clGetKernelSubGroupInfo);

    // 2.2
    CL_FUNC_IMPLEMENT(clSetProgramReleaseCallback);
}

