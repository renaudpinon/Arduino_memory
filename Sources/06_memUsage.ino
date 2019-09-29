#include <Arduino.h>

// Variables globales:
uint32_t _lastTime = 0;

// Prototypes:
void PrintMemusage();

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    uint8_t* buff1 = (uint8_t*)malloc(10);
    uint8_t* buff2 = (uint8_t*)malloc(20);
                
    PrintMemusage();
    
    memset(buff1, 0xe4, 10);
    memset(buff2, 0xe4, 20);
        
    free(buff2);	// Libérée !
    free(buff1);  // Délivrée !
        
    delay(10000);
}

// Ecrit les tailles de chaque section:
void PrintMemusage()
{
    extern char* __data_start;
    extern char* __data_end;
    extern char* __bss_start;
    extern char* __bss_end;
    extern char* __heap_start;
    // prochaine allocation du tas disponible:
    extern char* __brkval;
    
    uint16_t memReg = (uint16_t)&__data_start;
    uint16_t memData = (uint16_t)&__data_end - (uint16_t)&__data_start;
    uint16_t memBss = (uint16_t)&__bss_end - (uint16_t)&__bss_start;
    uint16_t memHeapTtl = ((uint16_t)__brkval == 0) ?  0 : (__brkval - __malloc_heap_start);
        
    uint16_t memStack = RAMEND - SP; // SP = pointeur de pile.
    uint16_t freeRam = SP - ((int)&__heap_start + memHeapTtl);
    
    Serial.println("Registres: " + String(memReg) + " octets");
    Serial.println(".Data: " + String(memData) + " octets");
    Serial.println(".Bss: " + String(memBss) + " octets");
    Serial.println("Tas: " + String(memHeapTtl) + " octets");
    Serial.println("Pile: " + String(memStack) + " octets");
    Serial.println("Libre: " + String(freeRam) + " octets");
}

