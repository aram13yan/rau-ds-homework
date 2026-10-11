#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList();

    /// 2. Деструктор
    ~ForwardList();

    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other);

    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other);

    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x);

    /// 6. pop_front() - удалить с начала
    void pop_front();

    /// 7. front() - первый элемент
    T& front();
    const T& front() const;

    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value);

    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node);

    /// 10. clear() - очистить
    void clear();

    /// 11. reverse() - развернуть
    void reverse();

    /// 12. size() - количество элементов
    int size() const;

    /// 13. empty() - пуст ли
    bool empty() const;

    /// 14. begin() - начало списка
    Node* begin();
    Node* begin() const;
};

#endif // FORWARDLIST_H


// 1. Конструктор по умолчанию
template <typename T>
ForwardList<T>::ForwardList() : _head(nullptr), _size(0) {}

// 2. Деструктор
template <typename T>
ForwardList<T>::~ForwardList() {
    while (_head != nullptr) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    }
}



// 5. push_front
template <typename T>
void ForwardList<T>::push_front(const T& x) {
    Node* new_node = new Node(x);
    new_node->next = _head;
    _head = new_node;
    _size++;
}

// 6. pop_front
template <typename T>
void ForwardList<T>::pop_front() {
    if (_head == nullptr) {
        return;
    }
    Node* tmp = _head;
    _head = _head->next;
    delete tmp;
    _size--;
}

// 7. front
template <typename T>
T& ForwardList<T>::front() {
    return _head->data;
}

// 8. clear
template <typename T>
void ForwardList<T>::clear() {
    while (_head != nullptr) {
        pop_front();
    }
}

// 9. size
template <typename T>
int ForwardList<T>::size() const{
    return _size;
}

// 10. reverse
template <typename T>
void ForwardList<T>::reverse() {
    typename ForwardList<T>::Node* prev = nullptr;
    typename ForwardList<T>::Node* current = _head;
    typename ForwardList<T>::Node* next_node = nullptr;

    while (current != nullptr) {
        next_node = current->next;
        current->next = prev;
        prev = current;
    }
    current = next_node;
}