/*Name: Matthew Berasa
  Date: 07/25/2025
  Math Game: User can play addition, multiplication, or guessing game. 
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int theArithmeticGame(int, int, int);
int timeToScoreConversion(double);
int scoreCalculatorArithmeticGame(double, int); 
int theGuessingGame(int);
int scoreCalculatorGuessingGame(double, int);
int numOfDigits(int);


int main() {
	srand(time(NULL));
	bool continueGame = true;
	int totalScore = 0;

	do {
		int mainMenuOption;

		//Display Menu
		printf("%s", "Please make a selection from the following:\n");
		printf("%s", "1. Play Arithmetic Game.\n");
		printf("%s", "2. Play Guessing Game.\n");
		printf("%s", "3. Print Score.\n");
		printf("%s", "4. Quit.\n");

		scanf("%d", &mainMenuOption);

		system("cls"); //Clear Console 

		switch (mainMenuOption) {
			case 1: {
				int arithmeticGameMenuOption;
				int maxNumber; //Determines range of numbers used from [1,maxNumber]
				int numOfProblems;

				//Display Arithmetic Game Menu
				printf("%s", "Please select an arithmetic game:\n");
				printf("%s", "1. Addition Game\n");
				printf("%s", "2. Multiplication Game\n");
				scanf("%d", &arithmeticGameMenuOption);
				
				printf("%s", "What is the maximum number you would like?\n");
				scanf("%d", &maxNumber);

				printf("%s", "How many problems do you want?\n");
				scanf("%d", &numOfProblems);
					
				system("cls"); //Clear Console 

				//Play Game
				totalScore += theArithmeticGame(maxNumber, numOfProblems, arithmeticGameMenuOption);
				break;
			}
			case 2: {
				int maxNumber; //Random number generated from [1,maxNumber]

				printf("%s", "Enter the maximum number for the game.\n");
				scanf("%d", &maxNumber);

				system("cls"); //Clear Console 

				totalScore += theGuessingGame(maxNumber);
				break;
			}
			case 3: {
				printf("Your score is %d.\n", totalScore);
				break;
			}
			case 4: {
				continueGame = false;
				printf("%s", "Thank you for playing!");
				break;
			}
		}

	} while (continueGame);

}

//AritihmeticGameChosen 1 - Addition Game or 2 - Multiplication Game
int theArithmeticGame(int maxNumber, int numOfProblems, int arithmeticGameChosen) {
	double totalTime = 0;
	//Generate Round Problems 
	for (int currentProblem = 0; currentProblem < numOfProblems; currentProblem++) {
		//Generate Two Numbers [1, maxNumber]
		int numberX = rand() % maxNumber + 1;
		int numberY = rand() % maxNumber + 1;

		int result = arithmeticGameChosen == 1 ? numberX + numberY : numberX * numberY;
		int userAnswer;

		//Display Problem 
		arithmeticGameChosen == 1 ? printf("What is %d + %d?\n", numberX, numberY) : printf("What is %d x %d?\n", numberX, numberY);
		double startTime = time(NULL);
		scanf("%d", &userAnswer);
		double endTime = time(NULL);
		if (userAnswer == result) {
			printf("%s", "Correct Great Job!\n");
			totalTime += endTime - startTime;
		}
		else {
			printf("Sorry, that's incorrect, the answer is %d.\n", result);
			totalTime += (endTime - startTime) + 5; //5 second penalty for incorrect answer
		}
	}

	//Calculate Round Score 
	return scoreCalculatorArithmeticGame(totalTime, numOfProblems);
}


int scoreCalculatorArithmeticGame(double timeTaken, int numOfProblems) {
	double averageTime = timeTaken / numOfProblems;
	int roundScore = timeToScoreConversion(averageTime);

	//Display Game Result 
	printf("You took an average of %.2lf seconds per question.\n", averageTime);
	printf("Your score for the round is %d\n", roundScore);
	
	return roundScore;
}

int theGuessingGame(int maxNumber) {
	int randomNumber = rand() % maxNumber + 1;
	int attemptCounter = 0;

	double startTime = time(NULL);
	while (true) {
		attemptCounter++;
		int userGuess;

		printf("%s", "Enter the guess!\n");
		scanf("%d", &userGuess);

		if (userGuess > randomNumber)
			printf("%s", "Your guess is too high, try again.\n");
		else if (userGuess < randomNumber)
			printf("%s", "Your guess is too low, try again.\n");
		else
			break;
	}
	double endTime = time(NULL);

	system("cls"); //Clear Console 
	printf("Great, you guessed the correct number %d in %d guesses in %.2lf seconds.\n", randomNumber, attemptCounter, endTime - startTime);

	//Calculate Round Score 
	return scoreCalculatorGuessingGame(endTime - startTime, maxNumber);
}

int scoreCalculatorGuessingGame(double timeTaken, int maxNumber) {
	int digits = numOfDigits(maxNumber);
	int roundScore = timeToScoreConversion(timeTaken / (2 * digits));

	printf("Your score for the round is %d.\n", roundScore);

	return roundScore;
}


int numOfDigits(int maxNumber) {
	int digitsCounter = 0;

	while (maxNumber != 0) {
		digitsCounter++;
		maxNumber /= 10;
	}

	return digitsCounter; 
}

int timeToScoreConversion(double gameTime) {
	int score = 0;
	if (gameTime < 1)
		score = 10;
	else if (gameTime >= 1 && gameTime < 2)
		score = 9;
	else if (gameTime >= 2 && gameTime < 3)
		score = 8;
	else if (gameTime >= 3 && gameTime < 4)
		score = 7;
	else if (gameTime >= 4 && gameTime < 5)
		score = 6;
	else if (gameTime >= 5 && gameTime < 6)
		score = 5;
	else if (gameTime >= 6 && gameTime < 7)
		score = 4;
	else if (gameTime >= 7 && gameTime < 8)
		score = 3;
	else if (gameTime >= 8 && gameTime < 9)
		score = 2;
	else if (gameTime >= 9 && gameTime < 10)
		score = 1;
	else
		score = 0;
	
	return score; 
}