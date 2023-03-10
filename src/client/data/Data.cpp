#include "Data.hpp"
#include <cstddef>


// constructors / destructors
template <typename T>
Data<T>::Data() {
    this->data = nullptr;
}

template <typename T>
Data<T>::~Data() {
    for (T* cell : this->data)
        delete cell;
}

// accessors
template <typename T>
std::vector<T*> Data<T>::getData() {
    return this->data;
}

template <typename T>
void Data<T>::addEntity(T* cell) {
    if (cell != NULL)
        this->data.push_back(cell);
}

template <typename T>
void Data<T>::deleteCell(T* cell) {
    this->data.erase(cell);
}
