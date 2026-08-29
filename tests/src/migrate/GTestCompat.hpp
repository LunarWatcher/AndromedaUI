#pragma once

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#define EXPECT_EQ(a, b) REQUIRE(a == b)
#define EXPECT_NEAR(a, b, delta) REQUIRE_THAT((b), Catch::Matchers::WithinAbs((a), (delta)))
#define TEST(a, b) TEST_CASE(#a #b)
