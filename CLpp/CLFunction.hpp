#pragma once

#include <functional>

namespace cl {
    // Hidden implementation
    namespace details {
        template<class Ret, class ...Args>
        class CLFunctionBase
        {
        public:
            typedef Ret ReturnType;
            typedef std::function<Ret(Args...)> FunctionType;

            explicit CLFunctionBase(Ret func(Args...))
            {
                if (nullptr != func)
                    m_Func = func;
            }

            virtual ~CLFunctionBase() = default;

            CLFunctionBase(const CLFunctionBase &rhs)
            {
                m_Func = rhs.m_Func;
            }

            CLFunctionBase(const CLFunctionBase &&rhs) noexcept
            {
                m_Func = std::move(rhs.m_Func);
            }

            CLFunctionBase& operator = (const CLFunctionBase &rhs)  // NOLINT(cert-oop54-cpp)
            {
                m_Func = rhs.m_Func;
                return *this;
            }

            CLFunctionBase& operator = (CLFunctionBase &&rhs) noexcept
            {
                m_Func = std::move(rhs.m_Func);
                return *this;
            }

            CLFunctionBase& operator = (Ret func(Args...))
            {
                FunctionType newFunction;
                if (nullptr != func)
                    newFunction = func;
                m_Func.swap(newFunction);
                return *this;
            }

            Ret operator () (Args... args)
            {
                return m_Func(std::forward<Args>(args)...);
            }

            bool Valid() const { return bool(m_Func); }

        private:
            std::function<Ret(Args ...)> m_Func;
        };

        template<class _Tx>
        struct _Get_function_impl;

        template<class _Ret, class... _Types>
        struct _Get_function_impl<_Ret(_Types...)>
        {
            /* determine type from argument list */
            typedef CLFunctionBase<_Ret, _Types...> FunctionType;
        };
    }

    template <class T, int MAJOR, int MINOR, int DEPRECATEDMAJOR, int DEPRECATEDMINOR>
    class CLFunction : public details::_Get_function_impl<T>::FunctionType
    {
        typedef typename details::_Get_function_impl<T>::FunctionType MyBase;

    public:
        CLFunction()
            : MyBase(nullptr)
        {}
        virtual ~CLFunction() = default;

        explicit CLFunction(T* functionPtr)
            : MyBase(functionPtr)
        {}

        CLFunction(const CLFunction &other)
            : MyBase(other)
        {}

        CLFunction(const CLFunction &&other) noexcept
            : MyBase(other)
        {}

        CLFunction& operator = (const CLFunction &rhs)
        {
            MyBase::operator=(rhs);
            return *this;
        }

        CLFunction& operator = (CLFunction &&rhs) noexcept
        {
            MyBase::operator=(rhs);
            return *this;
        }

        CLFunction& operator = (T* functionPtr)
        {
            MyBase::operator=(functionPtr);
            return *this;
        }

        int MajorVersion()
        {
            return MAJOR;
        }

        int MinorVersion()
        {
            return MINOR;
        }

        int DeprecatedMajorVersion()
        {
            return DEPRECATEDMAJOR;
        }

        int DeprecatedMinorVersion()
        {
            return DEPRECATEDMINOR;
        }

    private:
    };
}
