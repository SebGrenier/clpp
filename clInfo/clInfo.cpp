#include <clpp.hpp>

#include <iostream>
#include <string>
using namespace std;

#define TEST_FUNC(FUNC) \
    if (!clApi->FUNC.valid()) { \
        cout << "Failed to load " << #FUNC << endl; \
        cout << #FUNC << " requires version " << clApi->FUNC.majorVersion() << "." << clApi->FUNC.minorVersion() << endl; \
    } else {\
        cout << #FUNC << " loaded successfully" << endl; \
    }

void testFunctions()
{
    cout << "Testing functionalities..." << endl;
    auto clApi = cl::ClApi::instance();

    // 1.0 functions
    TEST_FUNC(clGetPlatformIDs);
    TEST_FUNC(clGetPlatformInfo);
    TEST_FUNC(clBuildProgram);
    TEST_FUNC(clCreateBuffer);
    TEST_FUNC(clCreateContext);

    // 2.0 functions
    TEST_FUNC(clCreateCommandQueueWithProperties);

    // 2.1 functions
    TEST_FUNC(clSetDefaultDeviceCommandQueue);
    TEST_FUNC(clCloneKernel);
}

void GetPlatformInfoForParam(cl_platform_id platformId, cl_platform_info param, const string& paramName)
{
    auto clApi = cl::ClApi::instance();
    if (!clApi->clGetPlatformInfo.valid())
        return;

    if (param == CL_PLATFORM_HOST_TIMER_RESOLUTION) {
        cl_ulong data = 0;
        auto success = clApi->clGetPlatformInfo(platformId, param, sizeof(cl_ulong), &data, nullptr);
        if (success != CL_SUCCESS) {
            cout << "Failed to query parameter " << paramName << endl;
            cout << cl::errorToString(success) << endl;
            return;
        }
        cout << paramName << ": " << data << endl;
    } else {
        size_t paramValueSize = 0;
        auto success = clApi->clGetPlatformInfo(platformId, param, 0, nullptr, &paramValueSize);
        if (success != CL_SUCCESS) {
            cout << "Failed to query parameter size of " << paramName << endl;
            cout << cl::errorToString(success) << endl;
            return;
        }

        char* data = new char[paramValueSize];
        success = clApi->clGetPlatformInfo(platformId, param, paramValueSize, data, nullptr);
        if (success != CL_SUCCESS) {
            cout << "Failed to query parameter " << paramName << endl;
            cout << cl::errorToString(success) << endl;
            return;
        }
        cout << paramName << ": " << data << endl;
    }
}

void GetPlatformInfo(cl_platform_id platformId)
{
    GetPlatformInfoForParam(platformId, CL_PLATFORM_PROFILE, "CL_PLATFORM_PROFILE");
    GetPlatformInfoForParam(platformId, CL_PLATFORM_VERSION, "CL_PLATFORM_VERSION");
    GetPlatformInfoForParam(platformId, CL_PLATFORM_NAME, "CL_PLATFORM_NAME");
    GetPlatformInfoForParam(platformId, CL_PLATFORM_VENDOR, "CL_PLATFORM_VENDOR");
    GetPlatformInfoForParam(platformId, CL_PLATFORM_EXTENSIONS, "CL_PLATFORM_EXTENSIONS");
    GetPlatformInfoForParam(platformId, CL_PLATFORM_HOST_TIMER_RESOLUTION, "CL_PLATFORM_HOST_TIMER_RESOLUTION");
}

void GetPlatformInfos()
{
    auto clApi = cl::ClApi::instance();
    if (!clApi->clGetPlatformIDs.valid())
        return;

    cl_uint numPlatform = 0;
    auto success = clApi->clGetPlatformIDs(0, nullptr, &numPlatform);
    if (success != CL_SUCCESS) {
        cout << "Failed to query the number of platforms." << endl;
        cout << cl::errorToString(success) << endl;
        return;
    }

    cl_platform_id* platformIds = new cl_platform_id[numPlatform];
    success = clApi->clGetPlatformIDs(numPlatform, platformIds, nullptr);
    if (success != CL_SUCCESS) {
        cout << "Failed to query the platforms." << endl;
        cout << cl::errorToString(success) << endl;
        return;
    }

    for (cl_uint i = 0; i < numPlatform; ++i) {
        GetPlatformInfo(platformIds[i]);
    }
}

int main(int argc, char** argv)
{
    const auto success = cl::initLibrary();

    if (!success)
        cout << "Failed to initialize clUtils" << endl;
    else {
        cout << "clUtils initialized successfully!" << endl;
        testFunctions();
    }

    GetPlatformInfos();

    if (success)
        cl::freeLibrary();

    string buffer;
    cin >> buffer;

    return 0;
}