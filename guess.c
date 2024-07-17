#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, attempts = 0;
    int score = 0;
    char playAgain;
    srand(time(0)); 
    printf("Welcome to the Number Guessing Game!\n");
    do {
        number = rand() % 100 + 1;
        attempts = 0;
        printf("\nGuess a number between 1 to 100: ");
        do {
            scanf("%d", &guess);
            attempts++;
            if (guess > number) {
                printf("Too high!\n");
                printf("Try again: ");
            } else if (guess < number) {
                printf("Too low!\n");
                printf("Try again: ");
            }
        } while (guess != number);

        printf("\nCongratulations! You guessed the number %d in %d attempts.\n", number, attempts);
        score += 100 - (attempts * 10);
        printf("\nYour current score is: %d\n", score);
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing! Your final score is: %d\n", score);
    return 0;
}
