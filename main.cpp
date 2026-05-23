// ##########################################################
// Tarea Corta 6 - Estructuras de Datos
// Edwin Andrey Muñoz Sandí 2025075200
// ############################################################

#include <iostream>
#include <random>
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

static int readOption(const string& prompt, int max) {
    while (true) {
        int option = readPositiveInt(prompt);
        if (option <= max)
            return option;
        cout << "Please select an option from the menu.\n";
    }
}

static int getMaxNum(LinkedList<int>& list) {
    list.goToStart();
    int max = 0;
    while (!list.atEnd()) {
        int num = list.getElement();
        if (num > max) max = num;
        list.next();
    }
    return max;
}

static int countDigits(LinkedList<int>& list, int base) {
    int maxNum = getMaxNum(list);
    int count = 1;
    while (maxNum >= base) {
        maxNum /= base;
        count++;
    }
    return count;
}

static void radixSort(LinkedList<int>& list, int base) {
    LinkedList<int>* buckets = new LinkedList<int>[base];
    int passes = countDigits(list, base);
    long long divisor = 1;

    while (passes != 0) {
        for (list.goToStart(); !list.atEnd(); list.next()) {
            int num = list.getElement();
            int index = (num / divisor) % base;
            buckets[index].append(num);
        }
        list.clear();
        for (int i = 0; i < base; i++) {
            for (buckets[i].goToStart(); !buckets[i].atEnd(); buckets[i].next())
                list.append(buckets[i].getElement());
            buckets[i].clear();
        }
        divisor *= base;
        passes--;
    }
    delete[] buckets;
}

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000000000);

    cout << "\tRadix Sort\n";
    int option = 1;
    while (option != 2) {
        cout << '\n';
        int size = readPositiveInt("Enter the size of the list to sort: ");
        int base = readPositiveInt("Enter the numeric base to use: ", 2);

        LinkedList<int> numbers;
        for (int i = 0; i < size; i++)
            numbers.append(dist(gen));

        cout << "\nUnsorted List:\n";
        numbers.print();

        cout << "\nSorted List:\n";
        radixSort(numbers, base);
        numbers.print();

        option = readOption("\nWould you like to sort another list?\n1. Yes\n2. No and exit\nOption: ", 2);
    }

    return 0;
}