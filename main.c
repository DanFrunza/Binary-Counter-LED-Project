#define F_CPU 16000000UL // Definirea frecven?ei procesorului la 16 MHz
#include <avr/io.h>
#include <util/delay.h>

void setup() {
	// Setare pini 3-10 ca ie?iri (porturile PD2-PD7 ?i PB0-BB1 pe majoritatea microcontrollerelor AVR)
	DDRD |= 0b11111100; // Pinii 2-7 (PD2-PD7) ca ie?iri
	DDRB |= 0b00000011; // Pinii 8-9 (PB0-PB1) ca ie?iri
}

void displayNumberOnLEDs(uint8_t number) {
	// Afi??m pe LED-urile conectate la pinii 3-10
	PORTD = (PORTD & 0b00000011) | (number << 2); // Afi??m primele 6 bi?i pe PD2-PD7
	PORTB = (PORTB & 0b11111100) | (number >> 6); // Afi??m bi?ii 6 ?i 7 pe PB0-PB1
}

void loop() {
	uint8_t count = 0; // Variabila pentru num?rare de la 0 la 255

	while (1) {
		displayNumberOnLEDs(count); // Afi??m num?rul curent pe LED-uri
		count++; // Increment?m num?rul
		_delay_ms(500); // Pauz? de 500ms
	}
}

int main(void) {
	setup();
	loop();
	return 0;
}


