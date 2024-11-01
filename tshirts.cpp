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
    assert(getSizeCategory(37) == 'S');
    assert(getSizeCategory(38) == 'M');
    assert(getSizeCategory(40) == 'M');
    assert(getSizeCategory(42) == 'M');
    assert(getSizeCategory(43) == 'L');
    cout << "All tests passed successfully (hopefully!)\n";
}

int main() {
    runTests();
    return 0;
}
