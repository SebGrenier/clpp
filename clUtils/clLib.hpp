#ifndef _CLLIB_HPP_
#define _CLLIB_HPP_

#include "libImport/lib.hpp"
#include <CL/opencl.h>

#define CL_FUNC_DECLARE(func) \
    static decltype(func) *func;

namespace cl {
    class ClLib
    {
    public:
        static ClLib* instance();

        ClLib(const ClLib& other) = delete;
        ClLib(ClLib&& other) noexcept = delete;
        ClLib& operator=(const ClLib& other) = delete;
        ClLib& operator=(ClLib&& other) noexcept = delete;

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

    private:
        ClLib();
        ~ClLib() = default;

        void initializeFunctions() const;

        static ClLib *_instance;
        lib_import::Lib* _lib;
    };
}

#undef CL_FUNC_DECLARE

#endif // _CLLIB_HPP_
