#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;

    int userGuess = 0;

    std::cout << "I have generated a random number between 1 and 100. Can you guess it?\n";

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Too low. Try again.\n";
        } else if (userGuess > randomNumber) {
            std::cout << "Too high. Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number.\n";
        }
    }

    return 0;
}