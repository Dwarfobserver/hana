/*!
@file
Defines `boost::hana::Functor`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_FUNCTOR_HPP
#define BOOST_HANA_CONCEPT_FUNCTOR_HPP

#include <boost/hana/fwd/concept/functor.hpp>

#include <boost/hana/adjust_if.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/fwd/core/models.hpp>
#include <boost/hana/transform.hpp>


namespace boost { namespace hana {
    template <typename F>
    struct models_impl<Functor, F> {
        static constexpr bool value = !is_default<transform_impl<F>>::value ||
                                      !is_default<adjust_if_impl<F>>::value;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONCEPT_FUNCTOR_HPP
