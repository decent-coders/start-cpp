#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int WIDTH = 20;
const int HEIGHT = 20;
const int SLEEP = 300;

// Direction enum
enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Global variables
vector<pair<int, int>> snake;
int foodX, foodY;
Direction dir = STOP;
bool gameOver = false;

// Function prototypes
void InitializeGame();
void Draw();
void Input();
void Logic();
void GenerateFood();
void DrawGameOver();
void InputGameOver();

int main()
{
    InitializeGame();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(SLEEP);
    }

    DrawGameOver();

    return 0;
}

void InitializeGame()
{
    snake.clear();

    // Start with a longer snake
    int initialLength = 3; // Set the initial length here

    // Create initial snake body segments
    for (int i = 0; i < initialLength; i++)
    {
        snake.push_back({WIDTH / 2 - i, HEIGHT / 2});
    }

    srand(time(0));
    GenerateFood();
    gameOver = false;
    dir = RIGHT; // Set initial direction to right
}

void Draw()
{
    system("cls");

    // Draw top border
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    // Draw game board
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0)
                cout << "#";

            bool isSnakePart = false;
            for (const auto &segment : snake)
            {
                if (segment.first == x && segment.second == y)
                {
                    if (&segment == &snake.front())
                        cout << "O";
                    else
                        cout << "o";
                    isSnakePart = true;
                    break;
                }
            }

            if (!isSnakePart)
            {
                if (x == foodX && y == foodY)
                    cout << "*";
                else
                    cout << " ";
            }

            if (x == WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }

    // Draw bottom border and score
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << snake.size() - 1 << endl;
}

void Input()
{
    if (_kbhit())
    {
        int key = _getch();

        // Handle extended keys (arrow keys)
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 75: // Left arrow
                if (dir != RIGHT)
                    dir = LEFT;
                break;
            case 77: // Right arrow
                if (dir != LEFT)
                    dir = RIGHT;
                break;
            case 72: // Up arrow
                if (dir != DOWN)
                    dir = UP;
                break;
            case 80: // Down arrow
                if (dir != UP)
                    dir = DOWN;
                break;
            }
        }
        // Handle 'x' to exit
        else if (key == 'x' || key == 'X')
        {
            gameOver = true;
        }
    }
}

void Logic()
{
    if (dir == STOP)
        return;

    // Calculate new head position
    int newHeadX = snake.front().first;
    int newHeadY = snake.front().second;

    switch (dir)
    {
    case LEFT:
        newHeadX--;
        break;
    case RIGHT:
        newHeadX++;
        break;
    case UP:
        newHeadY--;
        break;
    case DOWN:
        newHeadY++;
        break;
    }

    // Check wall collision
    if (newHeadX < 0 || newHeadX >= WIDTH || newHeadY < 0 || newHeadY >= HEIGHT)
    {
        gameOver = true;
        return;
    }

    // Check self collision
    for (size_t i = 1; i < snake.size(); i++)
    {
        if (snake[i].first == newHeadX && snake[i].second == newHeadY)
        {
            gameOver = true;
            return;
        }
    }

    // Add new head
    snake.insert(snake.begin(), {newHeadX, newHeadY});

    // Check food collision
    if (newHeadX == foodX && newHeadY == foodY)
    {
        GenerateFood();
    }
    // Remove tail if no food eaten
    else
    {
        snake.pop_back();
    }
}

void GenerateFood()
{
    bool onSnake;
    do
    {
        onSnake = false;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;

        for (const auto &segment : snake)
        {
            if (segment.first == foodX && segment.second == foodY)
            {
                onSnake = true;
                break;
            }
        }
    } while (onSnake);
}

void DrawGameOver()
{
    system("cls");
    cout << "********** GAME OVER **********" << endl;
    cout << "Your score: " << snake.size() - 1 << endl;
    cout << "Press Enter to play again" << endl;
    cout << "Press X to exit" << endl;

    InputGameOver();
}

void InputGameOver()
{
    while (true)
    {
        if (_kbhit())
        {
            int key = _getch();

            if (key == 13)
            { // Enter key
                InitializeGame();
                main(); // Restart the game
            }
            else if (key == 'x' || key == 'X')
            {
                exit(0); // Exit the game
            }
        }
    }
}