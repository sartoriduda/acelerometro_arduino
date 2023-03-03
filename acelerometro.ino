#include <Wire.h>

const int MPU = 0x68;

int AcX, AcY, AcZ;
int GcX, GcY, GcZ;

int tmp;

void setup() {
  Serial.begin (9600);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write (0x6B);

  Wire.write (0);
  Wire.endTransmission (true);
}

void loop() {
  Wire.beginTransmission (MPU);
  Wire.write (0x3B);
  Wire.endTransmission (false);

  Wire.requestFrom(MPU, 14, true);

  AcX = Wire.read()<<8|Wire.read();
  AcY = Wire.read()<<8|Wire.read();
  AcZ = Wire.read()<<8|Wire.read();

  tmp = Wire.read()<<8|Wire.read();

  GcX = Wire.read()<<8|Wire.read();
  GcY = Wire.read()<<8|Wire.read();
  GcZ = Wire.read()<<8|Wire.read();

  Serial.print("Acel. X = ");
  Serial.print(AcX);
  Serial.print(" | Y = ");
  Serial.print(AcY);
  Serial.print(" | Z = ");
  Serial.print(AcZ);

  Serial.print(" Gir. X = ");
  Serial.print(GcX);
  Serial.print(" | Y = ");
  Serial.print(GcY);
  Serial.print(" | Z = ");
  Serial.print(GcZ);

  Serial.print(" Temp. = ");
  Serial.println(tmp/340.00 + 36.53);

  delay(300);
}
