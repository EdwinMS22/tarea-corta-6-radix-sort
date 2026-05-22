// ##########################################################
// Tarea Corta 6 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "LinkedList.h"

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

static int randomBig() {
    return (std::rand() << 15) | std::rand();
}

static void radixSort(const LinkedList<int>& list, int base) {
    LinkedList<int>* buckets = new LinkedList<int>[base];

    buckets->print();
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int option = -1;
    while (option != 0) {
        cout << "\tRadix Sort\n\n";
        int size = readPositiveInt("Enter the size of the list to sort: ");
        int base = readPositiveInt("Enter the numeric base to use: ", 2);

        LinkedList<int> numbers;
        for (int i = 0; i < size; i++)
            numbers.append(randomBig());

        radixSort(numbers, base);

        option = 0;
    }

    return 0;
}