#include "lib.hpp"

cl::lib_import::Lib::Lib(const char* module)
    : _isLoaded(false)
{
    _imp = new LibImpWin();
    if (_imp->loadModule(module))
        _isLoaded = true;
}

cl::lib_import::Lib::~Lib()
{
    if (_isLoaded)
        _imp->unloadModule();
    delete _imp;
}
