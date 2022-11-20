/*
 * traffic_light.c
 *
 * Created: 11-10-2021 19:58:18
 * Author : SUMI
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void command(unsigned char cmd){
	PORTA = 0x02;
	PORTB = cmd;
	PORTA = 0x00;
	_delay_ms(15);
}

void lcd_data(unsigned char data){
	PORTA = 0x03;
	PORTB = data;
	PORTA = 0x01;
	_delay_ms(15);
}

void lcd_print(char *p){
	while(*p){
		lcd_data(*p++);
	}
}

int main(void)
{
    DDRD=0XFF;
    DDRC=0XFF;
	DDRA=0XFF;
	DDRB=0XFF;
	command(0X38);
	command(0X0F);
	command(0X01);
    while (1) 
    {
		
		command(0X80);
		lcd_print("STOP");
		//RED LIGHT 9 COUNT DISPLAY
		PORTC=0X01;
		PORTD=0X6F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X7F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X07;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X7D;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X6D;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X66;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X4F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X5B;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X06;
		_delay_ms(8000);
		PORTD=0X00;
		command(0x01);
		
		//YELLOW LIGHT 3 COUNT DISPLAY
		command(0X80);
		lcd_print("WAIT..");
		PORTC=0X02;
		PORTD=0X4F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X5B;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X06;
		_delay_ms(8000);
		PORTD=0X00;
		command(0x01);
			
		//GREEN LIGHT 9 COUNT DISPLAY
		command(0X80);
		lcd_print("GO!");
		_delay_ms(1000);
		PORTC=0X04;
		PORTD=0X6F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X7F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X07;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X7D;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X6D;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X66;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X4F;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X5B;
		_delay_ms(8000);
		PORTD=0X00;
		PORTD=0X06;
		_delay_ms(8000);
		PORTD=0X00;
			command(0x01);
			
			//YELLOW LIGHT 3 COUNT DISPLAY
			command(0X80);
			lcd_print("WAIT..");
			PORTC=0X02;
			PORTD=0X4F;
			_delay_ms(8000);
			PORTD=0X00;
			PORTD=0X5B;
			_delay_ms(8000);
			PORTD=0X00;
			PORTD=0X06;
			_delay_ms(8000);
			PORTD=0X00;
			command(0x01);
    }
}

