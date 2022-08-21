#include <io.h>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    srand(time(NULL));

    std::string Characters = {
        std::string("1234567890")
        + "abcdefghijkmnopqrstuvwxyz"
        + "ABCDEFGHIJKMNOPQRSTUVWXYZ"
    };

    while (true) {
        std::ofstream Codes("codes.txt");
        std::string Code = "https://discord.gift/";

        for (uint8_t I = 0; I < 16; I++) {
            Code += Characters[rand() % (Characters.length() - 1)];
        };

        std::cout << Code << '\n';
        Codes << Code << '\n';
        Codes.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}