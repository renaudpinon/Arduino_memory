#include <Arduino.h>

// Prototypes:
void PrintVariable(uint16_t address, int len);

void setup()
{
    // TODO: Program initialization here.
    Serial.begin(9600);
}

void loop()
{
    // TODO: Main program loop.
    long maVar = 32;
    // Obtention de l'adresse avec '&'
    // et de la taille avec sizeof():
    PrintVariable((uint16_t)&maVar, sizeof(maVar));

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

