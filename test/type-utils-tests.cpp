#include <bb/type-utils.h>

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

    // is_const

    static_assert( !is_const<type_of( i )> );
    static_assert( is_const<type_of( ic )> );
    static_assert( !is_const<type_of( iv )> );
    static_assert( is_const<type_of( icv )> );

    static_assert( !is_const<type_of( ip )> );
    static_assert( !is_const<type_of( icp )> );
    static_assert( !is_const<type_of( ivp )> );
    static_assert( !is_const<type_of( icvp )> );

    static_assert( is_const<type_of( ipc )> );
    static_assert( is_const<type_of( icpc )> );
    static_assert( is_const<type_of( ivpc )> );
    static_assert( is_const<type_of( icvpc )> );

    static_assert( !is_const<type_of( ipv )> );
    static_assert( !is_const<type_of( icpv )> );
    static_assert( !is_const<type_of( ivpv )> );
    static_assert( !is_const<type_of( icvpv )> );

    static_assert( is_const<type_of( ipcv )> );
    static_assert( is_const<type_of( icpcv )> );
    static_assert( is_const<type_of( ivpcv )> );
    static_assert( is_const<type_of( icvpcv )> );

    static_assert( !is_const<type_of( ir )> );
    static_assert( is_const<type_of( icr )> );
    static_assert( !is_const<type_of( ivr )> );
    static_assert( is_const<type_of( icvr )> );

    static_assert( !is_const<type_of( irr )> );
    static_assert( is_const<type_of( icrr )> );
    static_assert( !is_const<type_of( ivrr )> );
    static_assert( is_const<type_of( icvrr )> );

    // is_volatile

    static_assert( !is_volatile<type_of( i )> );
    static_assert( !is_volatile<type_of( ic )> );
    static_assert( is_volatile<type_of( iv )> );
    static_assert( is_volatile<type_of( icv )> );

    static_assert( !is_volatile<type_of( ip )> );
    static_assert( !is_volatile<type_of( icp )> );
    static_assert( !is_volatile<type_of( ivp )> );
    static_assert( !is_volatile<type_of( icvp )> );

    static_assert( !is_volatile<type_of( ipc )> );
    static_assert( !is_volatile<type_of( icpc )> );
    static_assert( !is_volatile<type_of( ivpc )> );
    static_assert( !is_volatile<type_of( icvpc )> );

    static_assert( is_volatile<type_of( ipv )> );
    static_assert( is_volatile<type_of( icpv )> );
    static_assert( is_volatile<type_of( ivpv )> );
    static_assert( is_volatile<type_of( icvpv )> );

    static_assert( is_volatile<type_of( ipcv )> );
    static_assert( is_volatile<type_of( icpcv )> );
    static_assert( is_volatile<type_of( ivpcv )> );
    static_assert( is_volatile<type_of( icvpcv )> );

    static_assert( !is_volatile<type_of( ir )> );
    static_assert( !is_volatile<type_of( icr )> );
    static_assert( is_volatile<type_of( ivr )> );
    static_assert( is_volatile<type_of( icvr )> );

    static_assert( !is_volatile<type_of( irr )> );
    static_assert( !is_volatile<type_of( icrr )> );
    static_assert( is_volatile<type_of( ivrr )> );
    static_assert( is_volatile<type_of( icvrr )> );

    // is_pointer

    static_assert( !is_pointer<type_of( i )> );
    static_assert( !is_pointer<type_of( ic )> );
    static_assert( !is_pointer<type_of( iv )> );
    static_assert( !is_pointer<type_of( icv )> );

    static_assert( is_pointer<type_of( ip )> );
    static_assert( is_pointer<type_of( icp )> );
    static_assert( is_pointer<type_of( ivp )> );
    static_assert( is_pointer<type_of( icvp )> );

    static_assert( is_pointer<type_of( ipc )> );
    static_assert( is_pointer<type_of( icpc )> );
    static_assert( is_pointer<type_of( ivpc )> );
    static_assert( is_pointer<type_of( icvpc )> );

    static_assert( is_pointer<type_of( ipv )> );
    static_assert( is_pointer<type_of( icpv )> );
    static_assert( is_pointer<type_of( ivpv )> );
    static_assert( is_pointer<type_of( icvpv )> );

    static_assert( is_pointer<type_of( ipcv )> );
    static_assert( is_pointer<type_of( icpcv )> );
    static_assert( is_pointer<type_of( ivpcv )> );
    static_assert( is_pointer<type_of( icvpcv )> );

    static_assert( !is_pointer<type_of( ir )> );
    static_assert( !is_pointer<type_of( icr )> );
    static_assert( !is_pointer<type_of( ivr )> );
    static_assert( !is_pointer<type_of( icvr )> );

    static_assert( !is_pointer<type_of( irr )> );
    static_assert( !is_pointer<type_of( icrr )> );
    static_assert( !is_pointer<type_of( ivrr )> );
    static_assert( !is_pointer<type_of( icvrr )> );

    // is_l_reference

    static_assert( !is_l_reference<type_of( i )> );
    static_assert( !is_l_reference<type_of( ic )> );
    static_assert( !is_l_reference<type_of( iv )> );
    static_assert( !is_l_reference<type_of( icv )> );

    static_assert( !is_l_reference<type_of( ip )> );
    static_assert( !is_l_reference<type_of( icp )> );
    static_assert( !is_l_reference<type_of( ivp )> );
    static_assert( !is_l_reference<type_of( icvp )> );

    static_assert( !is_l_reference<type_of( ipc )> );
    static_assert( !is_l_reference<type_of( icpc )> );
    static_assert( !is_l_reference<type_of( ivpc )> );
    static_assert( !is_l_reference<type_of( icvpc )> );

    static_assert( !is_l_reference<type_of( ipv )> );
    static_assert( !is_l_reference<type_of( icpv )> );
    static_assert( !is_l_reference<type_of( ivpv )> );
    static_assert( !is_l_reference<type_of( icvpv )> );

    static_assert( !is_l_reference<type_of( ipcv )> );
    static_assert( !is_l_reference<type_of( icpcv )> );
    static_assert( !is_l_reference<type_of( ivpcv )> );
    static_assert( !is_l_reference<type_of( icvpcv )> );

    static_assert( is_l_reference<type_of( ir )> );
    static_assert( is_l_reference<type_of( icr )> );
    static_assert( is_l_reference<type_of( ivr )> );
    static_assert( is_l_reference<type_of( icvr )> );

    static_assert( !is_l_reference<type_of( irr )> );
    static_assert( !is_l_reference<type_of( icrr )> );
    static_assert( !is_l_reference<type_of( ivrr )> );
    static_assert( !is_l_reference<type_of( icvrr )> );

    // is_r_reference

    static_assert( !is_r_reference<type_of( i )> );
    static_assert( !is_r_reference<type_of( ic )> );
    static_assert( !is_r_reference<type_of( iv )> );
    static_assert( !is_r_reference<type_of( icv )> );

    static_assert( !is_r_reference<type_of( ip )> );
    static_assert( !is_r_reference<type_of( icp )> );
    static_assert( !is_r_reference<type_of( ivp )> );
    static_assert( !is_r_reference<type_of( icvp )> );

    static_assert( !is_r_reference<type_of( ipc )> );
    static_assert( !is_r_reference<type_of( icpc )> );
    static_assert( !is_r_reference<type_of( ivpc )> );
    static_assert( !is_r_reference<type_of( icvpc )> );

    static_assert( !is_r_reference<type_of( ipv )> );
    static_assert( !is_r_reference<type_of( icpv )> );
    static_assert( !is_r_reference<type_of( ivpv )> );
    static_assert( !is_r_reference<type_of( icvpv )> );

    static_assert( !is_r_reference<type_of( ipcv )> );
    static_assert( !is_r_reference<type_of( icpcv )> );
    static_assert( !is_r_reference<type_of( ivpcv )> );
    static_assert( !is_r_reference<type_of( icvpcv )> );

    static_assert( !is_r_reference<type_of( ir )> );
    static_assert( !is_r_reference<type_of( icr )> );
    static_assert( !is_r_reference<type_of( ivr )> );
    static_assert( !is_r_reference<type_of( icvr )> );

    static_assert( is_r_reference<type_of( irr )> );
    static_assert( is_r_reference<type_of( icrr )> );
    static_assert( is_r_reference<type_of( ivrr )> );
    static_assert( is_r_reference<type_of( icvrr )> );

    // is_reference

    static_assert( !is_reference<type_of( i )> );
    static_assert( !is_reference<type_of( ic )> );
    static_assert( !is_reference<type_of( iv )> );
    static_assert( !is_reference<type_of( icv )> );

    static_assert( !is_reference<type_of( ip )> );
    static_assert( !is_reference<type_of( icp )> );
    static_assert( !is_reference<type_of( ivp )> );
    static_assert( !is_reference<type_of( icvp )> );

    static_assert( !is_reference<type_of( ipc )> );
    static_assert( !is_reference<type_of( icpc )> );
    static_assert( !is_reference<type_of( ivpc )> );
    static_assert( !is_reference<type_of( icvpc )> );

    static_assert( !is_reference<type_of( ipv )> );
    static_assert( !is_reference<type_of( icpv )> );
    static_assert( !is_reference<type_of( ivpv )> );
    static_assert( !is_reference<type_of( icvpv )> );

    static_assert( !is_reference<type_of( ipcv )> );
    static_assert( !is_reference<type_of( icpcv )> );
    static_assert( !is_reference<type_of( ivpcv )> );
    static_assert( !is_reference<type_of( icvpcv )> );

    static_assert( is_reference<type_of( ir )> );
    static_assert( is_reference<type_of( icr )> );
    static_assert( is_reference<type_of( ivr )> );
    static_assert( is_reference<type_of( icvr )> );

    static_assert( is_reference<type_of( irr )> );
    static_assert( is_reference<type_of( icrr )> );
    static_assert( is_reference<type_of( ivrr )> );
    static_assert( is_reference<type_of( icvrr )> );

    // is_same

    using integer = int;
    static_assert( is_same<int, integer> );

    static_assert( is_same<int, type_of( i )> );
    static_assert( is_same<int const, type_of( ic )> );
    static_assert( is_same<int volatile, type_of( iv )> );
    static_assert( is_same<int const volatile, type_of( icv )> );

    static_assert( is_same<int *, type_of( ip )> );
    static_assert( is_same<int const *, type_of( icp )> );
    static_assert( is_same<int volatile *, type_of( ivp )> );
    static_assert( is_same<int const volatile *, type_of( icvp )> );

    static_assert( is_same<int * const, type_of( ipc )> );
    static_assert( is_same<int const * const, type_of( icpc )> );
    static_assert( is_same<int volatile * const, type_of( ivpc )> );
    static_assert( is_same<int const volatile * const, type_of( icvpc )> );

    static_assert( is_same<int * volatile, type_of( ipv )> );
    static_assert( is_same<int const * volatile, type_of( icpv )> );
    static_assert( is_same<int volatile * volatile, type_of( ivpv )> );
    static_assert( is_same<int const volatile * volatile, type_of( icvpv )> );

    static_assert( is_same<int * const volatile, type_of( ipcv )> );
    static_assert( is_same<int const * const volatile, type_of( icpcv )> );
    static_assert( is_same<int volatile * const volatile, type_of( ivpcv )> );
    static_assert( is_same<int const volatile * const volatile, type_of( icvpcv )> );

    static_assert( is_same<int &, type_of( ir )> );
    static_assert( is_same<int const &, type_of( icr )> );
    static_assert( is_same<int volatile &, type_of( ivr )> );
    static_assert( is_same<int const volatile &, type_of( icvr )> );

    static_assert( is_same<int &&, type_of( irr )> );
    static_assert( is_same<int const &&, type_of( icrr )> );
    static_assert( is_same<int volatile &&, type_of( ivrr )> );
    static_assert( is_same<int const volatile &&, type_of( icvrr )> );

    static_assert( is_same<void, void> );
    static_assert( is_same<void *, void *> );

    static_assert( !is_same<int, int const> );
    static_assert( !is_same<int, int volatile> );
    static_assert( !is_same<int, int const volatile> );
    static_assert( !is_same<int, int const *> );
    static_assert( !is_same<int, int volatile *> );
    static_assert( !is_same<int, int const volatile *> );
    static_assert( !is_same<int, int * const> );
    static_assert( !is_same<int, int * volatile> );
    static_assert( !is_same<int, int * const volatile> );
    static_assert( !is_same<int, int &> );
    static_assert( !is_same<int, int &&> );

    static_assert( is_same<int, signed int> );
    static_assert( !is_same<int, unsigned int> );

    static_assert( !is_same<char, signed char> );
    static_assert( !is_same<char, unsigned char> );

    // is_one_of

    static_assert( is_one_of<int, bool, char, short, int> );
    static_assert( !is_one_of<int, int const, int volatile, int const volatile, int *, int &, int &&> );

    // are_unique

    static_assert( are_unique<char, signed char, unsigned char, char const, char volatile, char const volatile> );
    static_assert( are_unique<bool, char, short, int> );
    static_assert( are_unique<type_of( nullptr ), void *, char *, unsigned char *, signed char *> );
    static_assert( !are_unique<int, type_of( i )> );

    // without_const

    static_assert( is_same<int, without_const<type_of( i )>> );
    static_assert( is_same<int, without_const<type_of( ic )>> );
    static_assert( is_same<int volatile, without_const<type_of( iv )>> );
    static_assert( is_same<int volatile, without_const<type_of( icv )>> );

    static_assert( is_same<int *, without_const<type_of( ip )>> );
    static_assert( is_same<int const *, without_const<type_of( icp )>> );
    static_assert( is_same<int volatile *, without_const<type_of( ivp )>> );
    static_assert( is_same<int const volatile *, without_const<type_of( icvp )>> );

    static_assert( is_same<int *, without_const<type_of( ipc )>> );
    static_assert( is_same<int const *, without_const<type_of( icpc )>> );
    static_assert( is_same<int volatile *, without_const<type_of( ivpc )>> );
    static_assert( is_same<int const volatile *, without_const<type_of( icvpc )>> );

    static_assert( is_same<int * volatile, without_const<type_of( ipv )>> );
    static_assert( is_same<int const * volatile, without_const<type_of( icpv )>> );
    static_assert( is_same<int volatile * volatile, without_const<type_of( ivpv )>> );
    static_assert( is_same<int const volatile * volatile, without_const<type_of( icvpv )>> );

    static_assert( is_same<int * volatile, without_const<type_of( ipcv )>> );
    static_assert( is_same<int const * volatile, without_const<type_of( icpcv )>> );
    static_assert( is_same<int volatile * volatile, without_const<type_of( ivpcv )>> );
    static_assert( is_same<int const volatile * volatile, without_const<type_of( icvpcv )>> );

    static_assert( is_same<int &, without_const<type_of( ir )>> );
    static_assert( is_same<int &, without_const<type_of( icr )>> );
    static_assert( is_same<int volatile &, without_const<type_of( ivr )>> );
    static_assert( is_same<int volatile &, without_const<type_of( icvr )>> );

    static_assert( is_same<int &&, without_const<type_of( irr )>> );
    static_assert( is_same<int &&, without_const<type_of( icrr )>> );
    static_assert( is_same<int volatile &&, without_const<type_of( ivrr )>> );
    static_assert( is_same<int volatile &&, without_const<type_of( icvrr )>> );

    // without_volatile

    static_assert( is_same<int, without_volatile<type_of( i )>> );
    static_assert( is_same<int const, without_volatile<type_of( ic )>> );
    static_assert( is_same<int, without_volatile<type_of( iv )>> );
    static_assert( is_same<int const, without_volatile<type_of( icv )>> );

    static_assert( is_same<int *, without_volatile<type_of( ip )>> );
    static_assert( is_same<int const *, without_volatile<type_of( icp )>> );
    static_assert( is_same<int volatile *, without_volatile<type_of( ivp )>> );
    static_assert( is_same<int const volatile *, without_volatile<type_of( icvp )>> );

    static_assert( is_same<int * const, without_volatile<type_of( ipc )>> );
    static_assert( is_same<int const * const, without_volatile<type_of( icpc )>> );
    static_assert( is_same<int volatile * const, without_volatile<type_of( ivpc )>> );
    static_assert( is_same<int const volatile * const, without_volatile<type_of( icvpc )>> );

    static_assert( is_same<int *, without_volatile<type_of( ipv )>> );
    static_assert( is_same<int const *, without_volatile<type_of( icpv )>> );
    static_assert( is_same<int volatile *, without_volatile<type_of( ivpv )>> );
    static_assert( is_same<int const volatile *, without_volatile<type_of( icvpv )>> );

    static_assert( is_same<int * const, without_volatile<type_of( ipcv )>> );
    static_assert( is_same<int const * const, without_volatile<type_of( icpcv )>> );
    static_assert( is_same<int volatile * const, without_volatile<type_of( ivpcv )>> );
    static_assert( is_same<int const volatile * const, without_volatile<type_of( icvpcv )>> );

    static_assert( is_same<int &, without_volatile<type_of( ir )>> );
    static_assert( is_same<int const &, without_volatile<type_of( icr )>> );
    static_assert( is_same<int &, without_volatile<type_of( ivr )>> );
    static_assert( is_same<int const &, without_volatile<type_of( icvr )>> );

    static_assert( is_same<int &&, without_volatile<type_of( irr )>> );
    static_assert( is_same<int const &&, without_volatile<type_of( icrr )>> );
    static_assert( is_same<int &&, without_volatile<type_of( ivrr )>> );
    static_assert( is_same<int const &&, without_volatile<type_of( icvrr )>> );

    // without_reference

    static_assert( is_same<int, without_reference<type_of( i )>> );
    static_assert( is_same<int const, without_reference<type_of( ic )>> );
    static_assert( is_same<int volatile, without_reference<type_of( iv )>> );
    static_assert( is_same<int const volatile, without_reference<type_of( icv )>> );

    static_assert( is_same<int *, without_reference<type_of( ip )>> );
    static_assert( is_same<int const *, without_reference<type_of( icp )>> );
    static_assert( is_same<int volatile *, without_reference<type_of( ivp )>> );
    static_assert( is_same<int const volatile *, without_reference<type_of( icvp )>> );

    static_assert( is_same<int * const, without_reference<type_of( ipc )>> );
    static_assert( is_same<int const * const, without_reference<type_of( icpc )>> );
    static_assert( is_same<int volatile * const, without_reference<type_of( ivpc )>> );
    static_assert( is_same<int const volatile * const, without_reference<type_of( icvpc )>> );

    static_assert( is_same<int * volatile, without_reference<type_of( ipv )>> );
    static_assert( is_same<int const * volatile, without_reference<type_of( icpv )>> );
    static_assert( is_same<int volatile * volatile, without_reference<type_of( ivpv )>> );
    static_assert( is_same<int const volatile * volatile, without_reference<type_of( icvpv )>> );

    static_assert( is_same<int * const volatile, without_reference<type_of( ipcv )>> );
    static_assert( is_same<int const * const volatile, without_reference<type_of( icpcv )>> );
    static_assert( is_same<int volatile * const volatile, without_reference<type_of( ivpcv )>> );
    static_assert( is_same<int const volatile * const volatile, without_reference<type_of( icvpcv )>> );

    static_assert( is_same<int, without_reference<type_of( ir )>> );
    static_assert( is_same<int const, without_reference<type_of( icr )>> );
    static_assert( is_same<int volatile, without_reference<type_of( ivr )>> );
    static_assert( is_same<int const volatile, without_reference<type_of( icvr )>> );

    static_assert( is_same<int, without_reference<type_of( irr )>> );
    static_assert( is_same<int const, without_reference<type_of( icrr )>> );
    static_assert( is_same<int volatile, without_reference<type_of( ivrr )>> );
    static_assert( is_same<int const volatile, without_reference<type_of( icvrr )>> );

    // pure

    static_assert( is_same<int, pure<type_of( i )>> );
    static_assert( is_same<int, pure<type_of( ic )>> );
    static_assert( is_same<int, pure<type_of( iv )>> );
    static_assert( is_same<int, pure<type_of( icv )>> );

    static_assert( is_same<int *, pure<type_of( ip )>> );
    static_assert( is_same<int const *, pure<type_of( icp )>> );
    static_assert( is_same<int volatile *, pure<type_of( ivp )>> );
    static_assert( is_same<int const volatile *, pure<type_of( icvp )>> );

    static_assert( is_same<int *, pure<type_of( ipc )>> );
    static_assert( is_same<int const *, pure<type_of( icpc )>> );
    static_assert( is_same<int volatile *, pure<type_of( ivpc )>> );
    static_assert( is_same<int const volatile *, pure<type_of( icvpc )>> );

    static_assert( is_same<int *, pure<type_of( ipv )>> );
    static_assert( is_same<int const *, pure<type_of( icpv )>> );
    static_assert( is_same<int volatile *, pure<type_of( ivpv )>> );
    static_assert( is_same<int const volatile *, pure<type_of( icvpv )>> );

    static_assert( is_same<int *, pure<type_of( ipcv )>> );
    static_assert( is_same<int const *, pure<type_of( icpcv )>> );
    static_assert( is_same<int volatile *, pure<type_of( ivpcv )>> );
    static_assert( is_same<int const volatile *, pure<type_of( icvpcv )>> );

    static_assert( is_same<int, pure<type_of( ir )>> );
    static_assert( is_same<int, pure<type_of( icr )>> );
    static_assert( is_same<int, pure<type_of( ivr )>> );
    static_assert( is_same<int, pure<type_of( icvr )>> );

    static_assert( is_same<int, pure<type_of( irr )>> );
    static_assert( is_same<int, pure<type_of( icrr )>> );
    static_assert( is_same<int, pure<type_of( ivrr )>> );
    static_assert( is_same<int, pure<type_of( icvrr )>> );
}
