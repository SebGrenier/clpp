#ifndef _CLFUNCTION_HPP_
#define _CLFUNCTION_HPP_

namespace cl {
    // Hidden implementation
    namespace details {
        template<class Ret, class ...Args>
        struct ClFunctionBase
        {
            typedef Ret ReturnType;
        };

        template<class _Tx>
        struct _Get_function_impl;

        template<class _Ret, class... _Types>
        struct _Get_function_impl<_Ret(_Types...)>
        {
            /* determine type from argument list */
            typedef ClFunctionBase<_Ret, _Types> FunctionType;
        };
    }

    template <class T>
    class ClFunction : public details::_Get_function_impl<T>::FunctionType
    {
    public:
        

        

    private:
        T * _func;
    };
}

#endif // _CLFUNCTION_HPP_
