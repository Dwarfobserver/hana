/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/core/make.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/tuple.hpp>

#include <string>
namespace hana = boost::hana;


int main() {
    auto xs = hana::make<hana::Tuple>(1, 2, '3', std::string{"456"});

    constexpr auto ys = hana::make<hana::Tuple>(1, '2', 3.456);
    static_assert(ys == hana::make_tuple(1, '2', 3.456), "");
}