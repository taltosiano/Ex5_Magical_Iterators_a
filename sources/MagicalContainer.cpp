#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel{

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}
    
    void MagicalContainer::add(int element) {
      elements.push_back(element);
      if (isPrime(element))
         primeIndices.push_back(elements.size() - 1);  // (element)
}
    
    void MagicalContainer::remove(int element) {
        // for (auto it = elements.begin(); it != elements.end(); ++it) {
        //     if (*it == element) {
        //         elements.erase(it);
        //         break;
        //     }
        // }

    //     auto it = find(elements.begin(), elements.end(), element);
    //     if (it != elements.end()) {
    //         elements.erase(it);
    //         primeIndices.clear();
    //         for (int i = 0; i < elements.size(); i++) {
    //             if (isPrime(elements[i]))
    //                 primeIndices.push_back(i);
    //     }
    //   }
    }
    
    int MagicalContainer::size() const {
        return elements.size();
    }

    bool MagicalContainer::isPrime(int number) const {
    //     if (number < 2)
    //         return false;
    //     for (int i = 2; i <= std::sqrt(number); i++) {
    //         if (number % i == 0)
    //             return false;
    //     }
    //     return true;
    // }
}

//--------------AscendingIterator---------------//

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer* container, int index = 0) :
        container(container), index(index) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}

   // AscendingIterator::~AscendingIterator() {}

   MagicalContainer::AscendingIterator::AscendingIterator& operator=(const AscendingIterator& other) {
   }

   bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return true;
   }

    bool operator!=(const AscendingIterator& other) const {
        return true;
    }

    bool operator>(const AscendingIterator& other) const {
        return true;
    }

    bool operator<(const AscendingIterator& other) const {
        return true;
    }

    int operator*() const {
        return true;
    }

    AscendingIterator& operator++() {
        return true;
    }

    MagicalContainer::AscendingIterator MagicalContainer::beginAscending() const {
        return AscendingIterator(this);
    }

    MagicalContainer::AscendingIterator MagicalContainer::endAscending() const {
        return AscendingIterator(this, data.size());
    }


//--------------SideCrossIterator---------------//


    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer* container, int index = 0) :
        container(container), index(index) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}

   // AscendingIterator::~AscendingIterator() {}

   MagicalContainer::SideCrossIterator::SideCrossIterator& operator=(const SideCrossIterator& other) {
   }

   bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return true;
   }

    bool operator!=(const SideCrossIterator& other) const {
        return true;
    }

    bool operator>(const SideCrossIterator& other) const {
        return true;
    }

    bool operator<(const SideCrossIterator& other) const {
        return true;
    }

    int operator*() const {
        return true;
    }

    SideCrossIterator& operator++() {
        return true;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::beginSideCross() const {
        return SideCrossIterator(this);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::endSideCross() const {
        return SideCrossIterator(this, data.size() - 1, false);
    }

//--------------PrimeIterator---------------//

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer* container, int index = 0) :
        container(container), index(index) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}

   // AscendingIterator::~AscendingIterator() {}

   MagicalContainer::PrimeIterator::PrimeIterator& operator=(const PrimeIterator& other) {
   }

   bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return true;
   }

    bool operator!=(const PrimeIterator& other) const {
        return true;
    }

    bool operator>(const PrimeIterator& other) const {
        return true;
    }

    bool operator<(const PrimeIterator& other) const {
        return true;
    }

    int operator*() const {
        return true;
    }

    PrimeIterator& operator++() {
        return true;
    }

    MagicalContainer::PrimeIterator MagicalContainer::beginPrime() const {
        return PrimeIterator(this);
    }

    MagicalContainer::PrimeIterator MagicalContainer::endPrime() const {
        return PrimeIterator(this, primeIndices.size());
    }
}