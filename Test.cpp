#include "catch.hpp"
#include "MagicalContainer.hpp"


TEST_CASE("MagicContainer"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(2);
    container.addElement(8);
    container.addElement(3);
    CHECK(container.size() == 3);

    container.removeElement(8);
    CHECK(container.size() == 2);
    container.removeElement(2);
    CHECK_THROWS(container.removeElement(2));
    container.removeElement(3);
    CHECK(container.size() == 0);

}

TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
}

TEST_CASE("SideCrossIterator"){

}

TEST_CASE("PrimeIterator"){

}