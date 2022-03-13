#include <bitset>
#include <functional>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "dataHandler.hpp"

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 3) {
        std::cout << "Usage: signup <username> <password>" ;
        return -1;
    }

    std::ofstream credentials("./credentials.txt", std::ofstream::app);
    std::ifstream readCredentials("./credentials.txt");

    std::string data ;
    while (std::getline(readCredentials, data)) {
        if (argv[1] == getUsername(data)) {
            std::cout << "Username already exists" ;
            return -1;
        }
    }

    data = ""; //reusing me variables
    data.append(argv[1]);
    data.append(":");
    data.append(argv[2]);
    data.append("\n");

    credentials << data ;
    credentials.close(); //i remembered it again lets go!!!
    std::cout << "Sucessfully registered! You can now login!" ;

    return 0;
}