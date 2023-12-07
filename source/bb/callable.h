#pragma once

#include <bb/constexpr-utils.h>

namespace bb
{

template <class Return, class... Args>
class callable {
    class model {
    public:
        virtual ~model() = default;
        virtual auto clone() const -> model * = 0;
        virtual auto operator()( Args const &... args ) const -> Return = 0;
    };

    template <class Fn>
    class implementation final : public model {
    public:
        explicit implementation( Fn action_ ) : action{ action_ } {}
        auto clone() const -> model * final { return new implementation( action ); }
        auto operator()( Args const &... args ) const -> Return final { return action( args... ); }

        Fn action;
    };

    model * pimpl_{ nullptr };

public:
    constexpr callable() noexcept = default;
    constexpr callable( callable const & other ) : pimpl_{ other.pimpl_->clone() } {}
    constexpr callable( callable && other ) noexcept : pimpl_{ exchange( other.pimpl_, nullptr ) }
    {}

    template <class Fn>
    constexpr callable( Fn action ) : pimpl_{ new implementation<Fn>( action ) }
    {}

    constexpr ~callable() { reset(); }

    constexpr auto operator=( callable const & other ) -> callable &
    {
        if ( this != &other ) {
            delete pimpl_;
            pimpl_ = other.pimpl_->clone();
        }
        return *this;
    }

    constexpr auto operator=( callable && other ) noexcept -> callable &
    {
        if ( this != &other ) {
            delete pimpl_;
            pimpl_ = exchange( other.pimpl_, nullptr );
        }
        return *this;
    }

    constexpr auto operator()( Args const &... args ) const -> Return
    {
        assert( pimpl_ );
        return ( *pimpl_ )( args... );
    }

    [[nodiscard]] constexpr auto is_valid() const noexcept -> bool { return pimpl_ != nullptr; }

    constexpr auto reset() -> void
    {
        delete pimpl_;
        pimpl_ = nullptr;
    }
};

template <typename R, typename... Args>
callable( R ( * )( Args... ) ) -> callable<R, Args...>;

} // namespace bb
