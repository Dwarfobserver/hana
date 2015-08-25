/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/core/convert.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTANT_CHECK(
        hana::to<hana::Tuple>(hana::tuple_t<int, char, void, int(float)>)
            ==
        hana::make<hana::Tuple>(hana::type<int>, hana::type<char>, hana::type<void>, hana::type<int(float)>)
    );
}
