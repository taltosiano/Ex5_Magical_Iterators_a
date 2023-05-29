#include "catch.hpp"
#include "MagicalContainer.hpp"


TEST_CASE("MagicContainer"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.add(2);
    container.add(8);
    container.add(3);
    CHECK(container.size() == 3);

    container.remove(8);
    CHECK(container.size() == 2);
    container.remove(2);
    CHECK_THROWS(container.remove(2));
    container.remove(3);
    CHECK(container.size() == 0);

}

TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(4);
}

TEST_CASE("SideCrossIterator"){

}

TEST_CASE("PrimeIterator"){

}