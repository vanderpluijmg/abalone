#include <catch2/catch.hpp>
#include "abalonecore.h"

TEST_CASE("Regular starting moves white", "[moves][inbound]")
{
    SECTION("move 2pc right"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("H6G6");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,1)) == EMPTY);
    }
    SECTION("move 3pc right"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I5H5");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,0)) == EMPTY);
    }
    SECTION("move 3pc lateral right"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("G5G7F5");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(5,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(6,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(4,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(6,3)) == WHITE);
    }
    SECTION("move 3pc lateral left"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("G5G7F4");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(5,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(6,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(3,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,3)) == WHITE);
    }
    SECTION("move 2pc right"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("H6G5");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(3,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,1)) == EMPTY);
    }
    SECTION("move 3pc left"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I8H7");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(7,0)) == EMPTY);
    }

}

TEST_CASE("Regular movements pushings balls", "[moves][inbound][versus]"){
    SECTION("move 1 ball opp"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I7H6");
        game.applyMove(a,WHITE);
        MoveUtils ab = AbaPro::getCommand("A3B3");
        game.applyMove(ab,BLACK);
        MoveUtils ac = AbaPro::getCommand("H6G5");
        game.applyMove(ac,WHITE);
        MoveUtils ad = AbaPro::getCommand("B3C3");
        game.applyMove(ad,BLACK);
        REQUIRE(game.getBoard().getColor(Position(2,3)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(2,4)) == BLACK);
    }
    SECTION("move 2 ball opp nomove"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I5H5");
        game.applyMove(a,WHITE);
        MoveUtils ab = AbaPro::getCommand("B5C5");
        game.applyMove(ab,BLACK);
        MoveUtils ac = AbaPro::getCommand("H5G5");
        game.applyMove(ac,WHITE);
        MoveUtils ad = AbaPro::getCommand("C5D5");
        game.applyMove(ad,BLACK);
        REQUIRE(game.getBoard().getColor(Position(4,4)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,5)) == BLACK);
    }
    SECTION("move 2 ball opp move"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I5H5");
        game.applyMove(a,WHITE);
        MoveUtils ab = AbaPro::getCommand("B5C5");
        game.applyMove(ab,BLACK);
        MoveUtils ac = AbaPro::getCommand("H5G5");
        game.applyMove(ac,WHITE);
        MoveUtils ad = AbaPro::getCommand("C5D5");
        game.applyMove(ad,BLACK);
        MoveUtils ae = AbaPro::getCommand("A2B2");
        game.applyMove(ae,BLACK);
        MoveUtils af = AbaPro::getCommand("G5F5");
        game.applyMove(af,WHITE);

        REQUIRE(game.getBoard().getColor(Position(4,2)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(4,5)) == WHITE);
        REQUIRE(game.getBoard().getColor(Position(4,6)) == BLACK);
    }

    SECTION("move 3 ball opp"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I8H7");
        game.applyMove(a,WHITE);
        MoveUtils ab = AbaPro::getCommand("A2B2");
        game.applyMove(ab,BLACK);
        MoveUtils ac = AbaPro::getCommand("H7G6");
        game.applyMove(ac,WHITE);
        MoveUtils ad = AbaPro::getCommand("B3C3");
        game.applyMove(ad,BLACK);
        MoveUtils ae = AbaPro::getCommand("G6F5");
        game.applyMove(ae,WHITE);
        REQUIRE(game.getBoard().getColor(Position(2,5)) == BLACK);
        REQUIRE(game.getBoard().getColor(Position(3,4)) == WHITE);
    }
}
TEST_CASE("Regular movements outofBounds", "[moves][outbound]"){
    SECTION("move ball out of bounds"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("H6I7");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(5,1)) == EMPTY);
        REQUIRE(game.getBoard().getColor(Position(6,0)) == WHITE);
    }
    SECTION("move 3 ball white out of bounds"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("I5H4");
        game.applyMove(a,WHITE);
        MoveUtils ab = AbaPro::getCommand("A1B1");
        game.applyMove(ab,BLACK);
        MoveUtils ac = AbaPro::getCommand("H4G3");
        game.applyMove(ac,WHITE);
        MoveUtils ad = AbaPro::getCommand("B1C1");
        game.applyMove(ad,BLACK);
        MoveUtils ae = AbaPro::getCommand("G3F2");
        game.applyMove(ae,WHITE);
        MoveUtils af = AbaPro::getCommand("C1D1");
        game.applyMove(af,BLACK);
        REQUIRE(game.getBoard().getColor(Position(0,4)) == BLACK);
        REQUIRE(game.getBoard().getColor(Position(1,3)) == WHITE);
    }
    SECTION("move ball out of bounds"){
        Game game=Game();
        MoveUtils a = AbaPro::getCommand("G5H5");
        game.applyMove(a,WHITE);
        REQUIRE(game.getBoard().getColor(Position(2,4)) == EMPTY);
    }

}
