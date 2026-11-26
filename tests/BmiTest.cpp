#include <gtest/gtest.h>
#include "utility.h"

TEST(calcBmiTest, calculatesBmi) {
    float weight = 70.0;
    float height = 2.0;
    float result = Utils::calcBmi(weight, height);
    EXPECT_FLOAT_EQ(result, static_cast<float>(70.0 / 4.0));
}
