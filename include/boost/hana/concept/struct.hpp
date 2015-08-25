/*!
@file
Defines `boost::hana::Struct`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_STRUCT_HPP
#define BOOST_HANA_CONCEPT_STRUCT_HPP

#include <boost/hana/fwd/concept/struct.hpp>

#include <boost/hana/accessors.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/fwd/core/models.hpp>


namespace boost { namespace hana {
    template <typename S>
    struct models_impl<Struct, S> {
        static constexpr bool value = !is_default<accessors_impl<S>>::value;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONCEPT_STRUCT_HPP
