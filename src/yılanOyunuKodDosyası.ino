#include <LiquidCrystal.h>

// LCD Settings
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7 pins

// Joystick Pins
const int VRX = A0; // X axis
const int VRY = A1; // Y axis
const int SW = 9;   // Joystick button

// Buzzer Pin
const int buzzer = 10; 

// Game Variables
int snakeX[6] = {7}; // Snake X coordinates (maximum size 6)
int snakeY[6] = {0}; // Snake Y coordinates (maximum size 6)
int snakeLength = 1; // Initial snake length
int foodX, foodY;    // Food position
int obstacleX, obstacleY; // Obstacle position
int score = 3;       // Initial score (internal control)
bool gameStarted = false; // Whether the game has started

void setup() {
  // Initialize LCD and Buzzer
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  
  // Set Joystick Pins
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Start Game
  startGame();
}

void loop() {
  if (gameStarted) {
    // Read Joystick Values
    int xValue = analogRead(VRX);
    int yValue = analogRead(VRY);

    // Movement Detection
    int newX = snakeX[0];
    int newY = snakeY[0];

    if (xValue < 400) newX--; // Left
    if (xValue > 600) newX++; // Right
    if (yValue < 400) newY--; // Up
    if (yValue > 600) newY++; // Down

    // Boundary Check
    newX = constrain(newX, 0, 15);
    newY = constrain(newY, 0, 1);

    // Food Eating Check
    if (newX == foodX && newY == foodY) {
      if (snakeLength < 6) { // Maximum length 6
        snakeLength++; // Increase snake length
      }
      spawnFood(); // Create new food
      spawnObstacle(); // Create new obstacle
    }

    // Obstacle Collision Check
    if (newX == obstacleX && newY == obstacleY) {
      score--; // Decrease score (not shown on screen)
      tone(buzzer, 1000, 200); // Play buzzer

      // If score drops below zero, the game ends
      if (score < 0) {
        displayLoseMessage();
        return;
      }
    }

    // Update Snake Position
    for (int i = snakeLength - 1; i > 0; i--) {
      snakeX[i] = snakeX[i - 1];
      snakeY[i] = snakeY[i - 1];
    }
    snakeX[0] = newX;
    snakeY[0] = newY;

    // Win Condition Check
    if (snakeLength == 6) {
      displayWinMessage();
    }

    // Update LCD Screen
    lcd.clear();
    for (int i = 0; i < snakeLength; i++) {
      lcd.setCursor(snakeX[i], snakeY[i]);
      lcd.print("O"); // Draw snake segments
    }
    lcd.setCursor(foodX, foodY);
    lcd.print("*"); // Food
    lcd.setCursor(obstacleX, obstacleY);
    lcd.print("#"); // Obstacle

    delay(300); // Movement speed
  }
}

// Food Generation Function
void spawnFood() {
  bool validPosition = false;
  while (!validPosition) {
    foodX = random(0, 16); // Random X position for food
    foodY = random(0, 2);  // Random Y position for food
    validPosition = true;

    // Check that the food does not overlap with the snake or the obstacle
    for (int i = 0; i < snakeLength; i++) {
      if ((foodX == snakeX[i] && foodY == snakeY[i]) || (foodX == obstacleX && foodY == obstacleY)) {
        validPosition = false;
        break;
      }
    }
  }
}

// Obstacle Generation Function
void spawnObstacle() {
  bool validPosition = false;
  while (!validPosition) {
    obstacleX = random(0, 16); // Random X position for obstacle
    obstacleY = random(0, 2);  // Random Y position for obstacle
    validPosition = true;

    // Obstacle must not overlap with the snake or food
    for (int i = 0; i < snakeLength; i++) {
      if ((obstacleX == snakeX[i] && obstacleY == snakeY[i]) || (obstacleX == foodX && obstacleY == foodY)) {
        validPosition = false;
        break;
      }
    }
  }
}

// Start Game Function
void startGame() {
  // Start Message
  lcd.clear();
  lcd.print("Rules:");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("6 blocks -> Win!");
  delay(2000);
  lcd.clear();
  lcd.print("* -> REWARD!");
  lcd.setCursor(0, 1);
  lcd.print("# -> PENALTY!");
  delay(4000);
  lcd.clear();
  lcd.print("Press button!");

  // Wait for button to start
  while (digitalRead(SW) == HIGH) {
    delay(100);
  }
  
  lcd.clear();
  gameStarted = true;

  // Reset Game Variables
  snakeX[0] = 7;
  snakeY[0] = 0;
  snakeLength = 1;
  score = 3;

  // First Food and Obstacle Positions
  spawnFood();
  spawnObstacle();
}

// Display Losing Message
void displayLoseMessage() {
  gameStarted = false; // Stop game
  lcd.clear();
  lcd.print("You Lost!");
  lcd.setCursor(0, 1);
  lcd.print("Press to retry");

  // Wait for button
  while (digitalRead(SW) == HIGH) {
    delay(100);
  }

  // Restart game
  startGame();
}

// Display Winning Message
void displayWinMessage() {
  gameStarted = false; // Stop game
  lcd.clear();
  lcd.print("You Won!");
  lcd.setCursor(0, 1);
  lcd.print("Press to retry");

  // Wait for button
  while (digitalRead(SW) == HIGH) {
    delay(100);
  }

  // Restart game
  startGame();
}
