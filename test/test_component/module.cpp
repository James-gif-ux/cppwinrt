#include "pch.h"

bool __stdcall test_can_unload_now() noexcept;
void* __stdcall test_get_activation_factory(std::wstring_view const& name);
void* __cdecl winrt_make_test_component_LiesAboutInheritance(void);

int32_t __stdcall DllCanUnloadNow() noexcept
{
    return test_can_unload_now() ? 0 : 1;
}

int32_t __stdcall DllGetActivationFactory(void* classId, void** factory) noexcept
{
    try
    {
        std::wstring_view const name{ *reinterpret_cast<winrt::hstring*>(&classId) };
        *factory = test_get_activation_factory(name);

        if (*factory)
        {
            return 0;
        }
        
        auto requal = [](std::wstring_view const& left, std::wstring_view const& right) noexcept
        {
            return std::equal(left.rbegin(), left.rend(), right.rbegin(), right.rend());
        };

        if (requal(name, L"test_component.LiesAboutInheritance"))
        {
            *factory = winrt_make_test_component_LiesAboutInheritance();
            if (*factory)
            {
                return 0;
            }
        }

        return winrt::hresult_class_not_available(name).to_abi();
    }
    catch (...)
    {
        return winrt::to_hresult();
    }
}


void __stdcall WINRT_IMPL_RoFailFastWithErrorContext(int32_t) noexcept
{
    //g_failfastCalled = true;
}

#include "LiesAboutInheritance.h"
int32_t __stdcall DllGetLiesAboutInheritance(void** instance) noexcept
{
    *instance = winrt::make_self<winrt::test_component::implementation::LiesAboutInheritance>().detach();
    return 0;
}