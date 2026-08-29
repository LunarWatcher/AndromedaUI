#pragma once

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

/**
 * Do not use: this purely exists to avoid rewriting all the GTest macros.
 * Use catch2 directly instead
 */
#define EXPECT_EQ(a, b) REQUIRE(a == b)
/**
 * Do not use: this purely exists to avoid rewriting all the GTest macros.
 * Use catch2 directly instead
 */
#define EXPECT_NEAR(a, b, delta) REQUIRE_THAT((b), Catch::Matchers::WithinAbs((a), (delta)))
/**
 * Do not use: this purely exists to avoid rewriting all the GTest macros.
 * Use catch2 directly instead
 */
#define TEST(a, b) TEST_CASE(#a #b)
