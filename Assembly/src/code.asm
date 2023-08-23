.include "/sdcard/FWC/GATE/Assembly/m328Pdef.inc"
.def result = r16 ; Use register r16 to store the result

.cseg
.org 0x0000 ; Reset vector
    ldi r16, 0b00000000 ; Initialize result to 1

    ldi r17, 0b00000001 ; Load A as 0
    ldi r18, 0b00000000 ; Load B as 0

    eor r16, r17 ; A XOR B

    sbrc r16, 0 ; Test the least significant bit (LSB)
    rjmp led_on ; Jump to led_on if LSB is 1
    rjmp led_off ; Otherwise, jump to led_off

led_on:
    ; Turn on the LED
    sbi PORTB, PORTB0 ; Set PB0 to HIGH
    rjmp end

led_off:
    ; Turn off the LED
    cbi PORTB, PORTB0 ; Clear PB0 to LOW
    rjmp end

end:
    ; End of program


