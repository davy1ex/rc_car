// rc car v0.1
#include <Servo.h>

// bluetooth vars
char response;

// servo vars
Servo myservo;

// l239d vars
int pin_motor_plus = 5;
int pin_motor_minus = 6;


void setup() {
  // bluetooth setup
  Serial.begin(9600);
//  loggs.begin(9604);

  // servo setup
  myservo.attach(2);
  myservo.write(90); // ровное положение колёс

  // motor pin setup
  pinMode(pin_motor_plus, OUTPUT);
  pinMode(pin_motor_minus, OUTPUT);
}


void loop() {
  if (Serial.available()) { // проверка поданных команд 
    response = Serial.read();
    Serial.print(response);

    // управление передним мостом
    // поворот налево
    if (response == 'R') {
      myservo.write(120);
    }

    // поворот направо
    else if (response == 'L') {
      myservo.write(60);
    }

    else if (response == 'F') {
      digitalWrite(pin_motor_minus, HIGH);
      digitalWrite(pin_motor_plus, LOW);
    }

    else if (response == 'B') {
      digitalWrite(pin_motor_minus, LOW);
      digitalWrite(pin_motor_plus, HIGH);
    }
  }

  else if (response == 'S') {
    myservo.write(90);
    digitalWrite(pin_motor_plus, LOW);
    digitalWrite(pin_motor_minus, LOW);
  }
//  delay(0);
}
