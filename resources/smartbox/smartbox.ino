#include <Keypad.h>
#include <Servo.h>
const int GREEN_LED_PIN = 12;
const int RED_LED_PIN = 13;
const int SERVO_PIN = 9;
const int BUZZER_PIN = 11; // Ajout de la broche pour le buzzer

Servo myServo;
int passwordIndex = 0;
// Définir votre mot de passe
char password[5];
char enteredPassword[5];
int etat=0;
int faux=0;

// Définir le clavier (keypad)
const byte ROW_NUM = 4;
const byte COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pin_rows[ROW_NUM] = {8, 7, 6, 5}; // Connectez-les aux rangées respectives sur le clavier (à partir de 8 pour la rangée 1)
byte pin_column[COLUMN_NUM] = {4, 3, 2, 10}; // Connectez-les aux colonnes respectives sur le clavier
Keypad myKeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT); // Configuration de la broche du buzzer
  myServo.attach(SERVO_PIN);
  Serial.begin(9600); 
}

void loop() {
  switch(faux){
    case 0:
    Serial.write("3");
    break;
    case 1:
    Serial.write("2");
    break;
    case 2:
    Serial.write("1");
    break;
    case 3:
    Serial.write("0");
    break;
  }
  char key = myKeypad.getKey();
  if ((key)&&(faux<3)) {
    handleKeyPress(key);
  }
  if (Serial.available() > 0) {
    readPasswordFromSerial();
    myServo.write(150);
    etat=0;
    faux=0;
  }
}

void handleKeyPress(char key) {
  if (key == '#') {
    checkPassword();
  } else {
    enteredPassword[passwordIndex] = key;
    passwordIndex++;
  }
}

void checkPassword() {
  if (strcmp(enteredPassword, password) == 0) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH); // Activer le buzzer une fois
    delay(100); // Laisser le buzzer activé pendant 100 millisecondes
    digitalWrite(BUZZER_PIN, LOW); // Désactiver le buzzer
    myServo.write(90); // Ajustez l'angle si nécessaire
    delay(2000); // Gardez la serrure ouverte pendant 2 secondes (ajustez si nécessaire)
    digitalWrite(GREEN_LED_PIN, LOW);
    etat=1; 
    faux=0;
    clearEnteredPassword();
  } else {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH); // Activer le buzzer deux fois pour un mot de passe incorrect
    delay(100); 
    digitalWrite(BUZZER_PIN, LOW); // Désactiver le buzzer
    delay(100);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    faux++;
    clearEnteredPassword();
  }
}

void clearEnteredPassword() {
  memset(enteredPassword, 0, sizeof(enteredPassword));
  passwordIndex = 0;
}
void readPasswordFromSerial() {
  // Read the password from the serial port
  Serial.readBytesUntil('\n', password, sizeof(password) - 1);
  Serial.flush();  // Clear the serial buffer
}
