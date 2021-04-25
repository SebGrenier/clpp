#pragma once

#ifdef WINDOWS_PLATFORM
#include <type_traits>
#include <windows.h>

namespace cl {
    namespace lib_import {
        class LibImpWin
        {
        public:
            LibImpWin() : m_Module(nullptr) {}

            bool LoadModule(const LPCTSTR module)
            {
                m_Module = LoadLibrary(module);
                return m_Module != nullptr;
            }

            bool UnloadModule() const
            {
                return FreeLibrary(m_Module);
            }

            template <typename T, typename = std::enable_if_t<std::is_function_v<T>>>
            T* LoadFunction(const LPCSTR function)
            {
                const auto funcPtr = GetProcAddress(m_Module, function);
                if (nullptr == funcPtr)
                    return nullptr;
                return reinterpret_cast<T*>(funcPtr);
            }
        private:
            HMODULE m_Module;
        };
    }
}
#endif // WINDOWS_PLATFORM
