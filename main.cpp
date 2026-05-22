// ##########################################################
// Tarea Corta 6 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;

static int readPositiveInt(const string& prompt, int min=1) {
    while (true) {
        cout << prompt;
        string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        int value{};
        if ((iss >> value) && (iss >> std::ws).eof() && value >= min)
            return value;
        cout << "Please enter an integer greater than or equal to " << min << ". Try again.\n";
    }
}

int main() {
    int option = -1;
    while (option != 0) {
        cout << "\tRadix Sort\n\n";
        int size = readPositiveInt("Enter the size of the list to sort: ");

        option = 0;
    }

    return 0;
}