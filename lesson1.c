#include<avr/io.h>
int main(void)
{	char temp;
	DDRB = 0xff;
	PORTB = 0b11100110;
	while(1)
	{	PORTB = PORTB <<1;
	}
    while(PORTB&0b10000000)
	{	PORTB = PORTB|0b0000001;
	}
}
