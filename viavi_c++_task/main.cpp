using namespace std;
#include <iostream>
#include <fstream>
#include <regex>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>

// This code is designed to read phone numbers from a file and validate them based on certain criteria (checks if the phone number is exactly 11 digits long)
string generate_phone_number() {
    string prefixes[] = {"012", "011", "010", "015"};
    int randomPrefixIndex = rand() % 4;
    string phoneNumber = prefixes[randomPrefixIndex];

    for (int i = 0; i < 8; ++i) {
        phoneNumber += to_string(rand() % 10);
    }

    return phoneNumber;
}

class PhoneNo {
public:
     int num;
    void write_to_file(vector<string> phones)
    {
        ofstream file("phone_numbers.txt");

        for(int i = 0; i < phones.size(); i++) {
            file << phones[i] << endl;
        }

        //return file;
    }
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
  friend istream&operator>>(istream &input ,PhoneNo&x)
 {
     input>>x.num;
     return input ;
 }
};

int main() {
    PhoneNo PhoneNumber; 
    cin >> PhoneNumber;
    //generate and write numbers to file
    vector<string> phone_number;
    srand(static_cast<unsigned>(time(nullptr)));
    for(int i = 20; i > 0; i--) {
        string phoneNumber = generate_phone_number();
        phone_number.push_back(phoneNumber);
    }
    PhoneNumber.write_to_file(phone_number);

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
