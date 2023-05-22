#include <stdio.h>

uint8_t calculatePossibilityOfRain(int temperature, int humidity) {
    // Check the temperature and humidity thresholds for rain
    if (temperature > 25 && humidity > 70) {
        return 1;  // High possibility of rain
    } else {
        return 0;  // Low possibility of rain
    }
}