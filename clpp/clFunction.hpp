#ifndef _CLFUNCTION_HPP_
#define _CLFUNCTION_HPP_

#include <functional>

namespace cl {
    // Hidden implementation
    namespace details {
        template<class Ret, class ...Args>
        class ClFunctionBase
        {
        public:
            typedef Ret ReturnType;
            typedef std::function<Ret(Args...)> FunctionType;

            explicit ClFunctionBase(Ret func(Args...))
            {
                if (nullptr != func)
                    _func = func;
            }

            virtual ~ClFunctionBase() = default;

            ClFunctionBase(const ClFunctionBase &rhs)
            {
                _func = rhs._func;
            }

            ClFunctionBase(const ClFunctionBase &&rhs) noexcept
            {
                _func = std::move(rhs._func);
            }

            ClFunctionBase& operator = (const ClFunctionBase &rhs)  // NOLINT(cert-oop54-cpp)
            {
                _func = rhs._func;
                return *this;
            }

            ClFunctionBase& operator = (ClFunctionBase &&rhs) noexcept
            {
                _func = std::move(rhs._func);
                return *this;
            }

            ClFunctionBase& operator = (Ret func(Args...))
            {
                FunctionType newFunction;
                if (nullptr != func)
                    newFunction = func;
                _func.swap(newFunction);
                return *this;
            }

            Ret operator () (Args... args)
            {
                return _func(std::forward<Args>(args)...);
            }

            bool valid() const { return bool(_func); }

        private:
            std::function<Ret(Args ...)> _func;
        };

        template<class _Tx>
        struct _Get_function_impl;

        template<class _Ret, class... _Types>
        struct _Get_function_impl<_Ret(_Types...)>
        {
            /* determine type from argument list */
            typedef ClFunctionBase<_Ret, _Types...> FunctionType;
        };
    }

    template <class T, int MAJOR, int MINOR, int DEPRECATEDMAJOR, int DEPRECATEDMINOR>
    class ClFunction : public details::_Get_function_impl<T>::FunctionType
    {
        typedef typename details::_Get_function_impl<T>::FunctionType MyBase;

    public:
        ClFunction()
            : MyBase(nullptr)
        {}
        virtual ~ClFunction() = default;

        explicit ClFunction(T* functionPtr)
            : MyBase(functionPtr)
        {}

        ClFunction(const ClFunction &other)
            : MyBase(other)
        {}

        ClFunction(const ClFunction &&other) noexcept
            : MyBase(other)
        {}

        ClFunction& operator = (const ClFunction &rhs)
        {
            MyBase::operator=(rhs);
            return *this;
        }

        ClFunction& operator = (ClFunction &&rhs) noexcept
        {
            MyBase::operator=(rhs);
            return *this;
        }

        ClFunction& operator = (T* functionPtr)
        {
            MyBase::operator=(functionPtr);
            return *this;
        }

        int majorVersion()
        {
            return MAJOR;
        }

        int minorVersion()
        {
            return MINOR;
        }

        int deprecatedMajorVersion()
        {
            return DEPRECATEDMAJOR;
        }

        int deprecatedMinorVersion()
        {
            return DEPRECATEDMINOR;
        }

    private:
    };
}

#endif // _CLFUNCTION_HPP_
