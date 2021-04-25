#include "Lib.hpp"

cl::lib_import::Lib::Lib(const char* module)
    : m_IsLoaded(false)
{
    m_Imp = new LibImp();
    if (m_Imp->LoadModule(module))
        m_IsLoaded = true;
}

cl::lib_import::Lib::~Lib()
{
    if (m_IsLoaded)
        m_Imp->UnloadModule();
    delete m_Imp;
}
