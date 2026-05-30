#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Reading {

    int hour {};
    double temperature {};
};

std::vector<Reading> read_temperature(const std::string& file_name) {
    
    std::ifstream input_file {file_name};

    if (!input_file) {

        throw std::runtime_error("Cannot open input file");
    }

    std::vector<Reading> readings {};

    int hour {};
    double temperature {};

    while (input_file >> hour >> temperature) {

        if (hour < 0 || hour > 23) {
            throw std::runtime_error("Hour out of range");
        }

        readings.push_back(Reading{hour, temperature});
    }

    return readings;
}

void write_temperatures(const std::vector<Reading>& readings, const std::string& file_name) {

    std::ofstream output_file {file_name};

    if (!output_file) {

        throw std::runtime_error("Cannot open output file");
    }

    for (const Reading& reading : readings) {

        output_file << "(" << reading.hour
    }
}