#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <IRremote.h>

// --- Pin Configuration ---
#define SOIL_PIN A0       // Soil moisture sensor
#define PUMP_PIN 8        // Relay for water pump
#define SERVO_PIN 9       // Servo for shade
#define IR_PIN 2          // IR receiver

// --- Objects ---
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address may vary
Servo shadeServo;
IRrecv irrecv(IR_PIN);
decode_results results;

// --- Variables ---
int soilMoisture = 0;
int moisturePercent = 0;
int dryThreshold = 40; // below 40% means dry soil
int shadePosition = 0; // 0 = closed, 90 = open

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize pins
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);

  // Initialize servo
  shadeServo.attach(SERVO_PIN);
  shadeServo.write(0); // Start with shade closed

  // Initialize IR receiver
  irrecv.enableIRIn();

  // Welcome message
  lcd.setCursor(0,0);
  lcd.print("Auto Irrigation");
  lcd.setCursor(0,1);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read soil moisture
  soilMoisture = analogRead(SOIL_PIN);
  moisturePercent = map(soilMoisture, 1023, 0, 0, 100); // Adjust mapping if reversed

  // Display moisture on LCD
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.print(moisturePercent);
  lcd.print("%   ");

  // Pump control logic
  if (moisturePercent < dryThreshold) {
    digitalWrite(PUMP_PIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Pump: ON       ");
  } else {
    digitalWrite(PUMP_PIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF      ");
  }

  // Shade control via IR
  if (irrecv.decode(&results)) {
    unsigned long value = results.value;

    // Replace these with your IR remote button codes
    if (value == 0xFF629D) {        // Example: "Up" button opens shade
      shadeServo.write(90);
      lcd.setCursor(0, 1);
      lcd.print("Shade: Open    ");
    } else if (value == 0xFFA857) { // Example: "Down" button closes shade
      shadeServo.write(0);
      lcd.setCursor(0, 1);
      lcd.print("Shade: Closed  ");
    }

    irrecv.resume(); // Receive next value
  }

  delay(500); // Small delay for stability
}
