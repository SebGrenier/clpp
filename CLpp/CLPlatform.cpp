#include "CLPlatform.hpp"
#include <utility>

using namespace cl;
using namespace std;

CLPlatform::CLPlatform(cl_platform_id id)
    : m_PlatformId(id)
    , m_NumericVersion(id)
    , m_HostTimerResolution(id)
    , m_ExtensionsWithVersion(id)
{}

CLPlatform::CLPlatform(CLPlatform&& other) noexcept
    : m_PlatformId(std::exchange(other.m_PlatformId, nullptr))
    , m_NumericVersion(std::move(other.m_NumericVersion))
    , m_HostTimerResolution(std::move(other.m_HostTimerResolution))
    , m_ExtensionsWithVersion(std::move(other.m_ExtensionsWithVersion))
{}

CLPlatform& CLPlatform::operator=(const CLPlatform& rhs)
{
    if (this == &rhs)
        return *this;
    m_PlatformId = rhs.m_PlatformId;
    m_NumericVersion = rhs.m_NumericVersion;
    m_HostTimerResolution = rhs.m_HostTimerResolution;
    m_ExtensionsWithVersion = rhs.m_ExtensionsWithVersion;
    return *this;
}

CLPlatform& CLPlatform::operator=(CLPlatform&& rhs) noexcept
{
    if (this == &rhs)
        return *this;
    m_PlatformId = std::exchange(rhs.m_PlatformId, nullptr);
    m_NumericVersion = std::move(rhs.m_NumericVersion);
    m_HostTimerResolution = std::move(rhs.m_HostTimerResolution);
    m_ExtensionsWithVersion = std::move(rhs.m_ExtensionsWithVersion);
    return *this;
}

std::vector<CLPlatform> CLPlatform::GetPlatforms()
{
    std::vector<CLPlatform> platforms;
    auto* clApi = CLApi::Instance();

    if (!clApi->clGetPlatformInfo.Valid())
        return platforms;

    cl_uint numPlatform = 0;
    auto success = clApi->clGetPlatformIDs(0, nullptr, &numPlatform);
    if (success != CL_SUCCESS) {
        //cout << "Failed to query the number of platforms." << endl;
        //cout << ErrorToString(success) << endl;
        return platforms;
    }

    cl_platform_id* platformIds = new cl_platform_id[numPlatform];
    success = clApi->clGetPlatformIDs(numPlatform, platformIds, nullptr);
    if (success != CL_SUCCESS) {
        //cout << "Failed to query the platforms." << endl;
        //cout << cl::ErrorToString(success) << endl;

        delete[] platformIds;
        return platforms;
    }

    platforms.reserve(numPlatform);
    for (cl_uint i = 0; i < numPlatform; ++i)
    {
        platforms.push_back(CLPlatform(platformIds[i]));
    }

    delete[] platformIds;
    return platforms;
}

std::string CLPlatform::GetProfile()
{
    return GetStringInfo(CL_PLATFORM_PROFILE);
}

std::string CLPlatform::GetVersion()
{
    return GetStringInfo(CL_PLATFORM_VERSION);
}

cl_version CLPlatform::GetNumericVersion()
{
    return m_NumericVersion.GetValue();
}

std::string CLPlatform::GetName()
{
    return GetStringInfo(CL_PLATFORM_NAME);
}

std::string CLPlatform::GetVendor()
{
    return GetStringInfo(CL_PLATFORM_VENDOR);
}

std::string CLPlatform::GetExtensions()
{
    return GetStringInfo(CL_PLATFORM_EXTENSIONS);
}

vector<cl_name_version> CLPlatform::GetExtensionsWithVersion()
{
    return m_ExtensionsWithVersion.GetValue();
}

cl_ulong CLPlatform::GetHostTimerResolution()
{
    return m_HostTimerResolution.GetValue();
}

string CLPlatform::GetStringInfo(cl_platform_info info)
{
    string stringInfo;
    char* data = nullptr;
    size_t size = 0;
    if (!GetInfo(info, data, size))
        return stringInfo;
    if (data == nullptr)
        return stringInfo;

    stringInfo.assign(data);
    delete[] data;
    return stringInfo;
}
