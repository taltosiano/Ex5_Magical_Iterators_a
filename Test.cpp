#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace std;
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
    CHECK_THROWS(container.removeElement(2));  // already removed
    container.removeElement(3);
    CHECK(container.size() == 0);

}

TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(8));
    CHECK_NOTHROW(container.addElement(3));      // 2 3 8 

    MagicalContainer::AscendingIterator ascIter(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIterCopy(ascIter));  // copy constructor

    auto it = ascIter.begin();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);        // sorted after add element
}

TEST_CASE("SideCrossIterator"){
    MagicalContainer container;
    container.addElement(12);
    container.addElement(15);
    container.addElement(14);
    container.addElement(13);

    MagicalContainer::SideCrossIterator sideIter(container);
    auto it = sideIter.begin();
    CHECK_EQ(*it, 12);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 15);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 13);
    CHECK_NOTHROW(++it);

    container.removeElement(13);   
    CHECK(container.size() == 3);

}

TEST_CASE("PrimeIterator"){
    MagicalContainer container;
    container.addElement(2);
    container.addElement(15);
    container.addElement(11);
    container.addElement(16);          // 2 11
    MagicalContainer::PrimeIterator primeIter(container);
    auto it = primeIter.begin();
    auto it2 = primeIter.end();

    CHECK(*it > *it2);    
    CHECK_FALSE(*it < *it2);
    CHECK(*it != *it2);

    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 11);
    CHECK_NOTHROW(++it);
    CHECK_FALSE(*it != *it2);  // they equal, it arrived the end
    
}
