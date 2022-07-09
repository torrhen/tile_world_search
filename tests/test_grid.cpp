#include "grid.hpp"

#include <gtest/gtest.h>

namespace tile_world_search
{
    TEST(TileTest, TestGetX)
    {
        Tile t(1, 2, Letter::P);
        ASSERT_EQ(t.getX(), 1);
    }

    TEST(TileTest, TestGetY)
    {
        Tile t(0, 3, Letter::P);
        ASSERT_EQ(t.getY(), 3);
    }

    TEST(GridTest, TestGetConfiguration)
    {
        /*
        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [A][B][C][P]
        */
        Tile P(3, 0, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 0, Letter::C);
        Grid g(P, A, B, C);
        ASSERT_EQ(g.get_configuration().at(0).at(3), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerUpNoSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [A][B][P][C]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][P][ ]
                        [A][B][ ][C]
        */
        Tile P(2, 0, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(3, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::UP);
        ASSERT_EQ(g.get_configuration().at(1).at(2), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(3), Letter::C);
    }

    TEST(GridTest, TestMovePlayerUpSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][C][ ]
                        [A][B][P][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][P][ ]
                        [A][B][C][ ]
        */
        Tile P(2, 0, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 1, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::UP);
        ASSERT_EQ(g.get_configuration().at(1).at(2), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerDownNoSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][P]
                        [ ][ ][ ][ ]
                        [A][B][C][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][ ][ ][P]
                        [A][B][C][ ]
        */
        Tile P(3, 2, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::DOWN);
        ASSERT_EQ(g.get_configuration().at(1).at(3), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerDownSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [P][ ][ ][ ]
                        [A][ ][ ][ ]
                        [ ][B][C][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [A][ ][ ][ ]
                        [P][ ][ ][ ]
                        [ ][B][C][ ]
        */
        Tile P(0, 2, Letter::P);
        Tile A(0, 1, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::DOWN);
        ASSERT_EQ(g.get_configuration().at(1).at(0), Letter::P);
        ASSERT_EQ(g.get_configuration().at(2).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerLeftNoSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [ ][P][ ][ ]
                        [A][B][C][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [P][ ][ ][ ]
                        [A][B][C][ ]
        */
        Tile P(0, 1, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::LEFT);
        ASSERT_EQ(g.get_configuration().at(1).at(0), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerLeftSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][C][ ]
                        [ ][ ][ ][ ]
                        [A][B][P][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][C][ ]
                        [ ][ ][ ][ ]
                        [A][P][B][ ]
        */
        Tile P(2, 0, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(1, 0, Letter::B);
        Tile C(2, 2, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::LEFT);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::B);
        ASSERT_EQ(g.get_configuration().at(2).at(2), Letter::C);
    }

    TEST(GridTest, TestMovePlayerRightNoSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][P][ ]
                        [ ][ ][ ][ ]
                        [A][ ][B][C]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][P]
                        [ ][ ][ ][ ]
                        [A][ ][B][C]
        */
        Tile P(2, 2, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(2, 0, Letter::B);
        Tile C(3, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::RIGHT);
        ASSERT_EQ(g.get_configuration().at(2).at(3), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(3), Letter::C);
    }

    TEST(GridTest, TestMovePlayerRightSwap)
    {
        /*
        Start Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [B][ ][ ][ ]
                        [A][P][C][ ]

        Expected Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][ ]
                        [B][ ][ ][ ]
                        [A][C][P][ ]
        */
        Tile P(1, 0, Letter::P);
        Tile A(0, 0, Letter::A);
        Tile B(0, 1, Letter::B);
        Tile C(2, 0, Letter::C);
        Grid g(P, A, B, C);
        g.move_player(Direction::RIGHT);
        ASSERT_EQ(g.get_configuration().at(0).at(2), Letter::P);
        ASSERT_EQ(g.get_configuration().at(0).at(0), Letter::A);
        ASSERT_EQ(g.get_configuration().at(1).at(0), Letter::B);
        ASSERT_EQ(g.get_configuration().at(0).at(1), Letter::C);
    }

    TEST(GridTest, TestGridsAreEqual)
    {
        /*
        g1 Grid:
                        [ ][ ][ ][ ]
                        [ ][P][ ][ ]
                        [ ][A][ ][ ]
                        [ ][B][C][ ]

        g2 Grid:
                        [ ][ ][ ][ ]
                        [ ][P][ ][ ]
                        [ ][A][ ][ ]
                        [ ][B][C][ ]
        */
        Tile p1(1, 2, Letter::P);
        Tile a1(1, 1, Letter::A);
        Tile b1(1, 0, Letter::B);
        Tile c1(2, 0, Letter::C);
        Grid g1(p1, a1, b1, c1);

        Tile p2(1, 2, Letter::P);
        Tile a2(1, 1, Letter::A);
        Tile b2(1, 0, Letter::B);
        Tile c2(2, 0, Letter::C);
        Grid g2(p2, a2, b2, c2);

        ASSERT_TRUE(g1 == g2);
        /*
        g3 Grid:
                        [ ][ ][ ][ ]
                        [ ][ ][ ][P]
                        [ ][A][ ][ ]
                        [ ][B][C][ ]
        */
        Tile p3(3, 2, Letter::P);
        Tile a3(1, 1, Letter::A);
        Tile b3(1, 0, Letter::B);
        Tile c3(2, 0, Letter::C);
        Grid g3(p3, a3, b3, c3);

        ASSERT_FALSE(g1 == g3);
    }

    TEST(GridTest, TestMisplacedTiles)
    {
        /*
        g1 grid:
                        [ ][ ][ ][ ]
                        [ ][ ][A][ ]
                        [P][ ][ ][ ]
                        [ ][C][ ][B]

        g2 grid:
                        [ ][ ][ ][ ]
                        [ ][A][ ][ ]
                        [ ][B][ ][ ]
                        [ ][C][ ][P]
        */
        Tile p1(0, 1, Letter::P);
        Tile a1(2, 2, Letter::A);
        Tile b1(3, 0, Letter::B);
        Tile c1(1, 0, Letter::C);
        Grid g1(p1, a1, b1, c1);

        Tile p2(3, 0, Letter::P);
        Tile a2(1, 2, Letter::A);
        Tile b2(1, 1, Letter::B);
        Tile c2(1, 0, Letter::C);
        Grid g2(p2, a2, b2, c2);

        ASSERT_EQ(misplaced_tiles(g1, g2), 3);
        /*
        g3 Grid:
                        [C][ ][ ][ ]
                        [ ][A][ ][ ]
                        [B][ ][ ][ ]
                        [ ][ ][ ][P]
        */
        Tile p3(3, 0, Letter::P);
        Tile a3(1, 2, Letter::A);
        Tile b3(0, 1, Letter::B);
        Tile c3(0, 3, Letter::C);
        Grid g3(p3, a3, b3, c3);

        ASSERT_EQ(misplaced_tiles(g3, g2), 2);
    }

    TEST(GridTest, TestManhattanDistance)
    {
        /*
        g1 grid:
                        [ ][C][ ][ ]
                        [P][A][ ][ ]
                        [ ][ ][ ][ ]
                        [B][ ][ ][ ]

        g2 grid:
                        [ ][ ][ ][ ]
                        [ ][A][ ][ ]
                        [ ][B][ ][ ]
                        [ ][C][ ][P]
        */
        Tile p1(0, 2, Letter::P);
        Tile a1(1, 2, Letter::A);
        Tile b1(0, 0, Letter::B);
        Tile c1(1, 3, Letter::C);
        Grid g1(p1, a1, b1, c1);

        Tile p2(3, 0, Letter::P);
        Tile a2(1, 2, Letter::A);
        Tile b2(1, 1, Letter::B);
        Tile c2(1, 0, Letter::C);
        Grid g2(p2, a2, b2, c2);

        ASSERT_EQ(manhattan_distance(g1, g2), 10);
        /*
        g3 Grid:
                        [C][ ][ ][ ]
                        [ ][A][ ][ ]
                        [B][ ][ ][ ]
                        [ ][ ][ ][P]
        */
        Tile p3(3, 0, Letter::P);
        Tile a3(1, 2, Letter::A);
        Tile b3(0, 1, Letter::B);
        Tile c3(0, 3, Letter::C);
        Grid g3(p3, a3, b3, c3);

        ASSERT_EQ(manhattan_distance(g3, g2), 5);
    }
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
