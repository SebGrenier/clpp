#ifndef _CLLIB_HPP_
#define _CLLIB_HPP_
#include <CL/opencl.h>

#define CL_FUNC_DECLARE(func) \
    decltype(func) *func;

namespace cl {
    class ClApi
    {
    public:
        static ClApi* instance();

        ClApi(const ClApi& other) = delete;
        ClApi(ClApi&& other) noexcept = delete;
        ClApi& operator=(const ClApi& other) = delete;
        ClApi& operator=(ClApi&& other) noexcept = delete;

        bool initialize();
        void uninitialize() const;

        CL_FUNC_DECLARE(clBuildProgram);
        CL_FUNC_DECLARE(clCloneKernel);
        CL_FUNC_DECLARE(clCompileProgram);
        CL_FUNC_DECLARE(clCreateBuffer);
        CL_FUNC_DECLARE(clCreateCommandQueue);
        CL_FUNC_DECLARE(clCreateCommandQueueWithProperties);
        CL_FUNC_DECLARE(clCreateCommandQueueWithPropertiesKHR);
        CL_FUNC_DECLARE(clCreateContext);
        CL_FUNC_DECLARE(clSetDefaultDeviceCommandQueue);

    private:
        ClApi() = default;
        ~ClApi() = default;

        void initializeFunctions();

        static ClApi *_instance;
    };
}

#undef CL_FUNC_DECLARE

#endif // _CLLIB_HPP_
