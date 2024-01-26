#include <iostream>

using namespace std;

const int rows = 10;
const int cols = 20;

const char WALL = '#';
const char SPACE = ' ';
const char START = '$';
const char DESTINATION = '@';
const char PLAYER = '*';

char maze[rows][cols] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#',' ', '#', '#', '#', '#', '#', '#', ' ',  '#', '@', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

int playerRow, playerCol;

void printMaze() {
    system("cls");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

void movePlayer(char direction) {
    switch (direction) {
    case 'g':
        if (playerRow - 1 >= 0 && maze[playerRow - 1][playerCol] != WALL) {
            maze[playerRow][playerCol] = SPACE;
            playerRow--;
        }
        break;
    case 'd':
        if (playerRow + 1 < rows && maze[playerRow + 1][playerCol] != WALL) {
            maze[playerRow][playerCol] = SPACE;
            playerRow++;
        }
        break;
    case 'p':
        if (playerCol + 1 < cols && maze[playerRow][playerCol + 1] != WALL) {
            maze[playerRow][playerCol] = SPACE;
            playerCol++;
        }
        break;
    case 'l':
        if (playerCol - 1 >= 0 && maze[playerRow][playerCol - 1] != WALL) {
            maze[playerRow][playerCol] = SPACE;
            playerCol--;
        }
        break;
    default:
        cout << "Wprowadzona wartosc jest nieprawidlowa!" << endl;
        break;
    }

    if (maze[playerRow][playerCol] == DESTINATION) {
        cout << "Hurra! Udalo ci sie ukonczyc labirynt!" << endl;
        exit(0);
    }

    maze[playerRow][playerCol] = PLAYER;
}

int main() {
    int option;

    cout << "Witaj w grze Labirynt!\n"
        << "1. Start\n"
        << "2. Exit\n"
        << "Wybierz jedna z opcji: ";

    cin >> option;

    if (option == 2) {
        cout << "Bye, bye!" << endl;
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == START) {
                playerRow = i;
                playerCol = j;
                break;
            }
        }
    }

    char move;
    printMaze();

    do {
        cout << "Wykonaj ruch (p: right, l: left, g: up, d: down, q: quit): ";
        cin >> move;

        if (move == 'q' || move == 'Q') {
            cout << "Bye, bye!" << endl;
            break;
        }

        movePlayer(move);
        printMaze();

    } while (true);

    return 0;
}