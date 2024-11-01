#include <iostream>
#include <cassert>
using namespace std;

int alertFailureCount = 0;

// Modified alert function with conditional return to simulate both success and failure scenarios
int networkAlertStub(float temperatureInCelsius) {
    cout << "ALERT: Temperature is " << temperatureInCelsius << " degrees Celsius.\n";
    // Simulate a failure response if temperature exceeds a certain threshold
    return (temperatureInCelsius > 200.0) ? 500 : 200;
}

// Temperature alert function that incorporates proper failure counting
void sendAlertIfOverThreshold(float temperatureInFahrenheit) {
    float temperatureInCelsius = (temperatureInFahrenheit - 32.0) * (5.0 / 9.0);
    int responseCode = networkAlertStub(temperatureInCelsius);
    // Increment failure count if response code indicates failure
    if (responseCode != 200) {
        alertFailureCount++;
    }
}

int main() {
    sendAlertIfOverThreshold(400.5);  // Expected to trigger failure count increment
    sendAlertIfOverThreshold(303.6);  // Expected to succeed
    assert(alertFailureCount > 0);    // Should fail due to the original error
    cout << alertFailureCount << " alerts failed.\n";
    cout << "All is well (maybe!)\n";
    return 0;
}
