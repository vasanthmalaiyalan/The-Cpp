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

        output_file << "(" 
                    << reading.hour 
                    << ',' 
                    << reading.temperature 
                    << ")\n";
    }
}

int main() {

    try {

        const auto readings = read_temperatures("temps.txt");

        write_temperatures(readings, "formatted_temps.txt");

        std::cout << "Temperature data processed.\n";
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';

        return 1;
    }
}