#pragma once
#include <winrt/test_component.h>
//#include "LiesAboutInheritance.h"
//#include "LiesAboutInheritance.g.h"

namespace winrt::test_component::implementation
{
    struct LiesAboutInheritance : public winrt::implements<LiesAboutInheritance, winrt::test_component::ILiesAboutInheritance>
    {
        LiesAboutInheritance() = default;
        void StubMethod() {}
    };
}
//namespace winrt::test_component::factory_implementation
//{
//    struct LiesAboutInheritance : LiesAboutInheritanceT<LiesAboutInheritance, implementation::LiesAboutInheritance>
//    {
//    };
//}