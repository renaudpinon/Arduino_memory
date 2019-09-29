#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int x = 0, y = 0, z = 0;
    
    uint16_t varAddress1 = (uint16_t)&x;
    uint16_t varAddress2 = (uint16_t)&y;
    uint16_t varAddress3 = (uint16_t)&z;
    
    Serial.println("Addr1: Ox" + String(varAddress1, HEX));
    Serial.println("Addr2: Ox" + String(varAddress2, HEX));
    Serial.println("Addr3: Ox" + String(varAddress3, HEX));
    
    // Valeur fin de RAM:
    Serial.println("RAMEND: Ox" + String(RAMEND, HEX));
    
    delay(10000);
}

