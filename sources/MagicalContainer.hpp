#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <algorithm>

namespace ariel{
class MagicalContainer {
  private:
    std::vector<int> elements;  

  public:
    MagicalContainer();
    ~MagicalContainer();

    void addElement(int element);
    void removeElement(int element);
    int size();
    std::vector<int> getElements() const; 


    class AscendingIterator {
      private:
        MagicalContainer* container;
        int index;

        public:
        AscendingIterator(MagicalContainer& container, int index);
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();

        AscendingIterator& operator=(const AscendingIterator& other);

        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();

        AscendingIterator begin();
        AscendingIterator end();
        };

    class SideCrossIterator {
      private:
        MagicalContainer* container;
        int left_index;
        int right_index;
        bool isEnd;


      public:
        SideCrossIterator(MagicalContainer& container, int left_index, int right_index, bool isEnd);
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();

        SideCrossIterator& operator=(const SideCrossIterator& other);

        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();

        SideCrossIterator begin();
        SideCrossIterator end();


        };

    class PrimeIterator{
      private:
        MagicalContainer* container;
        int index;
        bool isPrime(int n);


      public:
        PrimeIterator(MagicalContainer& container, int index);
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();

        PrimeIterator& operator=(const PrimeIterator& other);

        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();
            
        PrimeIterator begin();
        PrimeIterator end();

        };  
    };
}
#endif