#include<stdio.h>
#include<cs50.h>
#include<string.h>

//  implement a program in C that determines the winner of a short Scrabble-like game.
//  Your program should prompt for input twice:
//  once for “Player 1” to input their word and
//  once for “Player 2” to input their word.
//  Then, depending on which player scores the most points,
//  your program should either print “Player 1 wins!”,
//  “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).

// ONE POINT: A, E, I, L, N, O, R, S, T, U
// TWO POINT: D, G
// THREE POINT: B, C, M, P
// FOUR POINT: F, H, V, W, Y
// FIVE POINT: K
// EIGHT POINT: J, X
// TEN POINT: Q, Z


int main()
{
    int N = 50; // set value for index
    string player1 = get_string("Player 1: "); // Gather input for Player 1
    string player2 = get_string("Player 2: "); // Gather input for Player 2
    int score1 = 0;
    int score2 = 0;
    int letter_scores[] =
    {
        1, // a
        3, // b
        3, // c
        2, // d
        1, // e
        4, // f
        2, // g
        4, // h
        1, // i
        8, // j
        5, // k
        1, // l
        3, // m
        1, // n
        1, // o
        3, // p
        10, // q
        1, // r
        1, // s
        1, // t
        1, // u
        4, // v
        4, // w
        8, // x
        4, // y
        10, // z

    };

    // loop for player 1
    for(int i = 0; i < strlen(player1); i++)
    {
        char letter = player1[i];
        if (letter >= 'A' && letter <= 'Z')
        {
            score1 += letter_scores[letter - 'A']; // here the subtraction of 'a' results in what letter we are actually at
        }
        else if(letter >= 'a' && letter <= 'z')
        {
            score1 += letter_scores[letter - 'a']; // here the subtraction of 'a' results in what letter we are actually at
        }
    }

    // loop for player 2
    for(int i = 0; i < strlen(player2); i++)
    {
        char letter = player2[i];
        if (letter >= 'A' && letter <= 'Z')
        {
            score2 += letter_scores[letter - 'A']; // here the subtraction of 'a' results in what letter we are actually at
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            score2 += letter_scores[letter - 'a']; // here the subtraction of 'a' results in what letter we are actually at
        }
    }
    if(score1 < score2)
    {
        printf("Player 2 Wins! Score:%i\n", score2);
    }
    else if(score1 > score2)
    {
        printf("Player 1 Wins! Score:%i\n", score1);
    }
    else
    {
        printf("We have have Tie!\n");
    }
    return 0; // program success
}
