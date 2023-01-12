#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <MMsystem.h>

#define LEN 100

int round = 0;
int repeat = 0;
int cards[52] = { 2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11 };

void swap(int a, int b)
{
	int aux = cards[a];
	cards[a] = cards[b];
	cards[b] = aux;
}

void shuffle()
{
	for (int i = 0; i < 512; i++)
	{
		swap(rand() % 52, rand() % 52);
	}
}

int getCard()
{
	int index = 0;
	int card;

	card = cards[index];
	cards[index] = 0;

	return card;
}

int decision()
{
	int hit = 0;
	int word;
	char response[30];

	printf("\nWhat do you want to do?\n\nHit or Stand\n");
	do
	{
		scanf("%s", response);

		if ((strcmp(response, "hit") == 0) || (strcmp(response, "HIT") == 0) || (strcmp(response, "Hit") == 0))
		{
			hit = 1;
			word = 1;
		}
		else if ((strcmp(response, "Stand") == 0) || (strcmp(response, "stand") == 0) || (strcmp(response, "STAND") == 0))
		{
			word = 2;
			printf("\nYou decided to stand\n");
		}
		else word = 0;
	} while (word == 0);

	//printf("%d", hit);

	return hit;
}

void showDealersCards()
{
    printf("\nDealer's first card : %d\n", cards[2]);
//    if (j==3)
    printf("Dealer's second card : %d\n", cards[3]);
 //   else
  //  {
  //      printf("Dealer's second card : %d\n", cards[3]);
  //      printf("Dealer's second card : %d\n", cards[j]);
 //   }
}

void welcome()
{
    char welcome[30]="Welcome to ";
	for(int q=0 ; q < strlen(welcome) ; q++){
        printf("%c",welcome[q]);
        Sleep(69 + rand() % 69);
	}
	printf("\n");
}

void blackjackCover()
{
    //BlackJack cover
		FILE *fin = fopen("blackjack.txt", "r");
		if (!fin)
		{
			puts("Error");
			exit(-1);
		}

		char string[LEN];

		while (fgets(string, LEN, fin))
		{
			string[strlen(string) - 1] = 0;
			puts(string);
		}

        srand(time(NULL));
}

void music()
{
    // Asking if the player wants to listen to music
        printf("\nDo you wish for listening to relaxing casino music while playing Blackjack?\n");
        char qMusic[5];
        int correctWordqMusic;
        do
		{
			scanf("%s", qMusic);
			if ((strcmp(qMusic, "yes") == 0) || (strcmp(qMusic, "YES") == 0) || (strcmp(qMusic, "Yes") == 0))
            {
                PlaySound(TEXT("LasVegasCasinoMusic.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
				correctWordqMusic = 1;
            }

			else if ((strcmp(qMusic, "no") == 0) || (strcmp(qMusic, "No") == 0) || (strcmp(qMusic, "NO") == 0))
			{
				correctWordqMusic = 1;
			}
			else correctWordqMusic = 0;
		} while (correctWordqMusic == 0);
}

void roundNumber()
{
    printf("-----------------------------------------------\n");
    printf("--------------------Round %d--------------------\n", round);
    printf("-----------------------------------------------\n");
}

void gameOver()
{
    char gameover[5];
    int correctWord;
    do
		{
			scanf("%s", gameover);
			if ((strcmp(gameover, "yes") == 0) || (strcmp(gameover, "YES") == 0) || (strcmp(gameover, "Yes") == 0))
			{
				repeat = 1;
				correctWord = 1;
			}
			else if ((strcmp(gameover, "no") == 0) || (strcmp(gameover, "No") == 0) || (strcmp(gameover, "NO") == 0))
			{
				exit(0);
				correctWord = 1;
			}
			else correctWord = 0;
		} while (correctWord == 0);
}

int main()
{


    welcome();
    blackjackCover();
    music();

	do
	{
	    round++;
		int playerSum = 0;
		int dealerSum = 0;
		int dealersCardsFaceUp = 0;
		int cntFor = 1;
		int dealerIsDone = 0;
		int playerIsDone = 0;
		int dealerNumberOfCards = 2;
		int playerNumberOfCards = 2;
		shuffle();
		roundNumber();
		playerSum = playerSum + cards[0];
		playerSum = playerSum + cards[1];
		dealerSum = dealerSum + cards[2];
		dealerSum = dealerSum + cards[3];
		//for (int i = 0; i < 52; i++)
		//	printf("%d ", cards[i]);
		printf("\n");
		printf("Dealer's first card : %d\n", cards[2]);
		//printf("Dealer's second card : X\n");
		printf("Dealer's second card : %d\n", cards[3]);
		printf("\n");
		printf("Your first card : %d\n", cards[0]);
		printf("Your second card : %d\n", cards[1]);
		printf("\n");
		//printf("playerSum=%d ; dealerSum=%d\n", playerSum, dealerSum);
		int j = 4;
		do {
			int playerHit = 0;
			int hit = decision();
			if (hit == 1)
			{	//you hit
				printf("\nYou decided to hit.\nYour next card is: %d\n", cards[j]);
				playerSum = playerSum + cards[j];
				if (cards[j] == 11 && playerSum > 21)
					playerSum = playerSum - 10;
				j++;
				if (playerSum > 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
                    showDealersCards();
					printf("\nBust!\nYou LOSE!\nGame over!\nDo you want to play again?\n");

					cntFor = 0;
				}
				else if (dealerIsDone == 1 && dealerSum < playerSum && playerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				playerNumberOfCards++;
				playerHit = 1;
			}
			else
			{	//you stand
				playerIsDone = 1;
				if (dealerIsDone == 1 && dealerSum < playerSum && playerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (dealerIsDone == 1 && playerSum < dealerSum && dealerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nDealer WINS!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (dealerIsDone == 1)
					dealersCardsFaceUp = 1;
			}
			if (cntFor == 1 && playerHit == 1 && dealerSum < 17)
			{
			    //dealer hit if you hit
                printf("\nDealer decided to hit.\nDealer's next card is: %d\n", cards[j]);
                dealerSum = dealerSum + cards[j];
                dealerNumberOfCards++;
                printf("\nDealer's number of cards: %d\n", dealerNumberOfCards);
                if (cards[j] == 11 && dealerSum > 21)
                    dealerSum = dealerSum - 10;
                if (dealerSum > 21)
                {
                    printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
                    printf("\nBust!\nYou WIN!\nGame over!\nDo you want to play again?\n");
                    cntFor = 0;
                }
                else if (playerIsDone == 1 && playerSum < dealerSum && dealerSum == 21)
                {
                    printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
                    printf("\nBlackjack!\nDealer WINS!\nGame over!\nDo you want to play again?\n");
                    cntFor = 0;
                }
                j++;
			}
			else if (playerIsDone == 1 && cntFor == 1 && playerHit == 0 && dealerSum < 17)
			{	//dealer hit if u stand
				printf("\nDealer decided to hit.\nDealer's next card is: %d\n", cards[j]);
				dealerSum = dealerSum + cards[j];
				dealerNumberOfCards++;
				printf("\nDealer's number of cards: %d\n", dealerNumberOfCards);
				if (cards[j] == 11 && dealerSum > 21)
					dealerSum = dealerSum - 10;
				while (dealerSum < 17) // dealer hit until he gets above 16
				{
					dealerSum = dealerSum + cards[j + 1];
					if (cards[j+1] == 11 && dealerSum > 21)
						dealerSum = dealerSum - 10;
					printf("\nDealer decided to hit.\nDealer's next card is: %d\n", cards[j + 1]);
					dealerNumberOfCards++;
					printf("\nDealer's number of cards: %d\n", dealerNumberOfCards);
					j++;
				}
				if (dealerSum > 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBust!\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (playerIsDone == 1 && playerSum < dealerSum && dealerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nDealer WINS!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (dealerSum >= 17)
					dealersCardsFaceUp = 1;
			}
			else if (cntFor == 1 && playerHit == 1 && dealerSum >= 17)
			{	//dealer stands if u hit
				printf("\nDealer decided to stand.\n");
				if (playerIsDone == 1 && dealerSum < playerSum && playerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (playerIsDone == 1 && playerSum < dealerSum && dealerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nDealer WINS!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				dealerIsDone = 1;
			}
			else if (playerIsDone == 1 && cntFor == 1 && playerHit == 0 && dealerSum >= 17)
			{	//dealer stands if u stand
				printf("\nDealer decided to stand.\n");
				if (dealerSum < playerSum && playerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (playerSum < dealerSum && dealerSum == 21)
				{
					printf("\nYou have: %d\nDealer has:%d\n", playerSum, dealerSum);
					printf("\nBlackjack!\nDealer WINS!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else dealersCardsFaceUp = 1;
			}
			if (dealersCardsFaceUp == 1)
			{
				printf("\nYou have: %d\nDealer has: %d\n", playerSum, dealerSum);
				if (playerSum > dealerSum)
				{
					printf("\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else if (dealerSum == playerSum)
				{
				    if (playerNumberOfCards == dealerNumberOfCards)
                        printf("\nIt's a tie!\nGame over!\nDo you want to play again?\n");
                    else if (playerNumberOfCards > dealerNumberOfCards)
                        printf("\nDealer WINS!\nGame over!\nDo you want to play again?\n");
                    else if (playerNumberOfCards < dealerNumberOfCards)
                        printf("\nYou WIN!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
				else
				{
					printf("\nDealer WINS!\nGame over!\nDo you want to play again?\n");
					cntFor = 0;
				}
			}
			printf("playerSum=%d ; dealerSum=%d\n", playerSum, dealerSum);
		} while (cntFor != 0);

		gameOver();

	} while (repeat == 1);
	return 0;
}
