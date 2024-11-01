#include <iostream>
#include <cassert>
using namespace std;

char getSizeCategory(int measurementInCm) {
    if (measurementInCm < 38) {
        return 'S';
    } 
    if (measurementInCm >= 38 && measurementInCm <= 42) {
        return 'M';
    } 
    return 'L';
}

void runTests() {
    // Intentionally set incorrect expected results to cause failure
    assert(getSizeCategory(37) == 'M'); // Should fail, expected 'S'
    assert(getSizeCategory(38) == 'L'); // Should fail, expected 'M'
    assert(getSizeCategory(40) == 'S'); // Should fail, expected 'M'
    assert(getSizeCategory(42) == 'M'); // Should fail if correct code, expected 'L'
    assert(getSizeCategory(43) == 'M'); // Should fail, expected 'L'
    cout << "All tests passed successfully (hopefully!)\n";
}

int main() {
    runTests();
    return 0;
}
