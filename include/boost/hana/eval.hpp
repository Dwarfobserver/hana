/*!
@file
Defines `boost::hana::eval`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EVAL_HPP
#define BOOST_HANA_EVAL_HPP

#include <boost/hana/fwd/eval.hpp>

#include <boost/hana/core/dispatch.hpp>
#include <boost/hana/detail/wrong.hpp>
#include <boost/hana/functional/id.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename Expr>
    constexpr decltype(auto) eval_t::operator()(Expr&& expr) const {
        return eval_impl<typename datatype<Expr>::type>::apply(
            static_cast<Expr&&>(expr)
        );
    }
    //! @endcond

    template <typename T, bool condition>
    struct eval_impl<T, when<condition>> : default_ {
        template <typename Expr>
        static constexpr auto eval_helper(Expr&& expr, int)
            -> decltype(static_cast<Expr&&>(expr)())
        { return static_cast<Expr&&>(expr)(); }

        template <typename Expr>
        static constexpr auto eval_helper(Expr&& expr, long)
            -> decltype(static_cast<Expr&&>(expr)(hana::id))
        { return static_cast<Expr&&>(expr)(hana::id); }

        template <typename Expr>
        static constexpr auto eval_helper(Expr&&, ...) {
            static_assert(detail::wrong<Expr>{},
            "hana::eval(expr) requires the expression to be Lazy, "
            "a nullary Callable or a unary Callable that may be "
            "called with hana::id");
        }

        template <typename Expr>
        static constexpr decltype(auto) apply(Expr&& expr)
        { return eval_helper(static_cast<Expr&&>(expr), int{}); }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EVAL_HPP
