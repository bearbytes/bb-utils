#include <bb/casting-utils.h>

using namespace bb;

auto main() -> int
{
    int i;
    int const ic{};
    int volatile iv{};
    int const volatile icv{};

    int * ip = &i;
    int const * icp = &ic;
    int volatile * ivp = &iv;
    int const volatile * icvp = &icv;

    int * const ipc = &i;
    int const * const icpc = &ic;
    int volatile * const ivpc = &iv;
    int const volatile * const icvpc = &icv;

    int * volatile ipv = &i;
    int const * volatile icpv = &ic;
    int volatile * volatile ivpv = &iv;
    int const volatile * volatile icvpv = &icv;

    int * const volatile ipcv = &i;
    int const * const volatile icpcv = &ic;
    int volatile * const volatile ivpcv = &iv;
    int const volatile * const volatile icvpcv = &icv;

    int & ir = i;
    int const & icr = ic;
    int volatile & ivr = iv;
    int const volatile & icvr = icv;

    int && irr = 1;
    int const && icrr = 2;
    int volatile && ivrr = 3;
    int const volatile && icvrr = 4;

    // as

    static_assert( is_same<char, type_of( as<char>( i ) )> );
    static_assert( is_same<char, type_of( as<char>( ic ) )> );
    static_assert( is_same<char, type_of( as<char>( iv ) )> );
    static_assert( is_same<char, type_of( as<char>( icv ) )> );

    static_assert( is_same<char, type_of( as<char>( ir ) )> );
    static_assert( is_same<char, type_of( as<char>( icr ) )> );
    static_assert( is_same<char, type_of( as<char>( ivr ) )> );
    static_assert( is_same<char, type_of( as<char>( icvr ) )> );

    static_assert( is_same<char, type_of( as<char>( irr ) )> );
    static_assert( is_same<char, type_of( as<char>( icrr ) )> );
    static_assert( is_same<char, type_of( as<char>( ivrr ) )> );
    static_assert( is_same<char, type_of( as<char>( icvrr ) )> );

    static_assert( is_same<char const &, type_of( as<char const &>( i ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( ic ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( iv ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( icv ) )> );

    static_assert( is_same<char const &, type_of( as<char const &>( ir ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( icr ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( ivr ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( icvr ) )> );

    static_assert( is_same<char const &, type_of( as<char const &>( irr ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( icrr ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( ivrr ) )> );
    static_assert( is_same<char const &, type_of( as<char const &>( icvrr ) )> );

    // as_const

    static_assert( is_same<int const &, type_of( as_const( i ) )> );
    static_assert( is_same<int const &, type_of( as_const( ic ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( iv ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( icv ) )> );

    static_assert( is_same<int const *, type_of( as_const( ip ) )> );
    static_assert( is_same<int const *, type_of( as_const( icp ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( ivp ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( icvp ) )> );

    static_assert( is_same<int const *, type_of( as_const( ipc ) )> );
    static_assert( is_same<int const *, type_of( as_const( icpc ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( ivpc ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( icvpc ) )> );

    static_assert( is_same<int const *, type_of( as_const( ipv ) )> );
    static_assert( is_same<int const *, type_of( as_const( icpv ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( ivpv ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( icvpv ) )> );

    static_assert( is_same<int const *, type_of( as_const( ipcv ) )> );
    static_assert( is_same<int const *, type_of( as_const( icpcv ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( ivpcv ) )> );
    static_assert( is_same<int const volatile *, type_of( as_const( icvpcv ) )> );

    static_assert( is_same<int const &, type_of( as_const( ir ) )> );
    static_assert( is_same<int const &, type_of( as_const( icr ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( ivr ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( icvr ) )> );

    static_assert( is_same<int const &, type_of( as_const( irr ) )> );
    static_assert( is_same<int const &, type_of( as_const( icrr ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( ivrr ) )> );
    static_assert( is_same<int const volatile &, type_of( as_const( icvrr ) )> );

    // as_mutable

    static_assert( is_same<int &, type_of( as_mutable( i ) )> );
    static_assert( is_same<int &, type_of( as_mutable( ic ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( iv ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( icv ) )> );

    static_assert( is_same<int *, type_of( as_mutable( ip ) )> );
    static_assert( is_same<int *, type_of( as_mutable( icp ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( ivp ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( icvp ) )> );

    static_assert( is_same<int *, type_of( as_mutable( ipc ) )> );
    static_assert( is_same<int *, type_of( as_mutable( icpc ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( ivpc ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( icvpc ) )> );

    static_assert( is_same<int *, type_of( as_mutable( ipv ) )> );
    static_assert( is_same<int *, type_of( as_mutable( icpv ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( ivpv ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( icvpv ) )> );

    static_assert( is_same<int *, type_of( as_mutable( ipcv ) )> );
    static_assert( is_same<int *, type_of( as_mutable( icpcv ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( ivpcv ) )> );
    static_assert( is_same<int volatile *, type_of( as_mutable( icvpcv ) )> );

    static_assert( is_same<int &, type_of( as_mutable( ir ) )> );
    static_assert( is_same<int &, type_of( as_mutable( icr ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( ivr ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( icvr ) )> );

    static_assert( is_same<int &, type_of( as_mutable( irr ) )> );
    static_assert( is_same<int &, type_of( as_mutable( icrr ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( ivrr ) )> );
    static_assert( is_same<int volatile &, type_of( as_mutable( icvrr ) )> );

    // as_ptr_to

    static_assert( is_same<char *, type_of( as_ptr_to<char>( ip ) )> );
    static_assert( is_same<char const *, type_of( as_ptr_to<char>( icp ) )> );
    static_assert( is_same<char volatile *, type_of( as_ptr_to<char>( ivp ) )> );
    static_assert( is_same<char const volatile *, type_of( as_ptr_to<char>( icvp ) )> );

    static_assert( is_same<char *, type_of( as_ptr_to<char>( ipc ) )> );
    static_assert( is_same<char const *, type_of( as_ptr_to<char>( icpc ) )> );
    static_assert( is_same<char volatile *, type_of( as_ptr_to<char>( ivpc ) )> );
    static_assert( is_same<char const volatile *, type_of( as_ptr_to<char>( icvpc ) )> );

    static_assert( is_same<char *, type_of( as_ptr_to<char>( ipv ) )> );
    static_assert( is_same<char const *, type_of( as_ptr_to<char>( icpv ) )> );
    static_assert( is_same<char volatile *, type_of( as_ptr_to<char>( ivpv ) )> );
    static_assert( is_same<char const volatile *, type_of( as_ptr_to<char>( icvpv ) )> );

    static_assert( is_same<char *, type_of( as_ptr_to<char>( ipcv ) )> );
    static_assert( is_same<char const *, type_of( as_ptr_to<char>( icpcv ) )> );
    static_assert( is_same<char volatile *, type_of( as_ptr_to<char>( ivpcv ) )> );
    static_assert( is_same<char const volatile *, type_of( as_ptr_to<char>( icvpcv ) )> );

    // as_movable

    static_assert( is_same<int &&, type_of( as_movable( i ) )> );
    // static_assert( is_same<int const &&, type_of( as_movable( ic ) )> );
    static_assert( is_same<int volatile &&, type_of( as_movable( iv ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_movable( icv ) )> );

    static_assert( is_same<int &&, type_of( as_movable( ir ) )> );
    // static_assert( is_same<int const &&, type_of( as_movable( icr ) )> );
    static_assert( is_same<int volatile &&, type_of( as_movable( ivr ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_movable( icvr ) )> );

    static_assert( is_same<int &&, type_of( as_movable( irr ) )> );
    // static_assert( is_same<int const &&, type_of( as_movable( icrr ) )> );
    static_assert( is_same<int volatile &&, type_of( as_movable( ivrr ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_movable( icvrr ) )> );

    // as_forwarding

    static_assert( is_same<int &&, type_of( as_forwarding<int>( i ) )> );
    // static_assert( is_same<int const &&, type_of( as_forwarding<int>( ic ) )> );
    static_assert( is_same<int volatile &&, type_of( as_forwarding<int>( iv ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_forwarding<int>( icv ) )> );

    static_assert( is_same<int &&, type_of( as_forwarding<int>( ir ) )> );
    // static_assert( is_same<int const &&, type_of( as_forwarding<int>( icr ) )> );
    static_assert( is_same<int volatile &&, type_of( as_forwarding<int>( ivr ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_forwarding<int>( icvr ) )> );

    static_assert( is_same<int &&, type_of( as_forwarding<int>( irr ) )> );
    // static_assert( is_same<int const &&, type_of( as_forwarding<int>( icrr ) )> );
    static_assert( is_same<int volatile &&, type_of( as_forwarding<int>( ivrr ) )> );
    // static_assert( is_same<int const volatile &&, type_of( as_forwarding<int>( icvrr ) )> );
}
