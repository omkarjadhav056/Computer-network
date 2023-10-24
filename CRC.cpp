CRC.txt
//write a program for error detection and correction for 7 or 8 bits ASCII codes using CRC

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

using namespace std;

// Function to calculate CRC
string calculateCRC(string data, string generator) {
    int dataLength = data.length();
    int generatorLength = generator.length();
    int totalLength = dataLength + generatorLength - 1;

    // Append zeros to the data to make space for the CRC bits
    for (int i = 0; i < generatorLength - 1; i++) {
        data += '0';
    }

    bitset<32> inputData(data);
    bitset<32> inputGenerator(generator);

    for (int i = 0; i < dataLength; i++) {
        if (inputData[i]) {
            inputData ^= (inputGenerator << (totalLength - i));
        }
    }

    string crc = inputData.to_string().substr(dataLength);

    return crc;
}

int main() {
    string data;
    string generator = "110"; // 3-bit generator polynomial for CRC-3

    cout << "Enter data (8-bit ASCII): ";
    getline(cin, data);

    string crc = calculateCRC(data, generator);

    cout << "CRC (Generated): " << crc << endl;

    // Simulate transmission by adding CRC to the data
    string transmittedData = data + crc;

    cout << "Transmitted Data: " << transmittedData << endl;

    // Simulate an error in transmission (bit flip)
    transmittedData[5] = (transmittedData[5] == '0') ? '1' : '0';

    cout << "Received Data (with error): " << transmittedData << endl;

    string receivedData = transmittedData; // In a real scenario, data would be received

    // Check CRC
    string receivedCRC = receivedData.substr(data.length());
    string recalculatedCRC = calculateCRC(receivedData.substr(0, data.length()), generator);

    if (recalculatedCRC == receivedCRC) {
        cout << "CRC Check: Data is correct." << endl;
    } else {
        cout << "CRC Check: Data is corrupted." << endl;
    }

    return 0;
}
