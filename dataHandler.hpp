std::string getUsername(std::string credentials) {
    int splitCharacter = credentials.find(':');
    std::string username = credentials.substr(0, splitCharacter);

    return username ;
}

std::string getPassword(std::string credentials) {
    int splitCharacter = credentials.find(':') ;
    std::string password = credentials.substr(splitCharacter + 1, credentials.length()) ;

    return password ;
}

//do hashing here