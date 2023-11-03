// Include necessary headers for input/output, strings, vectors, random numbers, and time.
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>

// Function prototypes
void printHangman(int guesses);
void printWord(const std::string& word, const std::vector<bool>& guessed);
bool isGameWon(const std::string& word, const std::vector<bool>& guessed);

// Main function of the program
int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // List of possible words to guess
    std::vector<std::string> words = {"programming", "threads", "inspire", "change", "happy", "coding"};
    // Select a random word from the list
    std::string wordToGuess = words[std::rand() % words.size()];

    // Initialize a vector to keep track of which letters have been guessed
    std::vector<bool> guessed(wordToGuess.length(), false);
    // Initialize a counter for incorrect guesses
    int incorrectGuesses = 0;
    // Set the maximum number of allowed incorrect guesses
    const int maxIncorrectGuesses = 6;

    // Main game loop
    while (incorrectGuesses < maxIncorrectGuesses) {
        // Print the current state of the hangman and word
        printHangman(incorrectGuesses);
        printWord(wordToGuess, guessed);

        // Prompt the user for a guess
        std::cout << "Enter your guess: ";
        char guess;
        std::cin >> guess;

        // Check if the guess is correct
        bool correctGuess = false;
        for (size_t i = 0; i < wordToGuess.length(); ++i) {
            if (wordToGuess[i] == guess && !guessed[i]) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        // If the guess was incorrect, increment the incorrect guesses counter
        if (!correctGuess) {
            ++incorrectGuesses;
        }

        // Check if the game has been won
        if (isGameWon(wordToGuess, guessed)) {
            printHangman(incorrectGuesses);
            printWord(wordToGuess, guessed);
            std::cout << "Congratulations! You've won!" << std::endl;
            return 0;
        }
    }

    // If the game loop ends, the player has lost
    printHangman(incorrectGuesses);
    std::cout << "Game Over! The word was: " << wordToGuess << std::endl;
    return 0;
}

// Function to print the current state of the hangman
void printHangman(int guesses) {
    std::cout << "--------\n";
    std::cout << "|      " << (guesses > 0 ? "|" : "") << "\n";
    std::cout << "|      " << (guesses > 1 ? "O" : "") << "\n";
    std::cout << "|     " << (guesses > 3 ? "/" : " ") << (guesses > 2 ? "|" : "") << (guesses > 4 ? "\\" : "") << "\n";
    std::cout << "|     " << (guesses > 5 ? "/" : " ") << " " << (guesses > 5 ? "\\" : "") << "\n";
    std::cout << "|\n";
    std::cout << "|\n";
}

// Function to print the current state of the word being guessed
void printWord(const std::string& word, const std::vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            std::cout << word[i];
        } else {
            std::cout << "_";
        }
        std::cout << " ";
    }
    std::cout << "\n\n";
}

// Function to check if the game has been won
bool isGameWon(const std::string& word, const std::vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (!guessed[i]) {
            return false;
        }
    }
    return true;
}
