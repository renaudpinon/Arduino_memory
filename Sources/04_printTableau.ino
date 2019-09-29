#include <Arduino.h>

// Prototypes:
void PrintVariable(uint16_t address, int len);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    byte tableau[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintVariable((uint16_t)&tableau, sizeof(tableau));

    delay(10000);
}

void PrintVariable(uint16_t address, int len)
{
    // On place un pointeur à l'adresse:
    uint8_t* pointer = (uint8_t*)address; 
    
    Serial.print("Ox");	// On commence l'écriture de la valeur.
    for (int i = 0 ; i < len ; i++)
    {
        uint8_t val = *(pointer+i);	// valeur d'1 octet.
        Serial.print((val < 16 ? "0" : "") + String(val, HEX));
    } 
    Serial.println(""); // CRLF
}

