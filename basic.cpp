#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include for std::find

using namespace std;

// Constants
const int WIDTH = 20;
const int HEIGHT = 20;
const int INITIAL_SLEEP = 300;  // Initial speed value
const int INITIAL_SEGMENTS = 5; // Initial snake length

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
string foodColor; // Store current food color
Direction dir = STOP;
bool gameOver = false;
bool isPaused = false;
double sleepTime = INITIAL_SLEEP; // Sleep time will be modified dynamically

// Add these color codes
const vector<string> rainbowColors = {
    "\033[31m", // Red
    "\033[33m", // Yellow
    "\033[32m", // Green
    "\033[36m", // Cyan
    "\033[34m", // Blue
    "\033[35m"  // Magenta
};

// Function prototypes
void InitializeGame();
void Draw();
void Input();
void Logic();
void GenerateFood(string color = "");
void DrawGameOver();
void InputGameOver();

int main()
{
    InitializeGame();

    while (!gameOver)
    {
        Draw();
        Input();
        if (!isPaused)
        {
            Logic();
            Sleep(static_cast<int>(sleepTime));
        }
    }

    DrawGameOver();

    return 0;
}

void InitializeGame()
{
    snake.clear();

    // Create initial snake body segments
    for (int i = 0; i < INITIAL_SEGMENTS; i++)
    {
        snake.push_back({WIDTH / 2 - i, HEIGHT / 2});
    }

    srand(time(0));
    GenerateFood();
    gameOver = false;
    dir = RIGHT;               // Set initial direction to right
    sleepTime = INITIAL_SLEEP; // Reset speed for new game
    isPaused = false;
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
                    // Find the iterator to the segment
                    auto it = find(snake.begin(), snake.end(), segment);
                    if (it != snake.end())
                    {
                        // Calculate color index based on position in snake
                        int colorIndex = (snake.size() - distance(snake.begin(), it)) % rainbowColors.size();

                        if (&segment == &snake.front())
                        {
                            cout << rainbowColors[colorIndex] << "O" << "\033[0m";
                            foodColor = rainbowColors[colorIndex]; // Update food color to match head
                        }
                        else
                        {
                            cout << rainbowColors[colorIndex] << "o" << "\033[0m";
                        }
                    }
                    else
                    {
                        cout << "O"; // Fallback if not found
                    }
                    isSnakePart = true;
                    break;
                }
            }

            if (!isSnakePart)
            {
                if (x == foodX && y == foodY)
                    cout << foodColor << "*" << "\033[0m"; // Use stored food color
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
    cout << "Score: " << snake.size() - INITIAL_SEGMENTS << endl;
    cout << "Current speed: " << (100 + ((INITIAL_SLEEP - sleepTime) * 100.0 / INITIAL_SLEEP)) << "%%" << endl;

    // Display pause message
    if (isPaused)
    {
        cout << "********** GAME PAUSED **********" << endl;
        cout << "Press Enter to resume" << endl;
    }
}

void Input()
{
    if (_kbhit())
    {
        int key = _getch();

        // Handle pause/resume with Enter key
        if (key == 13)
        { // Enter key
            isPaused = !isPaused;
            return;
        }

        // Only process other inputs when not paused
        if (isPaused)
            return;

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
        // Generate new food with the current head color
        GenerateFood(foodColor);
        // Increase speed by 1.4%
        sleepTime = sleepTime * 0.986;
    }
    // Remove tail if no food eaten
    else
    {
        snake.pop_back();
    }
}

void GenerateFood(string color)
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

    // Set food color to the specified color or use the current head color
    if (color.empty())
    {
        // Calculate new food color based on current head color
        auto headColorIndex = (snake.size() - 1) % rainbowColors.size();
        foodColor = rainbowColors[headColorIndex];
    }
    else
    {
        foodColor = color;
    }
}

void DrawGameOver()
{
    system("cls");
    cout << "********** GAME OVER **********" << endl;
    cout << "Your score: " << snake.size() - INITIAL_SEGMENTS << endl;
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