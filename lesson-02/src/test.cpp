#include <iostream>

#include <gtest/gtest.h>

#include "vector.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
    }
    void TearDown()
    {
    }
    fake::Fake foo;
};

TEST_F(TestFoo, test_const_method)
{
    ASSERT_EQ(foo.get_const(), 10);
}

TEST_F(TestFoo, test_string_method)
{
    ASSERT_EQ(foo.get_const_string(), std::string("Hello, world!"));
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


