#include <Arduino.h>

// Prototypes:
void PrintVariable(uint16_t address, int len);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // On crée un buffer:
    uint8_t* buffer = (uint8_t*)malloc(10);
    // On initialise les octets à 0xa0:
    memset(buffer, 0xa0, 10);
    
    // Imaginons maintenant qu'on ne
    // connaisse pas la taille du buffer:
    
    // Adresse du buffer dans le tas:
    uint16_t address = (uint16_t)buffer;
    
    uint8_t* pointer = (uint8_t*)(address - 2); //0x0;
    
    // Taille:
    int len = 0;
    // On copie la valeur à l'adresse -2 dans len:
    memcpy(&len, pointer, sizeof(int));
    
    pointer += 2;
    PrintVariable((uint16_t)pointer, len);
    
    free(buffer);	// On libère !

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

