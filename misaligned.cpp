#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

const char* primaryColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* secondaryColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Modified function to generate color map as a formatted string for testing
string generateColorMap() {
    ostringstream mapStream;
    for (int primaryIndex = 0; primaryIndex < 5; ++primaryIndex) {
        for (int secondaryIndex = 0; secondaryIndex < 5; ++secondaryIndex) {
            int pairId = primaryIndex * 5 + secondaryIndex;
            mapStream << setw(2) << pairId << " | "
                      << setw(6) << primaryColors[primaryIndex] << " | "
                      << setw(6) << secondaryColors[secondaryIndex] << "\n";
        }
    }
    return mapStream.str();
}

// Test function for verifying color map format and alignment
void testGenerateColorMap() {
    ostringstream expectedOutput;
    for (int primaryIndex = 0; primaryIndex < 5; ++primaryIndex) {
        for (int secondaryIndex = 0; secondaryIndex < 5; ++secondaryIndex) {
            int pairId = primaryIndex * 5 + secondaryIndex;
            // Intentionally create a mismatch in expected output
            expectedOutput << setw(2) << pairId << " | "
                           << setw(5) << primaryColors[primaryIndex] << " | "  // Incorrect width
                           << setw(7) << secondaryColors[secondaryIndex] << "\n"; // Incorrect width
        }
    }

    // Test should fail due to intentional mismatch in expected output
    assert(generateColorMap() == expectedOutput.str() && "Alignment or values in color map are incorrect.");
}

int main() {
    testGenerateColorMap();
    cout << "Color map tests completed.\n";
    return 0;
}
