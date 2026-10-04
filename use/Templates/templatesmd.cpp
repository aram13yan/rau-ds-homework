#include <iostream>
#include "Functions.h"
#include "Classes.h"
#include "Specalizations.h"

void testFunctions() {
    std::cout << "=== Template Functions Tests ===" << std::endl;

    std::cout << "printElement: ";
    printElement(100);
    printElement(3.14);
    printElement("Hello, RAU!");

    int a = 5, b = 20;
    std::cout << "Before mySwap: a=" << a << ", b=" << b << std::endl;
    mySwap(a, b);
    std::cout << "After mySwap: a=" << a << ", b=" << b << std::endl;
}

void testClasses() {
    std::cout << "\n=== Template Classes Tests ===" << std::endl;

    // Test Pair
    Pair<const char*, int> player("Level", 99);
    std::cout << "Pair test: ";
    player.print();

    // Test Range
    Range<int> myRange(1, 10);
    std::cout << "Range [1, 10] test:" << std::endl;
    std::cout << "Range length: " << myRange.length() << std::endl;
    std::cout << "Contains 5? " << (myRange.contains(5) ? "Yes" : "No") << std::endl;
}

void testSpecializations() {
    std::cout << "\n=== Specializations Tests ===" << std::endl;

    std::cout << "printValue (int): ";
    printValue(42);

    std::cout << "printValue (bool): ";
    printValue(true);

    std::cout << "printValue (const char*): ";
    printValue("Specialization works");

    std::cout << "\nisEqual(10, 10): " << (isEqual(10, 10) ? "Equal" : "Different") << std::endl;

    const char str1[] = "text";
    const char str2[] = "text";
    const char str3[] = "other";

    std::cout << "isEqual(\"text\", \"text\"): "
        << (isEqual<const char*>(str1, str2) ? "Equal" : "Different") << std::endl;

    std::cout << "isEqual(\"text\", \"other\"): "
        << (isEqual<const char*>(str1, str3) ? "Equal" : "Different") << std::endl;
}

int main() {
    testFunctions();
    testClasses();
    testSpecializations();

    return 0;
}
