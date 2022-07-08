#include "grid.hpp"

#include <gtest/gtest.h>

namespace tile_world_search
{
    TEST(TileTest, TestGetX)
    {
        Tile t1(1, 2, Letter::P);
        EXPECT_EQ(t1.getX(), 1);
        Tile t2(3, 0, Letter::P);
        EXPECT_EQ(t2.getX(), 3);
        Tile t3(2, 3, Letter::P);
        EXPECT_EQ(t3.getX(), 2);
    }

    TEST(TileTest, TestGetY)
    {
        Tile t1(1, 2, Letter::P);
        EXPECT_EQ(t1.getY(), 2);
        Tile t2(3, 0, Letter::P);
        EXPECT_EQ(t2.getY(), 0);
        Tile t3(2, 3, Letter::P);
        EXPECT_EQ(t3.getY(), 3);
    }
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
