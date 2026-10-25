#include "Stack.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину

void test_constructor() {
    Stack<int> s;

    assert(s.size() == 0);
    assert(s.capacity() == 0);
    assert(s.is_empty());

    std::cout << "test_constructor passed" << std::endl;
}

void test_push() {
    Stack<int> s;

    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);

    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.pop();
    assert(s.size() == 2);
    assert(s.top() == 10);

    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.pop();
    assert(s.size() == 0);
    assert(s.is_empty());

    std::cout << "test_pop passed" << std::endl;
}

void test_top() {
    Stack<int> s;

    s.push(10);
    s.push(20);

    assert(s.top() == 20);

    s.top() = 50;
    assert(s.top() == 50);

    const Stack<int>& cs = s;
    assert(cs.top() == 50);

    std::cout << "test_top passed" << std::endl;
}

void test_size() {
    Stack<int> s;

    assert(s.size() == 0);

    s.push(10);
    assert(s.size() == 1);

    s.push(20);
    assert(s.size() == 2);

    s.pop();
    assert(s.size() == 1);

    std::cout << "test_size passed" << std::endl;
}

void test_capacity() {
    Stack<int> s;

    assert(s.capacity() == 0);

    s.push(10);
    assert(s.capacity() >= 1);

    s.push(20);
    s.push(30);
    assert(s.capacity() >= 3);
    assert(s.capacity() >= s.size());

    std::cout << "test_capacity passed" << std::endl;
}

void test_is_empty() {
    Stack<int> s;

    assert(s.is_empty());

    s.push(10);
    assert(!s.is_empty());

    s.pop();
    assert(s.is_empty());

    std::cout << "test_is_empty passed" << std::endl;
}

void test_clear() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    int oldCapacity = s.capacity();

    s.clear();

    assert(s.size() == 0);
    assert(s.is_empty());
    assert(s.capacity() == oldCapacity);

    s.push(40);
    assert(s.size() == 1);
    assert(s.top() == 40);

    std::cout << "test_clear passed" << std::endl;
}

void test_peek() {
    Stack<int> s;

    s.push(10);
    s.push(20);

    assert(s.peek() == 20);
    assert(s.size() == 2);

    s.peek() = 50;
    assert(s.top() == 50);

    const Stack<int>& cs = s;
    assert(cs.peek() == 50);

    std::cout << "test_peek passed" << std::endl;
}

void test_copy_constructor() {
    Stack<int> s;

    s.push(10);
    s.push(20);

    Stack<int> copy(s);

    assert(copy.size() == 2);
    assert(copy.capacity() == s.capacity());
    assert(copy.top() == 20);

    copy.top() = 100;

    assert(copy.top() == 100);
    assert(s.top() == 20);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment() {
    Stack<int> a;
    a.push(10);
    a.push(20);

    Stack<int> b;
    b.push(5);

    b = a;

    assert(b.size() == 2);
    assert(b.capacity() == a.capacity());
    assert(b.top() == 20);

    b.top() = 100;

    assert(b.top() == 100);
    assert(a.top() == 20);

    b = b;

    assert(b.size() == 2);
    assert(b.top() == 100);

    std::cout << "test_assignment passed" << std::endl;
}

void test_empty_copy() {
    Stack<int> a;
    Stack<int> b(a);

    assert(b.size() == 0);
    assert(b.is_empty());

    Stack<int> c;
    c.push(10);
    c = a;

    assert(c.size() == 0);
    assert(c.is_empty());

    std::cout << "test_empty_copy passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;

    test_constructor();
    test_push();
    test_pop();
    test_top();
    test_size();
    test_capacity();
    test_is_empty();
    test_clear();
    test_peek();
    test_copy_constructor();
    test_assignment();
    test_empty_copy();

    std::cout << "All tests passed" << std::endl;

    return 0;
}