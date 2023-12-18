#include <CLpp/CLpp.hpp>

#include <iostream>
#include <string>
using namespace std;

#define TEST_FUNC(FUNC) \
    if (!clApi->FUNC.Valid()) { \
        cout << "Failed to load " << #FUNC << endl; \
        cout << #FUNC << " requires version " << clApi->FUNC.MajorVersion() << "." << clApi->FUNC.MinorVersion() << endl; \
    } else {\
        cout << #FUNC << " loaded successfully" << endl; \
    }

void testFunctions()
{
    cout << "Testing functionalities..." << endl;
    auto clApi = cl::CLApi::Instance();

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

    // 3.0 functions
    TEST_FUNC(clCreateBufferWithProperties);
}

void GetPlatformInfos()
{
    auto platforms = cl::CLPlatform::GetPlatforms();
    for (auto& p : platforms) {
        cout << "Name: " << p.GetName() << endl;
        cout << "Vendor: " << p.GetVendor() << endl;
        cout << "Profile: " << p.GetProfile() << endl;
        cout << "Version: " << p.GetVersion() << endl;
        cout << "Numeric Version: " << p.GetNumericVersion() << endl;
        cout << "Extensions: " << p.GetExtensions() << endl;
        cout << "Host Timer Resolution: " << p.GetHostTimerResolution() << endl;
    }
}

int main(int argc, char** argv)
{
    const auto success = cl::InitLibrary();

    if (!success)
        cout << "Failed to initialize clUtils" << endl;
    else {
        cout << "clUtils initialized successfully!" << endl;
        testFunctions();
    }

    GetPlatformInfos();

    if (success)
        cl::FreeLibrary();

    cout << std::endl << "Press Enter to continue...";
    cin.get();

    return 0;
}