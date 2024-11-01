#include <iostream>
#include <cassert>
using namespace std;

int alertFailureCount = 0;

// Modified alert stub to simulate failure for every alert
int networkAlertStub(float temperatureInCelsius) {
    cout << "ALERT: Temperature is " << temperatureInCelsius << " degrees Celsius.\n";
    // Stub always returns a failure code (500)
    return 500;
}

// Temperature alert function that increments failure count on non-200 response
void sendAlertIfOverThreshold(float temperatureInFahrenheit) {
    float temperatureInCelsius = (temperatureInFahrenheit - 32.0) * (5.0 / 9.0);
    int responseCode = networkAlertStub(temperatureInCelsius);
    if (responseCode != 200) {
        alertFailureCount++;
    }
}

void runTests() {
    sendAlertIfOverThreshold(400.5);  // Exceeds threshold
    sendAlertIfOverThreshold(303.6);  // Exceeds threshold
    // Expect failure count to be at least 1 due to failure in response code
    assert(alertFailureCount == 0 && "Expected failure count to be zero but got incremented."); // Should fail
}

int main() {
    runTests();
    cout << alertFailureCount << " alerts failed.\n";
    return 0;
}
