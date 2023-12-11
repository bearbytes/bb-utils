#pragma once

namespace bb
{

#define type_of( x ) decltype( x )

//

template <class T>
inline constexpr bool is_const = false;

template <class T>
inline constexpr bool is_const<T const> = true;

template <class T>
inline constexpr bool is_const<T const &> = true;

template <class T>
inline constexpr bool is_const<T const &&> = true;

//

template <class T>
inline constexpr bool is_volatile = false;

template <class T>
inline constexpr bool is_volatile<T volatile> = true;

template <class T>
inline constexpr bool is_volatile<T volatile &> = true;

template <class T>
inline constexpr bool is_volatile<T volatile &&> = true;

//

template <class T>
inline constexpr bool is_pointer = false;

template <class T>
inline constexpr bool is_pointer<T *> = true;

template <class T>
inline constexpr bool is_pointer<T * const> = true;

template <class T>
inline constexpr bool is_pointer<T * volatile> = true;

template <class T>
inline constexpr bool is_pointer<T * const volatile> = true;

//

template <class T>
inline constexpr bool is_l_reference = false;

template <class T>
inline constexpr bool is_l_reference<T &> = true;

//

template <class T>
inline constexpr bool is_r_reference = false;

template <class T>
inline constexpr bool is_r_reference<T &&> = true;

//

template <class T>
inline constexpr bool is_reference = is_l_reference<T> or is_r_reference<T>;

//

template <class T, class U>
inline constexpr bool is_same = false;

template <class T>
inline constexpr bool is_same<T, T> = true;

//

template <class T, class... Ts>
requires ( sizeof...( Ts ) > 0 )
inline constexpr bool is_one_of = ( is_same<T, Ts> or ... );

//

template <class T, class... Ts>
inline constexpr bool are_unique = !is_one_of<T, Ts...> and are_unique<Ts...>;

template <class T>
inline constexpr bool are_unique<T> = true;

//

template <class T>
struct remove_const {
    using type = T;
};

template <class T>
struct remove_const<T const> {
    using type = T;
};

template <class T>
struct remove_const<T const &> {
    using type = T &;
};

template <class T>
struct remove_const<T const &&> {
    using type = T &&;
};

template <class T>
using without_const = remove_const<T>::type;

//

template <class T>
struct remove_volatile {
    using type = T;
};

template <class T>
struct remove_volatile<T volatile> {
    using type = T;
};

template <class T>
struct remove_volatile<T volatile &> {
    using type = T &;
};

template <class T>
struct remove_volatile<T volatile &&> {
    using type = T &&;
};

template <class T>
using without_volatile = remove_volatile<T>::type;

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
using pure = without_const<without_volatile<without_reference<T>>>;

} // namespace bb
