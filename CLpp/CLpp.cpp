#include "CLpp.hpp"

bool cl::InitLibrary()
{
    auto *clLib = CLApi::Instance();
    const auto success = clLib->Initialize();
    return success;
}

bool cl::FreeLibrary()
{
    auto *clLib = CLApi::Instance();
    clLib->Uninitialize();
    return true;
}
