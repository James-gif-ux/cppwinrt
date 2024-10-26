#include "pch.h"
#include <winrt/test_component.h>
//#include "winrt/impl/test_component.2.h"

//int32_t __stdcall DllGetLiesAboutInheritance(void** instance) noexcept;

namespace
{
    struct LiesAboutInheritance : public winrt::implements<LiesAboutInheritance, winrt::test_component::ILiesAboutInheritance>
    {
        LiesAboutInheritance() = default;
        void StubMethod() {}
    };
}

bool g_failfastCalled = false;

void __stdcall WINRT_IMPL_RoFailFastWithErrorContext(int32_t) noexcept
{
    g_failfastCalled = true;
}

void DoTheUncatcheable(winrt::test_component::LiesAboutInheritance& lies) noexcept
{
    //lies.ToString();
}

bool CatchTheUncatcheable(winrt::test_component::LiesAboutInheritance& lies) noexcept
{
    bool caughtCrash = false;
    __try
    {
        DoTheUncatcheable(lies);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        caughtCrash = true;
    }
    return caughtCrash;
}

TEST_CASE("missing_required_interfaces")
{
    //HMODULE testComponent = LoadLibraryW(L"test_component.dll");
    //REQUIRE(testComponent != nullptr);
    //FARPROC address = GetProcAddress(testComponent, "DllGetLiesAboutInheritance");
    //REQUIRE(address != nullptr);
    //auto pfn = reinterpret_cast<decltype(DllGetLiesAboutInheritance)*>(address);
    //REQUIRE(pfn != nullptr);
    //const auto liesImpl = winrt::make_self<winrt::test_component::implementation::LiesAboutInheritance>();


    //winrt::test_component::LiesAboutInheritance lies{ nullptr };
    //const auto hresult = pfn(winrt::put_abi(lies));
    //REQUIRE(hresult == 0);

    //REQUIRE(lies);
    //REQUIRE_NOTHROW(lies.StubMethod());

    //REQUIRE(!g_failfastCalled);
    //const bool caughtCrash = CatchTheUncatcheable(lies);
    //REQUIRE(caughtCrash);
    //REQUIRE(g_failfastCalled);
}