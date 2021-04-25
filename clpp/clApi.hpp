#pragma once

#include "CLFunction.hpp"

#include <CL/opencl.h>

#define CL_FUNC_DECLARE(func, MajorVersion, MinorVersion) \
    CLFunction<decltype(func), MajorVersion, MinorVersion, -1, -1> func;

#define CL_FUNC_DECLARE_DEPRECATE(func, MajorVersion, MinorVersion, DeprecatedMajor, DeprecatedMinor) \
    CLFunction<decltype(func), MajorVersion, MinorVersion, DeprecatedMajor, DeprecatedMinor> func;

namespace cl {
    class CLApi
    {
    public:
        static CLApi* Instance();

        CLApi(const CLApi& other) = delete;
        CLApi(CLApi&& other) noexcept = delete;
        CLApi& operator=(const CLApi& other) = delete;
        CLApi& operator=(CLApi&& other) noexcept = delete;

        bool Initialize();
        void Uninitialize() const;

        CL_FUNC_DECLARE(clGetPlatformIDs, 1, 0);
        CL_FUNC_DECLARE(clGetPlatformInfo, 1, 0);
        CL_FUNC_DECLARE(clGetDeviceIDs, 1, 0);
        CL_FUNC_DECLARE(clGetDeviceInfo, 1, 0);
        CL_FUNC_DECLARE(clBuildProgram, 1, 0);
        CL_FUNC_DECLARE(clCreateBuffer, 1, 0);
        CL_FUNC_DECLARE(clCreateContext, 1, 0);
        CL_FUNC_DECLARE(clCreateContextFromType, 1, 0);
        CL_FUNC_DECLARE(clRetainContext, 1, 0);
        CL_FUNC_DECLARE(clReleaseContext, 1, 0);
        CL_FUNC_DECLARE(clGetContextInfo, 1, 0);
        CL_FUNC_DECLARE(clRetainCommandQueue, 1, 0);
        CL_FUNC_DECLARE(clReleaseCommandQueue, 1, 0);
        CL_FUNC_DECLARE(clGetCommandQueueInfo, 1, 0);
        CL_FUNC_DECLARE(clEnqueueReadBuffer, 1, 0);
        CL_FUNC_DECLARE(clEnqueueWriteBuffer, 1, 0);
        CL_FUNC_DECLARE(clEnqueueCopyBuffer, 1, 0);
        CL_FUNC_DECLARE(clEnqueueMapBuffer, 1, 0);
        CL_FUNC_DECLARE(clGetSupportedImageFormats, 1, 0);
        CL_FUNC_DECLARE(clEnqueueReadImage, 1, 0);
        CL_FUNC_DECLARE(clEnqueueWriteImage, 1, 0);
        CL_FUNC_DECLARE(clEnqueueCopyImage, 1, 0);
        CL_FUNC_DECLARE(clEnqueueCopyImageToBuffer, 1, 0);
        CL_FUNC_DECLARE(clEnqueueCopyBufferToImage, 1, 0);
        CL_FUNC_DECLARE(clEnqueueMapImage, 1, 0);
        CL_FUNC_DECLARE(clGetImageInfo, 1, 0);
        CL_FUNC_DECLARE(clRetainMemObject, 1, 0);
        CL_FUNC_DECLARE(clReleaseMemObject, 1, 0);
        CL_FUNC_DECLARE(clEnqueueUnmapMemObject, 1, 0);
        CL_FUNC_DECLARE(clGetMemObjectInfo, 1, 0);
        CL_FUNC_DECLARE(clRetainSampler, 1, 0);
        CL_FUNC_DECLARE(clReleaseSampler, 1, 0);
        CL_FUNC_DECLARE(clGetSamplerInfo, 1, 0);
        CL_FUNC_DECLARE(clCreateProgramWithSource, 1, 0);
        CL_FUNC_DECLARE(clCreateProgramWithBinary, 1, 0);
        CL_FUNC_DECLARE(clRetainProgram, 1, 0);
        CL_FUNC_DECLARE(clReleaseProgram, 1, 0);
        CL_FUNC_DECLARE(clGetProgramInfo, 1, 0);
        CL_FUNC_DECLARE(clGetProgramBuildInfo, 1, 0);
        CL_FUNC_DECLARE(clCreateKernel, 1, 0);
        CL_FUNC_DECLARE(clCreateKernelsInProgram, 1, 0);
        CL_FUNC_DECLARE(clRetainKernel, 1, 0);
        CL_FUNC_DECLARE(clReleaseKernel, 1, 0);
        CL_FUNC_DECLARE(clSetKernelArg, 1, 0);
        CL_FUNC_DECLARE(clGetKernelInfo, 1, 0);
        CL_FUNC_DECLARE(clGetKernelWorkGroupInfo, 1, 0);
        CL_FUNC_DECLARE(clEnqueueNDRangeKernel, 1, 0);
        CL_FUNC_DECLARE(clEnqueueNativeKernel, 1, 0);
        CL_FUNC_DECLARE(clWaitForEvents, 1, 0);
        CL_FUNC_DECLARE(clGetEventInfo, 1, 0);
        CL_FUNC_DECLARE(clRetainEvent, 1, 0);
        CL_FUNC_DECLARE(clReleaseEvent, 1, 0);
        CL_FUNC_DECLARE(clGetEventProfilingInfo, 1, 0);
        CL_FUNC_DECLARE(clFlush, 1, 0);
        CL_FUNC_DECLARE(clFinish, 1, 0);

        CL_FUNC_DECLARE(clCreateSubBuffer, 1, 1);
        CL_FUNC_DECLARE(clEnqueueReadBufferRect, 1, 1);
        CL_FUNC_DECLARE(clEnqueueWriteBufferRect, 1, 1);
        CL_FUNC_DECLARE(clEnqueueCopyBufferRect, 1, 1);
        CL_FUNC_DECLARE(clSetMemObjectDestructorCallback, 1, 1);
        CL_FUNC_DECLARE(clCreateUserEvent, 1, 1);
        CL_FUNC_DECLARE(clSetUserEventStatus, 1, 1);
        CL_FUNC_DECLARE(clSetEventCallback, 1, 1);

        CL_FUNC_DECLARE(clCompileProgram, 1, 2);
        CL_FUNC_DECLARE_DEPRECATE(clCreateCommandQueue, 1, 2, 2, 0);
        CL_FUNC_DECLARE(clCreateCommandQueueWithPropertiesKHR, 1, 2);
        CL_FUNC_DECLARE(clCreateSubDevices, 1, 2);
        CL_FUNC_DECLARE(clEnqueueFillBuffer, 1, 2);
        CL_FUNC_DECLARE(clCreateImage, 1, 2);
        CL_FUNC_DECLARE(clEnqueueFillImage, 1, 2);
        CL_FUNC_DECLARE(clEnqueueMigrateMemObjects, 1, 2);
        CL_FUNC_DECLARE(clCreateProgramWithBuiltInKernels, 1, 2);
        CL_FUNC_DECLARE(clLinkProgram, 1, 2);
        CL_FUNC_DECLARE(clUnloadPlatformCompiler, 1, 2);
        CL_FUNC_DECLARE(clGetKernelArgInfo, 1, 2);
        CL_FUNC_DECLARE(clEnqueueMarkerWithWaitList, 1, 2);
        CL_FUNC_DECLARE(clEnqueueBarrierWithWaitList, 1, 2);

        CL_FUNC_DECLARE(clCreateCommandQueueWithProperties, 2, 0);
        CL_FUNC_DECLARE(clCreatePipe, 2, 0);
        CL_FUNC_DECLARE(clGetPipeInfo, 2, 0);
        CL_FUNC_DECLARE(clSVMAlloc, 2, 0);
        CL_FUNC_DECLARE(clSVMFree, 2, 0);
        CL_FUNC_DECLARE(clEnqueueSVMFree, 2, 0);
        CL_FUNC_DECLARE(clEnqueueSVMMemcpy, 2, 0);
        CL_FUNC_DECLARE(clEnqueueSVMMemFill, 2, 0);
        CL_FUNC_DECLARE(clEnqueueSVMMap, 2, 0);
        CL_FUNC_DECLARE(clEnqueueSVMUnmap, 2, 0);
        CL_FUNC_DECLARE(clCreateSamplerWithProperties, 2, 0);
        CL_FUNC_DECLARE(clSetKernelArgSVMPointer, 2, 0);
        CL_FUNC_DECLARE(clSetKernelExecInfo, 2, 0);

        CL_FUNC_DECLARE(clSetDefaultDeviceCommandQueue, 2, 1);
        CL_FUNC_DECLARE(clCloneKernel, 2, 1);
        CL_FUNC_DECLARE(clGetDeviceAndHostTimer, 2, 1);
        CL_FUNC_DECLARE(clGetHostTimer, 2, 1);
        CL_FUNC_DECLARE(clEnqueueSVMMigrateMem, 2, 1);
        CL_FUNC_DECLARE(clCreateProgramWithIL, 2, 1);
        CL_FUNC_DECLARE(clGetKernelSubGroupInfo, 2, 1);

        CL_FUNC_DECLARE_DEPRECATE(clSetProgramReleaseCallback, 2, 2, 3, 0);
        CL_FUNC_DECLARE(clSetProgramSpecializationConstant, 2, 2);

        CL_FUNC_DECLARE(clSetContextDestructorCallback, 3, 0);
        CL_FUNC_DECLARE(clCreateBufferWithProperties, 3, 0);
        CL_FUNC_DECLARE(clCreateImageWithProperties, 3, 0);

    private:
        CLApi() = default;
        ~CLApi() = default;

        void InitializeFunctions();

        static CLApi *m_Instance;
    };
}

#undef CL_FUNC_DECLARE
#undef CL_FUNC_DECLARE_DEPRECATE
