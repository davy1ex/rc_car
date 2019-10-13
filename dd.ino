// rc car v0.1
#include <Servo.h>

// bluetooth vars
char response;

//
Servo myservo;

void setup() {
  // bluetooth setup
  Serial.begin(9600);
//  loggs.begin(9604);

  // servo setup
  myservo.attach(2);
  myservo.write(90); // ровное положение колёс

  // motor pin setup
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
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
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
    }

    else if (response == 'B') {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
    }
  }

  else if (response == 'S') {
    myservo.write(90);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
//  delay(0);
}
