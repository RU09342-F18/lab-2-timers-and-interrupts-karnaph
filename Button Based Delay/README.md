# Button Based Delay
This code programs teh board to be able to blink an led at a rate set by how long you press down the button. If the button is pressed for once second, the LED will turn on for 1 second, then turn on for 2 second, and repeat.

This is done using a timer, capture compare registers, global interrupts, an LED and a button. The interrupt is set to detect the falling edge of the button press at the input pin. Then the interrupt detects the rising edge of the button when the button is released. The timer is then reset and set into continuous mode after the first interrupt triggers and counts up to register how long the button is pressed for. This value is then saved to a capture compare register and set as the value the timer now counts up to in continuous mode. The interrupt flag is then also reset. 

