#include <Servo.h>
Servo ser[5];
void setup() {
  // put your setup code here, to run once:
  ser[0].attach(3);
  ser[1].attach(5);
  ser[2].attach(6);
  ser[3].attach(10);
  ser[4].attach(11);
  Serial.begin(9600);
  ser[0].write(88);
  ser[1].write(143);
  ser[2].write(67);
  ser[3].write(171);
  ser[4].write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 1) {
    char c = Serial.read();
    int val = Serial.parseInt();
    if (c == 'a')ser[0].write(val);
    else if (c == 'b')ser[1].write(val);
    else if (c == 'c')ser[2].write(val);
    else if (c == 'd')ser[3].write(val);
    else if (c == 'e')ser[4].write(val);
  }
}
