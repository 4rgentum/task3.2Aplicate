#include <iostream>
#include <limits>
#include <cstring>
#include <string>
#include "Source/logicalelement.h"
#include "Source/getnum.h"
#include "interfacefunc.h"
#include <stdexcept>

int main() {
    while (true) {
        try {
            std::cout << "Choose a logical operation (AND, OR, NOT, XOR, NOTAND, NOTOR): ";
            std::string operation;
            std::cin >> operation;

            if (std::cin.eof()) {
              std::cout << std::endl;
              // Завершаем программу или выполняем другие действия по необходимости
              exit(1);
            }

            if (operation == "NOT") {
                LogicElementClass::LogicElement logicElement(1, 2);
                
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);

                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::out);

                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::high);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                int inputStatus = getUserInput();
                if (inputStatus == 0) {
                    logicElement[0] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus == 1) {
                    logicElement[0] >> logicElement[1];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            } else if (operation == "AND") {
                LogicElementClass::LogicElement logicElement(2, 2);
              
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);
  
                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::in);
  
                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::low);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                logicElement[3].set_link_num(1);
                logicElement[3].set_status(signal::high);
                logicElement[3].set_link_num(0);
                logicElement[3].set_type(clamp_class::out);
    
                int inputStatus1 = getUserInput();
                int inputStatus2 = getUserInput();

                if ((inputStatus1 == 0 && inputStatus2 == 0) ||
                    (inputStatus1 == 1 && inputStatus2 == 0) ||
                    (inputStatus1 == 0 && inputStatus2 == 1)) {
                    logicElement[0] >> logicElement[2];
                    logicElement[1] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus1 == 1 && inputStatus2 == 1) {
                    logicElement[0] >> logicElement[3];
                    logicElement[1] >> logicElement[3];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            } else if (operation == "OR") {
                LogicElementClass::LogicElement logicElement(2, 2);
                
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);

                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::in);

                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::low);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                logicElement[3].set_link_num(1);
                logicElement[3].set_status(clamp_class::high);
                logicElement[3].set_link_num(0);
                logicElement[3].set_type(clamp_class::out);

                int inputStatus1 = getUserInput();
                int inputStatus2 = getUserInput();

                if ((inputStatus1 == 0 && inputStatus2 == 1) ||
                    (inputStatus1 == 1 && inputStatus2 == 0) ||
                    (inputStatus1 == 1 && inputStatus2 == 1)) {
                    logicElement[0] >> logicElement[3];
                    logicElement[1] >> logicElement[3];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus1 == 0 && inputStatus2 == 0) {
                    logicElement[0] >> logicElement[2];
                    logicElement[1] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            } else if (operation == "XOR") {
                LogicElementClass::LogicElement logicElement(2, 2);
              
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);

                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::in);

                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::low);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                logicElement[3].set_link_num(1);
                logicElement[3].set_status(clamp_class::high);
                logicElement[3].set_link_num(0);
                logicElement[3].set_type(clamp_class::out);

                int inputStatus1 = getUserInput();
                int inputStatus2 = getUserInput();

                if ((inputStatus1 == 1 && inputStatus2 == 0) ||
                    (inputStatus1 == 0 && inputStatus2 == 1)) {
                    logicElement[0] >> logicElement[3];
                    logicElement[1] >> logicElement[3];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus1 == 1 && inputStatus2 == 1) {
                    logicElement[0] >> logicElement[2];
                    logicElement[1] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            } else if (operation == "NOTAND") {
                LogicElementClass::LogicElement logicElement(2, 2);
                
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);

                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::in);

                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::low);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                logicElement[3].set_link_num(1);
                logicElement[3].set_status(clamp_class::high);
                logicElement[3].set_link_num(0);
                logicElement[3].set_type(clamp_class::out);

                int inputStatus1 = getUserInput();
                int inputStatus2 = getUserInput();

                if ((inputStatus1 == 0 && inputStatus2 == 0) ||
                    (inputStatus1 == 1 && inputStatus2 == 0) ||
                    (inputStatus1 == 0 && inputStatus2 == 1)) {
                    logicElement[0] >> logicElement[3];
                    logicElement[1] >> logicElement[3];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus1 == 1 && inputStatus2 == 1) {
                    logicElement[0] >> logicElement[2];
                    logicElement[1] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            } else if (operation == "NOTOR") {
                LogicElementClass::LogicElement logicElement(2, 2);
                
                logicElement[0].set_link_num(1);
                logicElement[0].set_status(clamp_class::low);
                logicElement[0].set_link_num(0);
                logicElement[0].set_type(clamp_class::in);

                logicElement[1].set_link_num(1);
                logicElement[1].set_status(clamp_class::low);
                logicElement[1].set_link_num(0);
                logicElement[1].set_type(clamp_class::in);

                logicElement[2].set_link_num(1);
                logicElement[2].set_status(clamp_class::low);
                logicElement[2].set_link_num(0);
                logicElement[2].set_type(clamp_class::out);

                logicElement[3].set_link_num(1);
                logicElement[3].set_status(clamp_class::high);
                logicElement[3].set_link_num(0);
                logicElement[3].set_type(clamp_class::out);

                int inputStatus1 = getUserInput();
                int inputStatus2 = getUserInput();

                if ((inputStatus1 == 0 && inputStatus2 == 1) ||
                    (inputStatus1 == 1 && inputStatus2 == 0) ||
                    (inputStatus1 == 1 && inputStatus2 == 1)) {
                    logicElement[0] >> logicElement[2];
                    logicElement[1] >> logicElement[2];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                } else if (inputStatus1 == 0 && inputStatus2 == 0) {
                    logicElement[0] >> logicElement[3];
                    logicElement[1] >> logicElement[3];
                    printStatus(static_cast<int>(logicElement[0].get_signal()));
                }
            }

            if (!continueOperation()) {
                break;
            }
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

    return 0;
}
