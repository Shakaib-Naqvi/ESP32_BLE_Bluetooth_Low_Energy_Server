#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  EEPROM.begin(4096);

  int data_sSize = EEPROM.length();
  for (int i = 0;i < data_sSize; i++){
    int dataa = EEPROM.read(i);
    if(dataa != 0xff){
      // Serial.println("Something else written EEPROM");
          Serial.print(" Data On ");
          Serial.print(i);
          Serial.print(" is: ");
          Serial.println(dataa,HEX);
    }
    // Serial.print(" Data On ");
    // Serial.print(i);
    // Serial.print(" is: ");
    // Serial.println(dataa,HEX);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
