// main.cpp: Defines the entry point for the console application.
//
#include "stdafx.h"
#include "WordList.h"
const int wordLength = 5;
const int numberOfWords = 15;
int i;

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game
	int intLives = 4;
	int intNumRight;
	std::string strGuess;
	while (intLives > 0)
	{
		std::cout << "Enter your guess you have "<< intLives << " guesses left" << std::endl;
		std::cin >> strGuess;
		if (strGuess == secret)
		{
			std::cout << "You win!" << std::endl;
			std::cin.ignore();
			break;
		}
		else
		{
			intNumRight = 0;
			for (i = 0; i<(wordLength); i++) {
				if (secret[i] == strGuess[i])
				{
					intNumRight++;
				}
			}
			std::cout << "Incorrect " << intNumRight << "/" << wordLength <<std::endl;
			intLives--;
			if (intLives == 0)
			{
				std::cout << "You Loose" << std::endl;
				std::cin.ignore();
			}
		}
	}
	std::cin.ignore();
	return 0;
}
