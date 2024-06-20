#include <Adafruit_GFX.h>       // Library needed for OLED display
#include <Adafruit_SSD1306.h>   // Library needed for OLED display
#include <Wire.h>               // Library needed for I2C communication

static const unsigned char PROGMEM Universities[] ={   // Bitmap array for displaying the logos of RUG nad UNAM
0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x16, 0x82, 0x50, 0x0f, 0x00, 0x00, 
0x00, 0x00, 0x01, 0xff, 0x40, 0x00, 0x00, 0x00, 0xe0, 0xa9, 0x6f, 0xe3, 0x5f, 0xd2, 0x1c, 0x00, 
0x7c, 0x40, 0x01, 0xff, 0xe0, 0x00, 0x9f, 0x88, 0x2d, 0xf9, 0xef, 0xe7, 0x7f, 0xf2, 0x38, 0xc0, 
0x7b, 0xf0, 0x03, 0xf3, 0xf0, 0x03, 0xf7, 0xa3, 0xef, 0xf8, 0xf6, 0x21, 0x17, 0xf2, 0x7b, 0x98, 
0x01, 0xf8, 0x03, 0xe1, 0xf0, 0x0f, 0xe0, 0x2b, 0xfd, 0xc8, 0x00, 0x00, 0x00, 0x02, 0x7f, 0x64, 
0x01, 0xfc, 0x63, 0xf3, 0xf1, 0x8f, 0xe0, 0x07, 0xd0, 0x78, 0x00, 0x00, 0x00, 0x3c, 0x1f, 0x68, 
0x00, 0xfc, 0xe1, 0xff, 0xe3, 0x8f, 0xc0, 0x16, 0x39, 0x00, 0xd0, 0x00, 0x3e, 0x01, 0x18, 0xe0, 
0x00, 0xf8, 0xf0, 0x7f, 0x83, 0x8f, 0x80, 0x13, 0x80, 0x83, 0x10, 0x00, 0x37, 0x82, 0x00, 0x50, 
0x00, 0x78, 0xf0, 0x7f, 0x03, 0xc7, 0x80, 0x0c, 0xff, 0xdd, 0xc8, 0x01, 0xff, 0xb0, 0xfe, 0x30, 
0x00, 0x38, 0x7c, 0x7f, 0x9f, 0x87, 0x00, 0x0f, 0xf8, 0x53, 0xdc, 0x00, 0xff, 0xfe, 0x7f, 0xf0, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x1e, 0x00, 0x87, 0xfc, 0x01, 0xf3, 0xc2, 0x1e, 0x7c, 
0x00, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x33, 0xff, 0x00, 0x7e, 0x00, 0xfe, 0x00, 0xff, 0xcc, 
0x00, 0x3f, 0xfc, 0x00, 0x0f, 0xfe, 0x00, 0x37, 0xee, 0x00, 0x7e, 0x03, 0xbe, 0x00, 0xcf, 0xf8, 
0x00, 0x18, 0x08, 0x0c, 0x0c, 0x06, 0x00, 0x07, 0xee, 0x00, 0x7e, 0x03, 0xfe, 0x00, 0x6e, 0x70, 
0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x09, 0xef, 0x00, 0xff, 0x01, 0x9f, 0x00, 0xfc, 0xf0, 
0x00, 0x1c, 0x0f, 0xff, 0xfc, 0x0e, 0x00, 0x1c, 0x3f, 0xc3, 0xff, 0x83, 0xff, 0xc1, 0xf7, 0x88, 
0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x07, 0xcf, 0xe1, 0xff, 0x81, 0xb4, 0x83, 0xee, 0xd8, 
0x00, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xfb, 0x30, 0xed, 0xc0, 0x82, 0x0d, 0xb9, 0xd8, 
0x60, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x1f, 0x38, 0x0f, 0x60, 0xff, 0xc1, 0xf2, 0x0e, 0xff, 0xd8, 
0x40, 0x00, 0x00, 0x03, 0x1f, 0xe4, 0x3f, 0x3b, 0xc0, 0xfc, 0xcd, 0xc1, 0x5a, 0x2f, 0xfa, 0x00, 
0x40, 0x00, 0x00, 0x07, 0x3f, 0x8e, 0x7f, 0x3b, 0xfe, 0x8f, 0xf0, 0x1f, 0xff, 0xe3, 0x01, 0x78, 
0x43, 0x38, 0xe6, 0x00, 0x7f, 0x00, 0xff, 0x3f, 0xff, 0xb8, 0xf8, 0x00, 0x01, 0xef, 0xff, 0xf8, 
0x47, 0x9d, 0xde, 0x01, 0xfe, 0x63, 0xfd, 0x3f, 0xff, 0x89, 0x78, 0x00, 0x00, 0x0f, 0xff, 0xf8, 
0x43, 0xcf, 0x9e, 0x03, 0xf8, 0xe7, 0xf1, 0x3e, 0x81, 0xff, 0x3f, 0x38, 0x01, 0x8f, 0x0b, 0xf8, 
0x47, 0xf8, 0xff, 0x07, 0xf0, 0x0f, 0xe1, 0x00, 0x3f, 0xf9, 0x0f, 0x8d, 0x00, 0xef, 0x00, 0x18, 
0x43, 0xf0, 0x7e, 0x07, 0xe6, 0x3f, 0xcd, 0x03, 0xff, 0xcf, 0x00, 0xc0, 0x01, 0x8f, 0xff, 0x48, 
0x47, 0xff, 0xff, 0x07, 0xce, 0x7f, 0x9d, 0x37, 0xef, 0xdf, 0x00, 0x3f, 0x00, 0x07, 0xfd, 0x68, 
0x43, 0xf0, 0xfe, 0x07, 0x00, 0xfe, 0x01, 0x3f, 0xef, 0xfb, 0x00, 0x3f, 0xc1, 0xef, 0xbd, 0xe8, 
0x40, 0x1f, 0xc0, 0x06, 0x61, 0xfc, 0xc3, 0x3f, 0xff, 0x7f, 0x00, 0x3f, 0xe1, 0xed, 0xfd, 0xe8, 
0x40, 0x3f, 0xe0, 0x00, 0xe7, 0xf8, 0xcf, 0x3b, 0xfe, 0x7f, 0x00, 0x7f, 0xf8, 0x2c, 0xdf, 0xe8, 
0x41, 0xb7, 0x6c, 0x00, 0x0f, 0xe0, 0x1f, 0x3b, 0xda, 0x7d, 0x00, 0x7f, 0xff, 0x8c, 0xb7, 0xe8, 
0x40, 0xc7, 0x13, 0x1c, 0x7f, 0xce, 0x3f, 0x3b, 0x59, 0x7f, 0x00, 0x3f, 0xfe, 0xfd, 0x37, 0xf8, 
0x40, 0x37, 0x38, 0x08, 0x0f, 0x80, 0xff, 0x3b, 0x69, 0xff, 0x00, 0x3f, 0xfd, 0x9c, 0x6d, 0xf8, 
0x40, 0x3f, 0xc2, 0xc8, 0x81, 0x21, 0xff, 0x3b, 0x61, 0xff, 0x00, 0x1f, 0xfc, 0x1e, 0x4d, 0xb8, 
0x40, 0x07, 0x52, 0x48, 0x91, 0xe3, 0xf9, 0x3b, 0x20, 0xcd, 0x00, 0x0f, 0xfc, 0x0e, 0x09, 0xb0, 
0x40, 0x00, 0x48, 0x08, 0x01, 0x07, 0xf1, 0x1b, 0x01, 0xc0, 0x00, 0x1f, 0xf1, 0xe8, 0x09, 0xb0, 
0x40, 0x00, 0x40, 0xea, 0x41, 0x1f, 0xe9, 0x19, 0x3f, 0xbf, 0x80, 0x1f, 0xe3, 0xef, 0x01, 0xf0, 
0x40, 0x00, 0x42, 0x6a, 0x41, 0x3f, 0x9d, 0x19, 0xbf, 0x1f, 0x80, 0x1f, 0x83, 0xfb, 0xf9, 0x70, 
0x40, 0x00, 0x5a, 0x08, 0x4d, 0x7f, 0x01, 0x18, 0x3e, 0x44, 0x40, 0x3f, 0x06, 0x51, 0xf8, 0x60, 
0x4c, 0x7f, 0xd8, 0x08, 0x05, 0x00, 0x01, 0x0c, 0x06, 0x3c, 0x00, 0x3c, 0x0f, 0xf8, 0xc8, 0x60, 
0x5c, 0xff, 0x42, 0x48, 0x81, 0x00, 0x01, 0x0c, 0x06, 0x7a, 0x60, 0x3c, 0x19, 0x78, 0xc0, 0x40, 
0x41, 0xfc, 0xd5, 0x48, 0x51, 0x00, 0x01, 0x0c, 0x04, 0x01, 0xf0, 0x38, 0x3e, 0xfc, 0xc0, 0xc0, 
0x47, 0xf9, 0xd0, 0x08, 0x09, 0x00, 0x01, 0x04, 0x00, 0x01, 0x98, 0x38, 0x5e, 0x20, 0x00, 0x80, 
0x4f, 0xf4, 0x41, 0xff, 0xc1, 0x3d, 0xc1, 0x06, 0x01, 0xfe, 0xf0, 0x30, 0xed, 0x04, 0x00, 0x04, 
0x7f, 0xce, 0x4f, 0xf7, 0xf1, 0xf3, 0xc1, 0x6f, 0xb9, 0xff, 0xe3, 0x03, 0x1f, 0x7e, 0x00, 0x1c, 
0x7f, 0x80, 0x7f, 0x1e, 0xff, 0xe3, 0xc1, 0x77, 0xf0, 0x19, 0x82, 0xcd, 0x2f, 0x6e, 0x03, 0x3c, 
0x3f, 0x21, 0xfe, 0x48, 0xfe, 0x1f, 0xc3, 0x7f, 0xf0, 0x40, 0x0f, 0x77, 0x40, 0x00, 0x03, 0xc8, 
0x3c, 0x73, 0xf8, 0xc0, 0x7e, 0x1f, 0x82, 0x22, 0x79, 0xa0, 0x04, 0x71, 0x00, 0x00, 0x01, 0x84, 
0x38, 0x07, 0xf0, 0x01, 0xff, 0xff, 0xe2, 0x21, 0xee, 0x01, 0xf1, 0xf4, 0x00, 0x71, 0xde, 0x08, 
0x13, 0x1f, 0xe4, 0x30, 0xfe, 0x1e, 0xc6, 0x21, 0x8e, 0x06, 0x08, 0x30, 0x03, 0xb2, 0x0d, 0xe0, 
0x13, 0x3f, 0xce, 0x70, 0x03, 0xf0, 0x04, 0x30, 0x99, 0xbb, 0xc4, 0x00, 0x0c, 0x64, 0x0c, 0x00, 
0x08, 0x7f, 0x00, 0xf0, 0x4f, 0xfd, 0x08, 0x18, 0xe0, 0x00, 0x41, 0x80, 0x08, 0xc8, 0x08, 0x00, 
0x0c, 0xfe, 0x61, 0xf0, 0x7a, 0xd7, 0x88, 0x06, 0x50, 0x46, 0x90, 0xfc, 0x90, 0x48, 0x70, 0x00, 
0x07, 0xfc, 0xe7, 0xf0, 0x10, 0xc2, 0x10, 0x03, 0x7c, 0x00, 0x1e, 0x04, 0x70, 0xc9, 0x80, 0x00, 
0x03, 0xf0, 0x0f, 0xe0, 0x05, 0xec, 0x20, 0x06, 0x06, 0x2f, 0xff, 0x00, 0x21, 0x9e, 0x1f, 0x00, 
0x01, 0xe6, 0x1f, 0xc0, 0x05, 0xe8, 0xc0, 0x05, 0x01, 0x3f, 0xfc, 0xc0, 0x26, 0xf7, 0xc0, 0xc0, 
0x00, 0xce, 0x7f, 0x80, 0x00, 0xc1, 0x80, 0x04, 0x20, 0xd0, 0x7f, 0xe7, 0xdf, 0x00, 0x02, 0x60, 
0x00, 0x30, 0xfe, 0x00, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x44, 0xbf, 0x78, 0x3c, 0x03, 0xc0, 0x40, 
0x00, 0x0d, 0xfc, 0x60, 0x00, 0x18, 0x00, 0x0f, 0xff, 0xc0, 0x36, 0xb0, 0x20, 0x03, 0x38, 0xc0, 
0x00, 0x03, 0xf8, 0xe0, 0x00, 0x60, 0x00, 0x18, 0x00, 0x62, 0x7b, 0xfc, 0x3e, 0x06, 0x07, 0x00, 
0x00, 0x00, 0x70, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x97, 0xf3, 0xc1, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x0f, 0xe3, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x2f, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xc0, 0x00, 0x00, 0x00
};

static const unsigned char PROGMEM heart[] ={  // Bitmap array for displaying a heart 
0x10, 0x10, 0x38, 0x38, 0x7c, 0x7c, 0xfe, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xee, 0xee, 0xd5, 0x56, 
0x3b, 0xb8, 0x3f, 0xf8, 0x1f, 0xf0, 0x0f, 0xe0, 0x07, 0xc0, 0x03, 0x80, 0x01, 0x00
};

static const unsigned char PROGMEM beat[] ={  // Bitmap array for displaying a heart of minor size to simulate an animation of a heart beat
  0x10, 0x04, 0x00, 0x38, 0x0e, 0x00, 0x7c, 0x1f, 0x00, 0xfe, 0x3f, 0x80, 0xff, 0x7f, 0x80, 0xff, 
0xff, 0x80, 0xff, 0xff, 0x80, 0xdf, 0x7d, 0x80, 0xae, 0xba, 0x80, 0x75, 0xd7, 0x00, 0x3b, 0xee, 
0x00, 0x1f, 0xfc, 0x00, 0x0f, 0xf8, 0x00, 0x07, 0xf0, 0x00, 0x03, 0xe0, 0x00, 0x01, 0xc0, 0x00, 
0x00, 0x80, 0x00
};

const int sensorPin = A0;             // Sensor pin for analog input
const int threshold = 300;            // Threshold value for peak detection
const int t_entre_picos = 200;        // Minimum time between peaks (in milliseconds)
const int OLED_RESET = LED_BUILTIN;   // Reset pin for the OLED display


int sensorValue;                      // Variable to store the sensor value
unsigned long previousMillis = 0;     // Variable to store the previous millisecond count
const long interval = 15000;          // Interval for the BPM calculation (in milliseconds)
unsigned long startTime;              // Variable to store the start time
int peakCount = 0;                    // Counter for the number of peaks detected

#define SCREEN_WIDTH 128   // OLED display dimensions
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Create an instance of the SSD1306 display

void read_temp() {    // Function to read the sensor value and update the display
    unsigned long currentMillis = millis();   // Get the current millisecond count
    sensorValue = analogRead(sensorPin);      // Read the sensor value from the analog pin

    int yPos = map(sensorValue, 0, 1023, SCREEN_HEIGHT / 2, 0);               // Map the sensor value to the y-position on the display
    int xPos = map(currentMillis - startTime, 0, interval, 0, SCREEN_WIDTH);  // Calculate the x-position based on the elapsed time

    static int lastYPos = yPos;     // Static variables to store the last positions and state
    static int lastXPos = xPos;
    static int lastPeakCount = 0;
    static bool heartState = true;

    display.drawLine(lastXPos, lastYPos, xPos, yPos, SSD1306_WHITE); // Draw a line from the last position to the current position that would be making the visualization inreal time

    lastYPos = yPos;   // Update the last positions
    lastXPos = xPos;

    // Function for Peak detection
    if (sensorValue > threshold && currentMillis - previousMillis > t_entre_picos) {
        peakCount++;  // Increment the peak count
        previousMillis = currentMillis;  // Update the previous millisecond count

        // Clear the rectangle where the heart/beat icon will be drawn
        display.fillRect(57, 48, 18, 18, SSD1306_BLACK);

        // Toggle the heart state if the peak count has changed
        if (peakCount != lastPeakCount) {
            heartState = !heartState; 
            lastPeakCount = peakCount;
        }

        // Draw the heart or beat icon based on the heart state for simulating of a heart beat
        if (heartState) {
            display.drawBitmap(57, 48, beat, 17, 17, 1);
        } else {
            display.drawBitmap(57, 48, heart, 15, 15, 1);
        }
    }

    if (currentMillis - startTime >= interval) {  // If the interval has passed, calculate and display the BPM
        int bpm = int(peakCount * 2);

        lastXPos = xPos = 0;   // Reset the x-position and clear the display
        display.clearDisplay();
        
        // Display BPM or "Measuring" text based on the BPM range
        if (bpm < 40 || bpm > 120) {
            display.setTextSize(1);
            display.setCursor(0, 52);
            display.println("Measuring");
            display.drawBitmap(57, 48, heart, 16, 16, 1); 
            display.setTextSize(2);
            display.setCursor(76, 50);
            display.print("BPM");
        } else {
            display.setTextSize(2);
            display.setCursor(16, 50);
            display.print(bpm);
            display.drawBitmap(56, 48, heart, 16, 16, 1); 
            display.setTextSize(2);
            display.setCursor(76, 50);
            display.print("BPM");
        }
        
        display.display();  
        
        peakCount = 0;  // Reset the peak count
        startTime = currentMillis;  // Reset the start time
        delay(100); 
    } else {
        display.display();  
    }
}

// Setup function to initialize the display and sensor
void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize the display with I2C address
    display.clearDisplay();  // Clear the display
    display.drawBitmap(0, 0, Universities, 128, 64, 1);  // Show "Universities" image
    display.display();  // Update the display
    delay(3000);  // Wait for 3 seconds
    display.clearDisplay();  // Clear the display
    Serial.println("Starting...");

    display.clearDisplay();   // Display text
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 52);
    display.println("Measuring");
    display.setTextSize(2);
    display.setCursor(76, 50);
    display.print("BPM");
    display.display();
    delay(100); 

    pinMode(sensorPin, INPUT);  // Set the sensor pin as input
    startTime = millis();
    Serial.println("Setup complete");
}

// Main loop function to continuously read sensor data and update the display
void loop() {
    read_temp();  // Call the read_temp function
}