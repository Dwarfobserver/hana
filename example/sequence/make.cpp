/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/core/make.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/tuple.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::make<hana::Tuple>() == hana::make_tuple());
static_assert(hana::make<hana::Tuple>(1, '2', 3.3) == hana::make_tuple(1, '2', 3.3), "");

int main() { }
