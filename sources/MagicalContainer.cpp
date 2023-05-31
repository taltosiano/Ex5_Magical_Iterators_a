#include "MagicalContainer.hpp"

using namespace std;
namespace ariel{

   MagicalContainer::MagicalContainer() {}

   MagicalContainer::~MagicalContainer() {}
    
    void MagicalContainer::addElement(int element) {
       elements.push_back(element);
    //   if (isPrime(element))
    //      primeIndices.push_back(container.size() - 1);  // (element)
}
    
    void MagicalContainer::removeElement(int element) {
       // elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
        }

    //     auto it = find(container.begin(), container.end(), element);
    //     if (it != container.end()) {
    //         container.erase(it);
    //         primeIndices.clear();
    //         for (int i = 0; i < container.size(); i++) {
    //             if (isPrime(container[i]))
    //                 primeIndices.push_back(i);
    //     }
    //   }
    }
    
    int MagicalContainer::size(){
        return elements.size();
    }

    vector<int> MagicalContainer::getElements() const{
        return elements;
    }

//--------------AscendingIterator---------------//

   
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, int index) : container(container), index(index) {}
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) :
        container(other.container), index(other.index) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if(this != &other) {
            this->container = other.container;
            this->index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return (this->container == other.container && this->index == other.index);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return (this->index > other.index);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return (this->index < other.index);
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        //return container->getElements().at((std::vector<int>::size_type)index);
        return container->elements[(std::vector<int>::size_type)index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        index++;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        // return *this;
        return AscendingIterator(*container,0);

    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return AscendingIterator(*container,container->size());
        
        // AscendingIterator itr(*this);
        // itr.index = container->elements.size();
        // return itr;
    }


//--------------SideCrossIterator---------------//


   
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, int left_index, int right_index, bool isEnd) : 
    container(&container), left_index(0), right_index(container.size() - 1), isEnd(true){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : 
    container(&container), left_index(0), right_index(container.size() - 1), isEnd(true){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) :
    container(other.container), left_index(other.left_index), right_index(other.right_index), isEnd(other.isEnd) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if(this != &other) {
            this->container = other.container;
            this->left_index = other.left_index;
            this->right_index = other.right_index;
            this->isEnd = other.isEnd;
        }
        return *this;
   }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return (this->container == other.container && this->left_index == other.left_index && this->right_index == other.right_index && this->isEnd == other.isEnd);
   }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return (this->left_index > other.left_index || (this->left_index == other.left_index && this->right_index > other.right_index));
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return (this->left_index < other.left_index || (this->left_index == other.left_index && this->right_index < other.right_index));
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        //return container->elements[static_cast<int>(left_index * container->size() + right_index)];
        if (isEnd)
            return container->elements[(std::vector<int>::size_type)right_index];
        else
            // return container.elements[(std::vector<int>::size_type)endIndex];
            return container->elements[(std::vector<int>::size_type)(container->size() - right_index )];
    }
    

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (right_index == container->size() - 1 && left_index == container->size() - 1) {
        isEnd = true;
    }
    else if (right_index == 0 && left_index == container->size() - 1) {
        right_index++;
    }
    else if (left_index == container->size() - 1) {
        left_index--;
        right_index++;
    }
    else if (right_index == container->size() - 1) {
        left_index++;
    }
    else if (isEnd) {
        left_index++;
        right_index--;
    }
    else {
        left_index--;
        right_index++;
    }
    isEnd = !isEnd;
    return *this;
}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        // SideCrossIterator it(*this);
        // it.container = container;
        // it.left_index = 0;
        // it.right_index = 0;
        // it.isEnd = false;
        // return it;
        return SideCrossIterator(*container,0,0,true);

    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        // SideCrossIterator it(*this);
        // it.container = container;
        // it.left_index = container->size() - 1;
        // it.right_index = container->size() - 1;
        // it.isEnd = true;
        // return it;
        return SideCrossIterator(*container,container->size(),container->size(),false);
        //return SideCrossIterator(*container, -1, -1, false);
    }




//--------------PrimeIterator---------------//

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, int index) : 
        container(&container), index(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : 
        container(&container), index(0) {}
    // MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) {
    //     this->container = &container;
    //     index = 0;
    //     while (index < container.size() && !isPrime(container.container[static_cast<std::vector<int>::size_type>(index)])) {
    //         index++;
    //     }


    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) :
        container(other.container), index(other.index) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if(this != &other) {
          //  this->container = other.container;
            this->index = other.index;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return (this->container == other.container && this->index == other.index);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
         return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return (this->index > other.index);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return (this->index < other.index);
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        // return container->elements[static_cast<std::vector<int>::size_type>(index)];
        return container->elements[(std::vector<int>::size_type)index];

    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        index++;
        while (index < container->size() && !isPrime(container->getElements().at((std::vector<int>::size_type)index))) {
            index++;
        }
        return *this;
    }


    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(*container, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        // PrimeIterator it(*this);
        // it.index = container->size();
        // return it;
        return PrimeIterator(*container,container->size());

    }

    bool MagicalContainer::PrimeIterator::isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
    }
