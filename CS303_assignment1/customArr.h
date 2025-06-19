#pragma once

#include <utility>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

template <typename T>
class customArr {
private:
    T* data;
    size_t size;

public:
    // Constructor and destructor
    customArr(size_t size);
    ~customArr();

    // Setters and getters
    void set(int index, const T& value);
    T get(int index) const;
    size_t getSize() const;

    // Class functions
    int search(const T& value) const;
    std::pair<T, T> replace(int index, T& newVal);
    void append(const T& value);
    T remove(const int& index);
};

template <typename T>
customArr<T>::customArr(size_t size) : size(size) {
    data = new T[size];
}

template <typename T>
customArr<T>::~customArr() {
    delete[] data;
}

template <typename T>
void customArr<T>::set(int index, const T& value) {
    if (index < 0 || static_cast<size_t>(index) >= size) {
        throw std::out_of_range("Index out of range, must provide a valid index to set");
    }
    data[index] = value;
}

template <typename T>
T customArr<T>::get(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= size) {
        throw std::out_of_range("Index out of range, must provide a valid index to get");
    }
    return data[index];
}

template <typename T>
size_t customArr<T>::getSize() const {
    return size;
}

template <typename T>
int customArr<T>::search(const T& value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) return static_cast<int>(i);
    }
    return -1;
}

template <typename T>
std::pair<T, T> customArr<T>::replace(int index, T& newVal) {
    if (index < 0 || static_cast<size_t>(index) >= size) {
        throw std::out_of_range("Index out of range, must provide a valid index to replace");
    }
    T oldVal = data[index];
    data[index] = newVal;
    return std::make_pair(oldVal, newVal);
}

template <typename T>
void customArr<T>::append(const T& value) {
    T* newData = new T[size + 1];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size += 1;
}

template <typename T>
T customArr<T>::remove(const int& index) {
    if (index < 0 || static_cast<size_t>(index) >= size) {
        throw std::out_of_range("Index out of range, must provide a valid index to remove");
    }

    T* newData = new T[size - 1];
    T delVal = data[index];

    for (size_t i = 0, j = 0; i < size; ++i) {
        if (static_cast<int>(i) == index) continue;
        newData[j++] = data[i];
    }

    delete[] data;
    data = newData;
    size -= 1;

    return delVal;
}

template <typename T>
customArr<T> import(std::string & fname) {
    std::ifstream file(fname);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + fname);
    }

    size_t count = 0;
    std::string line;

    // Count number of elements
    while (getline(file, line)) {
        std::stringstream ss(line);
        T temp;
        while (ss >> temp) ++count;
    }

    file.clear();
    file.seekg(0);

    customArr<T> arr(count);
    size_t index = 0;

    // Read elements into array
    while (getline(file, line)) {
        std::stringstream ss(line);
        T value;
        while (ss >> value) {
            arr.set(index++, value);
        }
    }

    file.close();
    return arr;
}
