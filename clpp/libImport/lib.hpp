#pragma once

#include <type_traits>

#ifdef WINDOWS_PLATFORM
#include "Windows/LibImp.hpp"
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

            bool IsLoaded() const { return m_IsLoaded; }

            template <typename T, typename = std::enable_if_t<std::is_function_v<T>>>
            T* LoadFunction(const char *funcName)
            {
                if (!m_IsLoaded)
                    return nullptr;
                return m_Imp->LoadFunction<T>(funcName);
            }
        private:
            LibImp *m_Imp;
            bool m_IsLoaded;
        };
    }
}
