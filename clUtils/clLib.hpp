#ifndef _CLLIB_HPP_
#define _CLLIB_HPP_

#include "libImport/lib.hpp"

namespace cl {
    class ClLib
    {
    public:
        ClLib();
        ~ClLib();

    private:
        lib_import::Lib* _lib;
    };
}

#endif // _CLLIB_HPP_
