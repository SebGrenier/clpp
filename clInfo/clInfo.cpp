#include <clUtils.hpp>
#include <clApi.hpp>

#include <iostream>
#include <string>
using namespace std;

#define TEST_FUNC(FUNC) \
    if (clApi->FUNC == nullptr) { \
        cout << "Failed to load " << #FUNC << endl; \
    } \

void testFunctions()
{
    cout << "Testing functionalities..." << endl;
    auto clApi = cl::ClApi::instance();

    
    TEST_FUNC(clCreateCommandQueueWithProperties);
    TEST_FUNC(clSetDefaultDeviceCommandQueue);
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

    if (success)
        cl::freeLibrary();

    string buffer;
    cin >> buffer;

    return 0;
}