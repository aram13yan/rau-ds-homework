#include <iostream>
#include <cassert>
#include "Vector.h"

void test_vector() {
    Vector<int> v;
    assert(v.empty());
    assert(v.size() == 0);

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    assert(v.size() == 3);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
    assert(v.front() == 10);
    assert(v.back() == 30);

    v.pop_back();
    assert(v.size() == 2);
    assert(v.back() == 20);

    assert(v.at(0) == 10);
    try {
        v.at(100);
        assert(false);
    }
    catch (const std::out_of_range&) {
    }

    Vector<int> copy_v = v;
    assert(copy_v.size() == 2);
    assert(copy_v[0] == 10);

    Vector<int> assigned_v;
    assigned_v = v;
    assert(assigned_v.size() == 2);
    assert(assigned_v[1] == 20);

    v.clear();
    assert(v.empty());
    assert(v.size() == 0);

    std::cout << "Тесты пройдены успешноо" << std::endl;
}

int main() {
    test_vector();
    return 0;
}