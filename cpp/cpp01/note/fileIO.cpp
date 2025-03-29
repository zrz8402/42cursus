#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

class Data {
public:
    int id;
    std::string name;

    void save(std::ofstream &out) {
        out << id << std::endl;
        out << name << std::endl;
    }

    void load(std::ifstream &in) {
        in >> id;
        in >> name;
    }
};

void basicFileReading() {
    std::cout << "=== Basic File Reading ===" << std::endl;
    std::ifstream inputFile("example.txt");
    std::string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void fileWritingWithModeFlags() {
    std::cout << "\n=== File Writing with Mode Flags ===" << std::endl;
    std::ofstream outputFile("example.txt", std::ios::app);
    
    if (outputFile.is_open()) {
        outputFile << "Appending a new line!" << std::endl;
        outputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void readingDifferentDataTypes() {
    std::cout << "\n=== Reading Different Data Types ===" << std::endl;
    int number;
    std::ifstream numberFile("numbers.txt");

    if (numberFile.is_open()) {
        numberFile >> number; // Attempt to read an integer

        if (numberFile.fail()) {
            std::cout << "Failed to read an integer from the file." << std::endl;
        } else {
            std::cout << "Read number: " << number << std::endl;
        }

        numberFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

    // std::vector<int> numbers;

    // if (numberFile.is_open()) {
    //     std::string line;
    //     while (getline(numberFile, line)) {
    //         std::istringstream ss(line);
    //         std::string token;
    //         while (getline(ss, token, ',')) {
    //             numbers.push_back(std::stoi(token)); // Convert string to int and store
    //         }
    //     }

    //     numberFile.close();

    //     std::cout << "Read numbers: ";
    //     for (int n : numbers) {
    //         std::cout << n << " ";
    //     }
    //     std::cout << std::endl;
    // } else {
    //     std::cout << "Unable to open file." << std::endl;
    // }
}

void errorHandling() {
    std::cout << "\n=== Error Handling ===" << std::endl;
    std::ifstream errorFile("nonexistent.txt");

    if (!errorFile) {
        std::cerr << "Error opening file!" << std::endl;
    }
}

void formattedIO() {
    std::cout << "\n=== Formatted I/O ===" << std::endl;
    std::ofstream formattedOutputFile("formatted_output.txt");

    if (formattedOutputFile.is_open()) {
        formattedOutputFile << std::fixed << std::setprecision(2) << 123.456; // Output: 123.46
        formattedOutputFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void readingLinesWithGetline() {
    std::cout << "\n=== Reading Lines with getline() ===" << std::endl;
    std::ifstream lineFile("example.txt");
    std::string line;

    if (lineFile.is_open()) {
        while (getline(lineFile, line)) {
            std::cout << line << std::endl;
        }
        lineFile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void combiningIfstreamAndOfstream() {
    std::cout << "\n=== Combining ifstream and ofstream ===" << std::endl;
    std::ifstream combineInputFile("input.txt");
    std::ofstream combineOutputFile("output.txt");
    std::string line;

    if (combineInputFile.is_open() && combineOutputFile.is_open()) {
        while (getline(combineInputFile, line)) {
            combineOutputFile << line << std::endl; // Write to output file
        }
        combineInputFile.close();
        combineOutputFile.close();
    } else {
        std::cout << "Unable to open one of the files" << std::endl;
    }
}

void objectSerialization() {
    std::cout << "\n=== Object Serialization ===" << std::endl;
    Data dataToSave;
    dataToSave.id = 1;
    dataToSave.name = "Sample Data";

    // Save to file
    std::ofstream outFile("data.txt");
    if (outFile.is_open()) {
        dataToSave.save(outFile);
        outFile.close();
    }

    // Load from file
    Data dataToLoad;
    std::ifstream inFile("data.txt");
    if (inFile.is_open()) {
        dataToLoad.load(inFile);
        inFile.close();
    }

    std::cout << "Loaded Data: " << dataToLoad.id << ", " << dataToLoad.name << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No function specified to run." << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::istringstream iss(input);
    std::string function;

    while (std::getline(iss, function, ',')) {
        int funcNum = std::stoi(function);
        switch (funcNum) {
            case 1:
                basicFileReading();
                break;
            case 2:
                fileWritingWithModeFlags();
                break;
            case 3:
                readingDifferentDataTypes();
                break;
            case 4:
                errorHandling();
                break;
            case 5:
                formattedIO();
                break;
            case 6:
                readingLinesWithGetline();
                break;
            case 7:
                combiningIfstreamAndOfstream();
                break;
            case 8:
                objectSerialization();
                break;
            default:
                std::cout << "Invalid function number: " << funcNum << std::endl;
        }
    }

    return 0;
}
