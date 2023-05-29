#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <algorithm>
#include <cmath>

class MagicalContainer {
  private:
    std::vector<int> elements;
    std::vector<int> primeIndices;   

  public:
    MagicalContainer();
    ~MagicalContainer();

    void add(int element);
    void remove(int element);
    int size() const;
    bool isPrime(int number) const;

    class AscendingIterator {
      private:
        const MagicalContainer* container;
        int index;


        public:
        AscendingIterator();
        ~AscendingIterator() = default;
        AscendingIterator(const AscendingIterator& other);

        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();

        beginAscending() const;
        endAscending() const;

        };

    class SideCrossIterator {
            private:
               const MagicalContainer* container;
               int index;
               bool fromBeginning;


            public:
            SideCrossIterator();
            ~SideCrossIterator() = default;
            SideCrossIterator(const SideCrossIterator& other);

            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();

            beginSideCross() const;
            endSideCross() const;


        };

    class PrimeIterator{
            private:
            const MagicalContainer* container;
            int index;


            public:
            PrimeIterator();
            ~PrimeIterator() = default;
            PrimeIterator(const SideCrossIterator& other);

            PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            
            beginPrime() const;
            endPrime() const;

        };

};
#endif