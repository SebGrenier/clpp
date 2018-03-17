#ifndef _LIB_IMP_WIN_
#define _LIB_IMP_WIN_
#ifdef WINDOWS_PLATFORM
#include <type_traits>
#include <windows.h>

bool testMyFunc(int num, const char* str);

namespace cl {
    namespace lib_import {
        class LibImpWin
        {
        public:
            LibImpWin() : _module(nullptr) {}

            bool loadModule(const LPCTSTR module)
            {
                _module = LoadLibrary(module);
                return _module != nullptr;
            }

            bool unloadModule() const
            {
                return FreeLibrary(_module);
            }

            template <typename T, typename = std::enable_if_t<std::is_function_v<T>>>
            T* loadFunction(const LPCSTR function)
            {
                const auto funcPtr = GetProcAddress(_module, function);
                if (nullptr == funcPtr)
                    return nullptr;
                return reinterpret_cast<T*>(funcPtr);
            }
        private:
            HMODULE _module;
        };
    }
}
#endif // WINDOWS_PLATFORM
#endif // _LIB_IMP_WIN_
