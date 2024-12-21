#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib> // For simulating data

// Simulate GPS module
std::string getGPSCoordinates() {
    // Simulating GPS coordinates
    return "Latitude: 43.651070, Longitude: -79.347015";
}

// Simulate GSM module
void sendToServer(const std::string& data) {
    std::cout << "Sending data to server: " << data << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Data sent successfully!" << std::endl;
}

// Main vehicle tracking function
void vehicleTrackingSystem() {
    std::cout << "Initializing GPS-based Vehicle Tracking System...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    while (true) {
        // Retrieve GPS coordinates
        std::string gpsData = getGPSCoordinates();
        std::cout << "GPS Data Retrieved: " << gpsData << std::endl;

        // Send data to the server
        sendToServer(gpsData);

        // Wait for the next cycle (simulate real-time tracking)
        std::cout << "Waiting for the next update...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    try {
        vehicleTrackingSystem();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
