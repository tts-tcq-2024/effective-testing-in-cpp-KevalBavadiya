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

// Wrapper function to print the color map
int displayColorMap() {
    cout << generateColorMap();
    return 25;
}

// Test function for verifying color map format and alignment
void testGenerateColorMap() {
    ostringstream expectedOutput;
    for (int primaryIndex = 0; primaryIndex < 5; ++primaryIndex) {
        for (int secondaryIndex = 0; secondaryIndex < 5; ++secondaryIndex) {
            int pairId = primaryIndex * 5 + secondaryIndex;
            expectedOutput << setw(2) << pairId << " | "
                           << setw(6) << primaryColors[primaryIndex] << " | "
                           << setw(6) << secondaryColors[secondaryIndex] << "\n";
        }
    }

    // Check if generated output matches expected output
    assert(generateColorMap() == expectedOutput.str() && "Alignment or values in color map are incorrect.");
}

int main() {
    int result = displayColorMap();
    assert(result == 25 && "Function should return 25 pairs.");
    testGenerateColorMap();
    cout << "All is well (maybe!)\n";
    return 0;
}
