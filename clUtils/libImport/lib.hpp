#ifndef _LIB_HPP_
#define _LIB_HPP_
#include <type_traits>

#ifdef WINDOWS_PLATFORM
#include "windows/libImp.hpp"
using LibImp = cl::lib_import::LibImpWin;
#endif

namespace cl {
    namespace lib_import {
        class Lib
        {
        public:
            explicit Lib(const char* module);
            ~Lib();

            // Prevent copying
            Lib(const Lib& rhs) = delete;
            Lib(const Lib&& rhs) = delete;
            Lib& operator = (const Lib &rhs) = delete;
            Lib& operator = (const Lib&& rhs) = delete;

            bool isLoaded() const { return _isLoaded; }

            template <typename T, typename = std::enable_if_t<std::is_function_v<T>>>
            T* loadFunction(const char *funcName)
            {
                return _imp->loadFunction<T>(funcName);
            }
        private:
            LibImp *_imp;
            bool _isLoaded;
        };
    }
}

#endif // _LIB_HPP_
