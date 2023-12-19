#pragma once
#include <type_traits>
#include <vector>

namespace cl
{
    template <typename T, typename _ = void>
    struct is_vector {
        static const bool value = false;
    };

    template <typename T>
    struct is_vector<T, std::enable_if_t<std::is_same<T, std::vector< typename T::value_type, typename T::allocator_type>>::value>>
    {
        static const bool value = true;
    };
}
