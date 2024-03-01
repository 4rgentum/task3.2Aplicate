#include <iostream>
#include "Source/getnum.h"
#include <stdexcept>

int getUserInput() {
    int input;
    while (true) {
        try {
            std::cout << "Enter input signal (0 or 1): ";
            input = utils::getNum<int>(0, 1);
            break;
        } catch (const std::exception& e) {

            if (std::cin.eof()) {
              std::cout << std::endl;
              // Завершаем программу или выполняем другие действия по необходимости
              exit(1);
            }
          
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

bool continueOperation() {
    char choice;
    std::cout << "Do you want to perform another operation? (y/n): ";
    std::cin >> choice;
    if (std::cin.eof()) {
      throw std::runtime_error("It is EOF, sorry\n");
    }
    return (choice == 'y' || choice == 'Y');
}

void printStatus(int status) {
    std::cout << "Output status: " << status << std::endl;
}
