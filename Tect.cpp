#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

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
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(5));
    CHECK_NOTHROW(container.addElement(7));

    MagicalContainer::AscendingIterator ascIter(container);

    auto it = ascIter.begin();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 5);

}

TEST_CASE("SideCrossIterator"){
    MagicalContainer container;
    container.addElement(12);
    container.addElement(13);
    container.addElement(14);

    MagicalContainer::SideCrossIterator sideIter(container);
    auto it = sideIter.begin();
    CHECK_EQ(*it, 12);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 13);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 14);
    CHECK_NOTHROW(++it);

    container.removeElement(13);   
    CHECK(container.size() == 2);

}

TEST_CASE("PrimeIterator"){
    MagicalContainer container;
    container.addElement(12);
    container.addElement(15);
    container.addElement(16);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(container);

    auto it = primeIter.begin();
    auto it2 = primeIter2.end();
    CHECK_EQ(*it, 12);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 15);
    CHECK_FALSE(primeIter != primeIter2);
}
