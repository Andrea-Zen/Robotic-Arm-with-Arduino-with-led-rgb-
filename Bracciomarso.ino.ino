#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the LiquidCrystal object
LiquidCrystal_I2C lcd(0x27, 20, 2); // Specify the I2C address and dimensions

// Declare an array to hold Servo objects
Servo servos[6]; // Array to hold 6 Servo objects

// Insertiamo i pin dei 6 servos
int servoPins[] = {3, 4, 5, 6, 7, 8};

// Initialize the angles for each servo
int angles[6] = {90, 90, 90, 90, 90, 90};

// Joystick pins
int joystickPins[] = {A0, A1, A2, A3};

// Sensitivity threshold for joystick
int joystickThreshold = 10;

// RGB LED pins
int redPin = 9;
int whitePin = 10;
int bluePin = 11;
int greenPin = 8;

// Button pins for controlling LEDs
int redButtonPin = 2;
int whiteButtonPin = 3;
int blueButtonPin = 4;
int greenButtonPin = 5;

// Button pin for changing modes
int modeButtonPin = 6;
bool mode = false; // false: mode one, true: mode two

// State of LEDs
bool redState = false;
bool whiteState = false;
bool blueState = false;
bool greenState = false;

// Function declarations
Servo* getServo(int index);

// Setup function
void setup() {
    // Attach servos to their respective pins
    for (int i = 0; i < 6; i++) {
        servos[i].attach(servoPins[i]);
        servos[i].write(angles[i]); // Move to initial position
    }

    // Set all LED pins as OUTPUT    
    pinMode(redPin, OUTPUT);
    pinMode(whitePin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(modeButtonPin, INPUT_PULLUP); // Use pull-up resistor for button

    // Initialize the LCD
    lcd.begin(20, 2);
}

void loop() {
    // Change mode if button is pressed
    if (digitalRead(modeButtonPin) == LOW) {
        mode = !mode;
        delay(300); // Delay to prevent multiple activations
    }

    // Read joystick values based on the current mode
    if (!mode) {
        for (int i = 0; i < 4; i++) {
            int joystickValue = analogRead(joystickPins[i]);
            int servoIndex = i;

            if (abs(joystickValue - 512) > joystickThreshold) {
                int direction = (joystickValue > 512) ? 1 : -1;
                angles[servoIndex] += direction * map(joystickValue, 0, 1023, -1, 1);
                angles[servoIndex] = constrain(angles[servoIndex], 0, 180);
            }
        }
    } else {
        // Mode 2 control
        for (int i = 0; i < 2; i++) {
            int joystickValue = analogRead(joystickPins[i * 2]);
            int servoIndex = i + 4;

            if (abs(joystickValue - 512) > joystickThreshold) {
                int direction = (joystickValue > 512) ? 1 : -1;
                angles[servoIndex] += direction * map(joystickValue, 0, 1023, -1, 1);
                angles[servoIndex] = constrain(angles[servoIndex], 0, 180);
            }
        }
    }

    // Check button states for LEDs
    if (digitalRead(redButtonPin) == LOW) redState = !redState;
    if (digitalRead(whiteButtonPin) == LOW) whiteState = !whiteState;
    if (digitalRead(blueButtonPin) == LOW) blueState = !blueState;
    if (digitalRead(greenButtonPin) == LOW) greenState = !greenState;

    // Update LED states
    digitalWrite(redPin, redState ? HIGH : LOW);
    digitalWrite(whitePin, whiteState ? HIGH : LOW);
    digitalWrite(bluePin, blueState ? HIGH : LOW);
    digitalWrite(greenPin, greenState ? HIGH : LOW);

    // Display servo angles on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Servo1:");
    lcd.print(angles[0]);
    lcd.setCursor(0, 1);
    lcd.print("Servo2:");
    lcd.print(angles[1]);
    lcd.setCursor(10, 0);
    lcd.print("Servo3:");
    lcd.print(angles[2]);
    lcd.setCursor(10, 1);
    lcd.print("Servo4:");
    lcd.print(angles[3]);
    lcd.setCursor(0, 1);
    lcd.print("Servo5:");
    lcd.print(angles[4]);
    lcd.setCursor(0, 1); 
    lcd.print("Servo6:");
    lcd.print(angles[5]);

    delay(100); // Update delay
}

// Function to get the Servo pointer
Servo* getServo(int index) {
    if (index >= 0 && index < 6) {
        return &servos[index];
    }
    return nullptr; // Return nullptr if index is invalid
}
