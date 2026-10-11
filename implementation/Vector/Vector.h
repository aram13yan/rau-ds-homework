#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <utility>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void _resize_capacity(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    /// 1. Конструктор по умолчанию
    Vector() : _data(nullptr), _size(0), _capacity(0) {}

    /// 2. Конструктор с начальным размером
    Vector(size_t initial_size) : _size(initial_size), _capacity(initial_size) {
        _data = (_capacity > 0) ? new T[_capacity]() : nullptr;
    }

    /// 3. Деструктор
    ~Vector() {
        delete[] _data;
    }

    /// 4. Конструктор копирования
    Vector(const Vector& other) : _size(other._size), _capacity(other._capacity) {
        if (_capacity > 0) {
            _data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        else {
            _data = nullptr;
        }
    }

    /// 5. Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        if (_capacity > 0) {
            _data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        else {
            _data = nullptr;
        }
        return *this;
    }

    /// 6. push_back
    void push_back(const T& value) {
        if (_size == _capacity) {
            size_t new_cap = (_capacity == 0) ? 1 : _capacity * 2;
            reserve(new_cap);
        }
        _data[_size] = value;
        ++_size;
    }

    /// 7. pop_back
    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    /// 8. operator[]
    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    /// 9. at (с проверкой выхода за границы)
    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Vector index out of range");
        }
        return _data[index];
    }

    const T& at(size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Vector index out of range");
        }
        return _data[index];
    }

    /// 10. front
    T& front() {
        return _data[0];
    }

    const T& front() const {
        return _data[0];
    }

    /// 11. back
    T& back() {
        return _data[_size - 1];
    }

    const T& back() const {
        return _data[_size - 1];
    }

    /// 12. size
    size_t size() const {
        return _size;
    }

    /// 13. capacity
    size_t capacity() const {
        return _capacity;
    }

    /// 14. empty
    bool empty() const {
        return _size == 0;
    }

    /// 15. reserve
    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            _resize_capacity(new_capacity);
        }
    }

    /// 16. clear
    void clear() {
        _size = 0;
    }

    /// 17. begin
    T* begin() {
        return _data;
    }

    const T* begin() const {
        return _data;
    }

    /// 18. end
    T* end() {
        return _data + _size;
    }

    const T* end() const {
        return _data + _size;
    }

    void resize(size_t new_size) {
        if (new_size > _capacity) {
            reserve(new_size);
        }
        _size = new_size;
    }

    void swap(Vector& other) {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
    }
};

#endif // VECTOR_H