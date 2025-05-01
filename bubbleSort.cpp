// Copyright (c) 2025 Jack Turcotte All rights reserved.
//
// Created by: Jack Turcotte
// Date: April 29, 2025
// Bubblesort program in C++

#include <iostream>
#include <vector>
#include <string>

// Generate an array with random numbers
std::vector<int> setupArray(int length) {
    std::vector<int> array;
    for (int i = 0; i < length; i++) {
        array.push_back(rand() % 99 + 1);  // Numbers from 1 to 99
    }
    return array;
}

// Perform bubble sort and update the sorted array + iteration count
std::vector<int> bubbleSort(std::vector<int> inputArray) {
    int length = inputArray.size();
    int iterations = 0;

    std::string red = "\033[91m";
    std::string reset = "\033[0m";

    while (true) {
        bool isSorted = true;

        for (int i = 1; i < length; i++) {
            if (inputArray[i - 1] > inputArray[i]) {
                isSorted = false;
                break;
            }
        }

        if (isSorted) break;

        for (int i = 1; i < length; i++) {
            iterations+=1;

            if (inputArray[i - 1] > inputArray[i]) {
                for (int j = 0; j < length; j++) {
                    if (j == i || j == i - 1)
                        std::cout << red << inputArray[j] << reset << " ";
                    else
                        std::cout << inputArray[j] << " ";
                }
                std::cout << std::endl;

                // Swapping indexes
                int temp = inputArray[i - 1];
                inputArray[i - 1] = inputArray[i];
                inputArray[i] = temp;
            }
        }
    }

    // Display iterations and return the input array
    std::cout << "Iterations: " << iterations << std::endl;
    return inputArray;
}

int main() {
    srand(time(0));  // Seed for random number generator

    while (true) {
        int length;

        // Get length of array
        std::cout << "Please enter an integer length for your array: ";
        std::cin >> length;

        try {
            // Call setup array function
            std::vector<int> originalArray = setupArray(length);

            // Display original array
            std::cout << "Your array is: ";
            for (int num : originalArray) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            // Initialize sorted array

            std::vector<int> sortedArray;

            // Initialize iterations, sort array
            int iterations;
            sortedArray = bubbleSort(originalArray);

            // Show original array
            std::cout << "Your original array was: ";
            for (int num : originalArray) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            // Show new array
            std::cout << "Your new array is: ";
            for (int num : sortedArray) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            std::cout << "The worst case would have been " << length * length
            << " iterations." << std::endl;

            // Prompt restart
            std::string restart;
            std::cout << "Try again? (yes/no): ";
            std::cin >> restart;

            if (restart != "yes") {
                std::cout << "Thanks for using my sorting program!"
                << std::endl;
                break;
            }
        } catch(std::invalid_argument) {
            // Warn user, enter positive integer
            std::cout << "Please enter a positive integer!" << std::endl;
        }
    }
}
