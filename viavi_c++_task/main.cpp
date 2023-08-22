using namespace std;
#include <iostream>
#include <fstream>
#include <regex>

// This code is designed to read phone numbers from a file and validate them based on certain criteria (checks if the phone number is exactly 11 digits long)

class PhoneNo {
public:
    string readFile(const string& filename) {
        ifstream file(filename);
        string content;
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                content += line + "\n";
            }
            file.close();
            return content;
        }
        else {
            cout << "Unable to open file for reading." << endl;
            return "";
        }
    }

    bool validatePhoneNumber(const string& phoneNumber) {
        // Remove any non-digit characters from the phone number
        string digitsOnly = regex_replace(phoneNumber, regex("\\D"), "");

        // Check if the phone number is exactly 11 digits long
        return (digitsOnly.length() == 11);
    }
};

int main() {
    PhoneNo PhoneNumber;

    // Read from a file
    string content = PhoneNumber.readFile("phone_numbers.txt");
    cout << "File content: " << content << endl;

    // Validate phone numbers
    istringstream iss(content);
    string phoneNumber;
    while (getline(iss, phoneNumber)) {
        bool isValid = PhoneNumber.validatePhoneNumber(phoneNumber);
        cout << "Phone number: " << phoneNumber << " is " << (isValid ? "valid" : "invalid") << endl;
    }

    return 0;
}
