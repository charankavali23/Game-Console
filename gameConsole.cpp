#include <iostream>
#include <conio.h>
#include <time.h>
#include <string.h>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char mark = 'X';

string player1;
string player2;

int p1win = 0;
int p2win = 0;

bool tie;

int position1;
int position2;

void currBoard()
{

    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  "
         << "\n";
    cout << "                                                            ";
    cout << "_____|_____|_____"
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  "
         << "\n";
    cout << "                                                            ";
    cout << "_____|_____|_____"
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  "
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
}

void assignSymbols()
{

    int position;
    int row, column;

    if (mark == 'X')
    {
        cout << player1 << " choose position: ";
        cin >> position;
        cout << "\n\n";
    }
    if (mark == 'O')
    {
        cout << player2 << " choose position: ";
        cin >> position;
        cout << "\n\n";
    }

    switch (position)
    {

    case 1:
        row = 0;
        column = 0;
        break;

    case 2:
        row = 0;
        column = 1;
        break;

    case 3:
        row = 0;
        column = 2;
        break;

    case 4:
        row = 1;
        column = 0;
        break;

    case 5:
        row = 1;
        column = 1;
        break;

    case 6:
        row = 1;
        column = 2;
        break;

    case 7:
        row = 2;
        column = 0;
        break;

    case 8:
        row = 2;
        column = 1;
        break;

    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "\n\nError! Invalid entry."
             << "\n\n\n";
        assignSymbols();
        break;
    }

    if (mark == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        mark = 'O';
    }
    else if (mark == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        mark = 'X';
    }
    else
    {
        cout << "There is no empty space!"
             << "\n";
        assignSymbols();
    }
}

bool checkStatus()
{

    tie = false;

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    tie = true;

    return false;
}

void display()
{

    system("cls");

    cout << "\n\n\n\n\t\t\tWelcome to TIC-TAC-TOE"
         << "\n\n\n\n";

    cout << player1 << " won " << p1win << " and " << player2 << " won " << p2win << "\n\n";

    currBoard();

    cout << player1 << " - [X]  " << player2 << " - [O]  "
         << "\n\n\n";
}

void ticTacToe()
{
    system("cls");

    cout << "\n\n\n\n\t\t\tWELCOME TO TIC-TAC-TOE"
         << "\n\n\n\n";

    cout << "Player 1 will play first with 'X' and Player 2 will play second with 'O'\n\n\n";

    cout << "Enter the name of player 1: ";
    getline(cin >> ws, player1);
    cout << "Enter the name of player 2: ";
    getline(cin >> ws, player2);

    cout << "\n\nChoose positions numbered from 1 to 9 as below and play"
         << "\n\n";

    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << 1 << "  |  " << 2 << "  |  " << 3 << "  "
         << "\n";
    cout << "                                                            ";
    cout << "_____|_____|_____"
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << 4 << "  |  " << 5 << "  |  " << 6 << "  "
         << "\n";
    cout << "                                                            ";
    cout << "_____|_____|_____"
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n";
    cout << "                                                            ";
    cout << "  " << 7 << "  |  " << 8 << "  |  " << 9 << "  "
         << "\n";
    cout << "                                                            ";
    cout << "     |     |     "
         << "\n\n\n";

    cout << player1 << " - [X]  " << player2 << " - [O]  "
         << "\n\n\n";
    cout << "Press any key to start playing ";
    getch();

    while (1)
    {

        for (int i = 1; i <= 9; i++)
        {

            display();
            assignSymbols();

            if (checkStatus())
            {
                break;
            }
        }

        cout << "\n\n                                                              ";
        if (mark == 'X' && tie == false)
        {
            p2win++;
            display();
            cout << player2 << " won!!"
                 << "\n\n\n";
        }
        else if (mark == 'O' && tie == false)
        {
            p1win++;
            display();
            cout << player1 << " won!!"
                 << "\n\n\n";
        }
        else
        {
            display();
            cout << "It's a draw!"
                 << "\n\n\n";
        }

        char playAgain;
        cout << "ENTER 0 TO EXIT TIK TAC TOE\n"
             << "ENTER ANY KEY TO PLAY AGAIN\n\n";
        cout << "Enter your response here --> ";
        cin >> playAgain;

        if (playAgain == '0')
        {
            break;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }
    }
}

void sboard()
{
    cout << "\n\n\t\t\tSNAKE AND LADDER GAME"
         << "\n\n\n";
    cout << "SNAKES AT POSTION"
         << "\n";
    cout << "From 29 to 9\nFrom 38 to 15\nFrom 47 to 5\nFrom 53 to 33\nFrom 62 to 37\nFrom 86 to 54\nFrom 92 to 70\nFrom 97 to 25\n";
    cout << "\n\nLADDER AT POSITION"
         << "\n";
    cout << "From 2 to 23\nFrom 8 to 34\nFrom 20 to 77\nFrom 32 to 68\nFrom 41 to 79\nFrom 74 to 88\nFrom 82 to 100\nFrom 85 to 95\n\n\n";
}

void status()
{
    cout << "\t\t\tGAME STATUS"
         << "\n";
    cout << player1 << " is at position " << position1 << "\n";
    cout << player2 << " is at position " << position2 << "\n\n\n";
}

void throwDice(int &position)
{

    srand(time(0));

    int dice;
    dice = (rand() % 6) + 1;
    cout << "\nYou got " << dice << " moves"
         << "\n";
    position += dice;
    if (position > 100)
    {
        cout << "You can't move"
             << "\n";
        position -= dice;
    }
    cout << "Now you are at position " << position << "\n";

    switch (position)
    {
    case 2:
        position = 23;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 8:
        position = 34;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 20:
        position = 77;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 29:
        position = 9;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 32:
        position = 68;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 38:
        position = 15;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 41:
        position = 79;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 47:
        position = 5;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 53:
        position = 33;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 62:
        position = 37;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 86:
        position = 54;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 92:
        position = 70;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 97:
        position = 25;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 74:
        position = 8;
        cout << "Oops! Snake found ! You are at postion " << position << "\n";
        break;
    case 82:
        position = 100;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;
    case 85:
        position = 95;
        cout << "Great! You got a ladder ! You are at position " << position << "\n";
        break;

    default:
        break;
    }

    cin.get();
}

void snakeAndLadder()
{
    system("cls");
    cout << "\n\n\t\t\tSNAKE AND LADDER GAME"
         << "\n\n\n";
    cout << "Enter the name of player 1: ";
    getline(cin >> ws, player1);
    cout << "Enter the name of player 2: ";
    getline(cin >> ws, player2);
    system("cls");

    while (1)
    {
        sboard();
        status();
        cout << player1 << " Now your Turn --> Press any key to play ";
        getch();
        throwDice(position1);

        if (position1 >= 100)
        {
            system("cls");
            cout << "\n\n\t\t\tSNAKE AND LADDER GAME"
                 << "\n\n\n";
            cout << player1 << " !! You are the winner of the game"
                 << "\n\n";
            cout << player2 << " !! Well played better luck next time"
                 << "\n\n";
            break;
        }
        else
        {
            system("cls");
        }

        sboard();
        status();
        cout << player2 << " Now your Turn --> Press any key to play ";
        getch();
        throwDice(position2);

        if (position2 >= 100)
        {
            system("cls");
            cout << "\n\n\t\t\tSNAKE AND LADDER GAME"
                 << "\n\n\n";
            cout << player2 << " !! You are the winner of the game"
                 << "\n\n";
            cout << player1 << " !! Well played better luck next time"
                 << "\n\n";
            exit(0);
        }
        else
        {
            system("cls");
        }
    }
}

int main()
{
START:
    system("cls");

    printf("\n\n\n\n\t\t\tWELCOME TO CHARAN'S GAME CONSOLE\n\n\n\n");
    printf("Games you can Play: ");
    printf("1:TIK TAC TOE\n\t\t    2:SNAKE AND LADDER\n\n\n");

    printf("Choose the game you want to play\n\n");
    printf("ENTER 1 FOR TIC TAC TOE\n");
    printf("ENTER 2 FOR SNAKE AND LADDER\n");
    printf("ENTER ANY KEY TO EXIT\n\n");

    printf("Enter your response here --> ");
    char gameChoice;
    cin >> gameChoice;

    if (gameChoice == '1')
    {
        ticTacToe();
    }
    else if (gameChoice == '2')
    {
        snakeAndLadder();
    }
    else
    {
        exit(0);
    }

    goto START;

    return 0;
}
