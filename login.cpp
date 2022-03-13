#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "./dataHandler.hpp"


int main(int argc, char **argv) {
    if (argc < 3) {
        printf("\nUsage: login <username> <password>\n") ;
        return -1 ;
    }
    
    std::ifstream credentials("./credentials.txt") ;

    //check if user exists
    std::string data ;
    bool exists = false ;
    while (std::getline(credentials, data)) 
    {
        if (argv[1] == getUsername(data)) {
            //if user exists check password
            if (argv[2] == getPassword(data)) {
                std::cout << "\nLogged in successfully!\n" ;
                return 0;
            } 
            else {
                break ;
            }
        } 
        else {
            continue ;
        }
    }
    

    std::cout << "\nUsername or password is incorrect.\n";
    
    return 0;
}