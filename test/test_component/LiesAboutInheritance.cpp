#include "pch.h"
#include "LiesAboutInheritance.h"
//#include "LiesAboutInheritance.g.cpp"

namespace winrt::test_component::implementation
{
}

// Satisfy the linker, which thinks we are producing a cppwinrt implemented class instead of using winrt::implements to
// produce an invalid class.
void* __cdecl winrt_make_test_component_LiesAboutInheritance(void)
{
    return winrt::make_self<winrt::test_component::implementation::LiesAboutInheritance>().detach();
}