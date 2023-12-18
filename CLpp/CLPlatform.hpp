#pragma once
#include "CLApi.hpp"
#include "CLCachedProperty.hpp"
#include <CL/opencl.h>
#include <vector>
#include <string>

namespace cl
{
    namespace details
    {
        template <typename T, typename Enable = void>
        class CLPlatformPropertyGetter;

        template <typename T>
        class CLPlatformPropertyGetter<T, std::enable_if_t<!std::is_pointer_v<T>>>
        {
        public:
            bool operator()(const cl_platform_id& platformId, cl_platform_info info, T& value)
            {
                auto* clApi = CLApi::Instance();

                if (!clApi->clGetPlatformInfo.Valid())
                    return false;

                auto success = clApi->clGetPlatformInfo(platformId, info, sizeof(T), &value, nullptr);
                if (success != CL_SUCCESS) {
                    //cout << "Failed to query parameter " << paramName << endl;
                    //cout << cl::ErrorToString(success) << endl;
                    return false;
                }

                return true;
            }
        };

        template <typename T>
        class CLPlatformPropertyGetter<T, std::enable_if_t<std::is_pointer_v<T>>>
        {
        public:
            bool operator()(const cl_platform_id& platformId, cl_platform_info info, T& value)
            {
                auto* clApi = CLApi::Instance();

                if (!clApi->clGetPlatformInfo.Valid())
                    return false;

                size_t paramValueSize = 0;
                auto success = clApi->clGetPlatformInfo(platformId, info, 0, nullptr, &paramValueSize);
                if (success != CL_SUCCESS) {
                    //cout << "Failed to query parameter size of " << paramName << endl;
                    //cout << cl::ErrorToString(success) << endl;
                    return false;
                }

                size = paramValueSize / sizeof(T);
                T* data = new T[paramValueSize / sizeof(T)];
                success = clApi->clGetPlatformInfo(platformId, info, paramValueSize, data, nullptr);
                if (success != CL_SUCCESS) {
                    //cout << "Failed to query parameter " << paramName << endl;
                    //cout << cl::ErrorToString(success) << endl;
                    delete[] data;
                    return false;
                }

                value = data;
                return true;
            }
        };
    }

    class CLPlatform
    {
    public:
        CLPlatform() = delete;
        CLPlatform(const CLPlatform& other) = default;
        CLPlatform(CLPlatform&& other) noexcept;
        ~CLPlatform() = default;

        CLPlatform& operator=(const CLPlatform& rhs);
        CLPlatform& operator=(CLPlatform&& rhs) noexcept;

        static std::vector<CLPlatform> GetPlatforms();

        template <typename T, typename std::enable_if_t<!std::is_pointer_v<T>, bool> = true>
        bool GetInfo(cl_platform_info info, T& value);

        template <typename T>
        bool GetInfo(cl_platform_info info, T*& value, size_t& size);

        std::string GetProfile();
        std::string GetVersion();
        cl_version GetNumericVersion();
        std::string GetName();
        std::string GetVendor();
        std::string GetExtensions();
        std::vector<cl_name_version> GetExtensionsWithVersion();
        cl_ulong GetHostTimerResolution();

    private:
        template <typename T, int PROPERTY>
        class CLPlatformProperty : public CLCachedProperty<T>
        {
        public:
            CLPlatformProperty(const cl_platform_id& id)
                : m_PlatformId(id)
            {}
            ~CLPlatformProperty() override = default;

            CLPlatformProperty(const CLPlatformProperty& other)
                : CLCachedProperty<T>(other)
                , m_PlatformId(other.m_PlatformId)
            {}

            CLPlatformProperty(CLPlatformProperty&& other) noexcept
                : CLCachedProperty<T>(std::move(other))
                , m_PlatformId(other.m_PlatformId)
            {}

            CLPlatformProperty& operator=(const CLPlatformProperty& rhs)
            {
                if (this == &rhs)
                    return *this;
                CLCachedProperty<T>::operator=(rhs);
                m_PlatformId = rhs.m_PlatformId;
                return *this;
            }

            CLPlatformProperty& operator=(CLPlatformProperty&& rhs) noexcept
            {
                if (this == &rhs)
                    return *this;
                m_PlatformId = rhs.m_PlatformId;
                CLCachedProperty<T>::operator=(std::move(rhs));
                return *this;
            }

        protected:
            void CacheValue(T& cachedValue) override
            {
                m_InfoGetter(m_PlatformId, PROPERTY, cachedValue);
            }

        private:
            cl_platform_id m_PlatformId;
            details::CLPlatformPropertyGetter<T> m_InfoGetter;
        };

        CLPlatform(cl_platform_id id);

        std::string GetStringInfo(cl_platform_info info);

        cl_platform_id m_PlatformId {nullptr};
        CLPlatformProperty<cl_version, CL_PLATFORM_NUMERIC_VERSION> m_NumericVersion;
        CLPlatformProperty<cl_ulong, CL_PLATFORM_HOST_TIMER_RESOLUTION> m_HostTimerResolution;
    };

    template <typename T, typename std::enable_if_t<!std::is_pointer_v<T>, bool>>
    bool CLPlatform::GetInfo(cl_platform_info info, T& value)
    {
        auto* clApi = CLApi::Instance();

        if (!clApi->clGetPlatformInfo.Valid())
            return false;

        auto success = clApi->clGetPlatformInfo(m_PlatformId, info, sizeof(T), &value, nullptr);
        if (success != CL_SUCCESS) {
            //cout << "Failed to query parameter " << paramName << endl;
            //cout << cl::ErrorToString(success) << endl;
            return false;
        }

        return true;
    }

    template <typename T>
    bool CLPlatform::GetInfo(cl_platform_info info, T*& value, size_t& size)
    {
        auto* clApi = CLApi::Instance();

        if (!clApi->clGetPlatformInfo.Valid())
            return false;

        size_t paramValueSize = 0;
        auto success = clApi->clGetPlatformInfo(m_PlatformId, info, 0, nullptr, &paramValueSize);
        if (success != CL_SUCCESS) {
            //cout << "Failed to query parameter size of " << paramName << endl;
            //cout << cl::ErrorToString(success) << endl;
            return false;
        }

        size = paramValueSize / sizeof(T);
        T* data = new T[paramValueSize / sizeof(T)];
        success = clApi->clGetPlatformInfo(m_PlatformId, info, paramValueSize, data, nullptr);
        if (success != CL_SUCCESS) {
            //cout << "Failed to query parameter " << paramName << endl;
            //cout << cl::ErrorToString(success) << endl;
            delete[] data;
            return false;
        }

        value = data;
        return true;
    }
}
