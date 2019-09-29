#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    uint8_t* buffer1 = (uint8_t*)malloc(10);
    uint8_t* buffer2 = (uint8_t*)malloc(10); 
    
    Serial.println("Addr1: Ox" + String((uint16_t)buffer1, HEX));
    Serial.println("Addr2: Ox" + String((uint16_t)buffer2, HEX));
    
    free(buffer1);
    free(buffer2);
    
    delay(10000);
}

