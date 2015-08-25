/*!
@file
Defines `boost::hana::Group`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_GROUP_HPP
#define BOOST_HANA_CONCEPT_GROUP_HPP

#include <boost/hana/fwd/concept/group.hpp>

#include <boost/hana/core/default.hpp>
#include <boost/hana/fwd/core/models.hpp>
#include <boost/hana/minus.hpp>
#include <boost/hana/negate.hpp>


namespace boost { namespace hana {
    template <typename G>
    struct models_impl<Group, G> {
        static constexpr bool value = !is_default<negate_impl<G>>::value ||
                                      !is_default<minus_impl<G, G>>::value;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONCEPT_GROUP_HPP
