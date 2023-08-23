#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set up your input pins for A, B, and C
    // Set up your output pins for LEDs
    DDRC &= ~(1 << PC2); // Set PC2 as input (A)
    DDRC &= ~(1 << PC3); // Set PC3 as input (B)
    DDRC &= ~(1 << PC4); // Set PC4 as input (C)
    DDRC |= (1 << PB2);  // Set PC5 as output for LED (output of the boolean function)

    while (1) {
        // Set the values of A, B, and C to 0, 1, 0
        uint8_t A = 0;
        uint8_t B = 1;
        uint8_t C = 0;

        // Evaluate the boolean expression: (!A && B)  (A && !B) && !C
        uint8_t result = ((!A && B) || (A && !B)) && !C;

        // Control the LED accordingly
        if (result) {
            PORTC |= (1 << PB2); // Turn on the LED
        } else {
            PORTC &= ~(1 << PB2); // Turn off the LED
        }

        _delay_ms(100); // Delay for a short period
    }

    return 0;
}