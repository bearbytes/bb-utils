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
        virtual auto operator()( Args &&... args ) -> Return = 0;
    };

    template <class Fn>
    class implementation final : public model {
    public:
        explicit implementation( Fn action_ ) : action{ action_ } {}
        auto clone() const -> model * final { return new implementation( action ); }
        auto operator()( Args &&... args ) -> Return final
        {
            return action( as_forwarding<Args>( args )... );
        }

        Fn action;
    };

    model * pimpl_{ nullptr };

public:
    callable() noexcept = default;
    callable( callable const & other ) : pimpl_{ other.pimpl_->clone() } {}
    callable( callable && other ) noexcept : pimpl_{ exchange( other.pimpl_, nullptr ) } {}

    template <class Fn>
    callable( Fn action ) : pimpl_{ new implementation<Fn>( action ) }
    {}

    ~callable() { delete pimpl_; }

    auto operator=( callable const & other ) -> callable &
    {
        if ( this != &other ) {
            delete pimpl_;
            pimpl_ = other.pimpl_->clone();
        }
        return *this;
    }

    auto operator=( callable && other ) noexcept -> callable &
    {
        if ( this != &other ) {
            delete pimpl_;
            pimpl_ = exchange( other.pimpl_, nullptr );
        }
        return *this;
    }

    auto operator()( Args &&... args ) -> Return
    {
        return ( *pimpl_ )( as_forwarding<Args>( args )... );
    }

    [[nodiscard]] auto is_active() const noexcept -> bool { return pimpl_ != nullptr; }
};

template <typename R, typename... Args>
callable( R ( * )( Args... ) ) -> callable<R, Args...>;

} // namespace bb
