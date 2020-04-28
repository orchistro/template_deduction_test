#include <utility>
#include <iostream>
#include <type_traits>
#include <functional>

template<typename T>
using IsNonVoidFunc = std::enable_if_t<!std::is_same_v<void, typename decltype(std::function{std::declval<T>()})::result_type>>;

template<typename T>
using IsVoidFunc = std::enable_if_t<std::is_same_v<void, typename decltype(std::function{std::declval<T>()})::result_type>>;

template <typename Func, typename ...Args, typename = IsVoidFunc<Func>>
void f(Func&& aFunc, Args&&... aArgs)
{
    std::cout << "f(): Func returns void\n";
    std::forward<decltype(aFunc)>(aFunc)(std::forward<decltype(aArgs)>(aArgs)...);
}

template <typename Func, typename ...Args, typename = IsNonVoidFunc<Func>>
auto f(Func&& aFunc, Args&&... aArgs)
{
    std::cout << "f(): Func returns non-void\n";
    auto r = std::forward<decltype(aFunc)>(aFunc)(std::forward<decltype(aArgs)>(aArgs)...);
    return r;
}

int main(void)
{
    f([](){std::cout<<"lambda\n";});
    f([](int a, std::string&& b){std::cout<<"lambda a:" << a << " b:" << b << "\n";}, 3, "str");
    auto r = f([](int a){std::cout<<"lambda returning int\n";return a;}, 13);
    std::cout << "r:" << r << "\n";

    return 0;
}

