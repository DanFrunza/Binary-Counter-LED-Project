#define F_CPU 16000000UL // Definirea frecventei procesorului la 16 MHz
#include <avr/io.h>
#include <util/delay.h>

void setup() {
	// Setare pini 3-10 ca iesiri (porturile PD2-PD7 si PB0-BB1 pe majoritatea microcontrollerelor AVR)
	DDRD |= 0b11111100; // Pinii 2-7 (PD2-PD7) ca iesiri
	DDRB |= 0b00000011; // Pinii 8-9 (PB0-PB1) ca iesiri
}

void displayNumberOnLEDs(uint8_t number) {
	// Afi??m pe LED-urile conectate la pinii 3-10
	PORTD = (PORTD & 0b00000011) | (number << 2); // Afisam primii 6 biti pe PD2-PD7
	PORTB = (PORTB & 0b11111100) | (number >> 6); // Afisam bitii 6 si 7 pe PB0-PB1
}

void loop() {
	uint8_t count = 0; // Variabila pentru numarare de la 0 la 255

	while (1) {
		displayNumberOnLEDs(count); // Afisam numarul curent pe LED-uri
		count++; // Incrementam numarul
		_delay_ms(500); // Pauza de 500ms
	}
}

int main(void) {
	setup();
	loop();
	return 0;
}


