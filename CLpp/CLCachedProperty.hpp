#pragma once
#include <algorithm>
#include <memory>

namespace cl
{
    template <typename T>
    class CLCachedProperty
    {
    public:
        CLCachedProperty() = default;
        CLCachedProperty(const CLCachedProperty& other)
            : m_Valid(other.m_Valid)
            , m_CachedValue(other.m_CachedValue)
        {}
        CLCachedProperty(CLCachedProperty&& other) noexcept
            : m_Valid(other.m_Valid)
            , m_CachedValue(std::move(other.m_CachedValue))
        {}

        virtual ~CLCachedProperty()
        {
            m_Valid = false;
        }

        CLCachedProperty& operator=(const CLCachedProperty& rhs)
        {
            if (this == &rhs)
                return *this;
            m_Valid = rhs.m_Valid;
            m_CachedValue = rhs.m_CachedValue;
            return *this;
        }

        CLCachedProperty& operator=(CLCachedProperty&& rhs) noexcept
        {
            if (this == &rhs)
                return *this;
            m_Valid = rhs.m_Valid;
            m_CachedValue = std::move(rhs.m_CachedValue);
            return *this;
        }

        const T& GetValue()
        {
            if (!m_Valid) {
                CacheValue(m_CachedValue);
                m_Valid = true;
            }
            return m_CachedValue;
        }

        void Invalidate()
        {
            m_Valid = false;
        }

    protected:
        virtual void CacheValue(T& cachedValue) = 0;

    private:
        bool m_Valid {false};

        T m_CachedValue;
    };
}
