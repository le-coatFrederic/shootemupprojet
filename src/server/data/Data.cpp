#include "Data.hpp"
#include <algorithm>
#include <cstddef>
#include "../game/Party.hpp"


// constructors / destructors
template <typename T>
Data<T>::Data() {
    this->data;
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
    auto it = std::find(data.begin(), data.end(), cell);
    if (it != data.end())
        data.erase(it);
        delete cell;
}


template class Data<Party*>;