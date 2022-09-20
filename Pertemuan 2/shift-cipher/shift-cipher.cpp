#include <iostream>
#include <string>

void encrypt(std::string, int);
void decrypt(std::string, int);

int main() 
{
    std::string message;
    int key;
    int op;

    std::cout << "Message\t: ";
    std::cin >> message;
    std::cout << "Key\t: ";
    std::cin >> key;
    std::cout << "1. Enkripsi\n2. Dekripsi\nPilihan\t: ";
    std::cin >> op;
    key = key % 26;

    switch(op) {
        case 1:
        encrypt(message, key);
        break;
        case 2:
        decrypt(message, key);
        break;
        default:
        std::cout << "Invalid input";
        break;
    }
}

void encrypt(std::string message, int key) {
    std::cout << "\nMessage\t: " << message << "\nKey\t: " << key <<"\n";
    std::string result = "";

    for(int i = 0; i < message.length(); i++) {
        if(message[i] == ' ') {
            result += ' ';
            continue;
        }
        if(isupper(message[i])) {
            result += char(int(message[i] + key - 65) % 26 + 65);
        }
        else {
            result += char(int(message[i] + key - 97) % 26 + 97);
        }
    }
    std::cout << "Hasil enkripsi : " << result;
}

void decrypt(std::string message, int key) {
    std::cout << "\nMessage\t: " << message << "\nKey\t: " << key <<"\n";
    std::string result = "";

    for(int i = 0; i < message.length(); i++) {
        if(message[i] == ' ') {
            result += ' ';
            continue;
        }
        if(isupper(message[i])) {
            result += char(int(message[i] + (26 - key) - 65) % 26 + 65);
        }
        else {
            result += char(int(message[i] + (26 - key) - 97) % 26 + 97);
        }
    }
    std::cout << "Hasil dekripsi : " << result;
}