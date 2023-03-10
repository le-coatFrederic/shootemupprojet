#ifndef DATA_IMPL_HPP
#define DATA_IMPL_HPP

#include <algorithm>
#include <cstddef>
#include <vector>
#include "Data.hpp"

template <typename T>
Data<T>::Data() {
}

template <typename T>
Data<T>::~Data() {
    for (T cell : this->data)
        delete cell;
}

template <typename T>
std::vector<T> Data<T>::getData() {
    return this->data;
}

template <typename T>
void Data<T>::addEntity(T cell) {
    if (cell != NULL)
        this->data.push_back(cell);
}

template <typename T>
void Data<T>::deleteCell(T cell) {
    auto it = std::find(data.begin(), data.end(), cell);
    if (it != data.end())
        data.erase(it);
}

#endif /* DATA_IMPL_HPP */
