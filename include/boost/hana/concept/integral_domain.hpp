/*!
@file
Defines `boost::hana::IntegralDomain`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_INTEGRAL_DOMAIN_HPP
#define BOOST_HANA_CONCEPT_INTEGRAL_DOMAIN_HPP

#include <boost/hana/fwd/concept/integral_domain.hpp>

#include <boost/hana/core/default.hpp>
#include <boost/hana/fwd/core/models.hpp>
#include <boost/hana/quot.hpp>
#include <boost/hana/rem.hpp>


namespace boost { namespace hana {
    template <typename D>
    struct models_impl<IntegralDomain, D> {
        static constexpr bool value = !is_default<rem_impl<D, D>>::value &&
                                      !is_default<quot_impl<D, D>>::value;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONCEPT_INTEGRAL_DOMAIN_HPP
