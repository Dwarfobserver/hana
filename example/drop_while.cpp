/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/drop_while.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/negate.hpp>
#include <boost/hana/range.hpp>
#include <boost/hana/tuple.hpp>
namespace hana = boost::hana;
using namespace hana::literals;


auto negative = [](auto x) {
    return x < hana::int_<0>;
};

BOOST_HANA_CONSTANT_CHECK(
    hana::drop_while(hana::make_range(hana::int_<-3>, hana::int_<6>), negative)
        ==
    hana::make_range(hana::int_<0>, hana::int_<6>)
);

BOOST_HANA_CONSTANT_CHECK(
    hana::drop_while(hana::make_tuple(1_c, -2_c, 4_c, 5_c), negative)
        ==
    hana::make_tuple(1_c, -2_c, 4_c, 5_c)
);

int main() { }
