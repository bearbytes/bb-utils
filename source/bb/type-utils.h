#pragma once

namespace bb
{

template <class T>
struct remove_const {
    using type = T;
};

template <class T>
struct remove_const<T const> {
    using type = T;
};

template <class T>
using without_const = remove_const<T>::type;

//

template <class T>
struct remove_reference {
    using type = T;
};

template <class T>
struct remove_reference<T &> {
    using type = T;
};

template <class T>
struct remove_reference<T &&> {
    using type = T;
};

template <class T>
using without_reference = remove_reference<T>::type;

//

template <class T>
using pure = without_const<without_reference<T>>;

//

template <class T, class U>
constexpr bool is_same = false;

template <class T>
constexpr bool is_same<T, T> = true;

//

template <class T, class... Ts>
requires ( sizeof...( Ts ) > 0 )
constexpr bool is_one_of = ( is_same<T, Ts> or ... );

//

template <class T, class... Ts>
constexpr bool are_unique = !is_one_of<T, Ts...> and are_unique<Ts...>;

template <class T>
constexpr bool are_unique<T> = true;

} // namespace bb
