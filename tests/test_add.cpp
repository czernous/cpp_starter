#include <catch2/catch_test_macros.hpp>
#include <../src/lib/add.h>

TEST_CASE("add correctly calculates 1 + 2 = 3", "[single-file]")
{
    REQUIRE(add(1, 2) == 3);
}
