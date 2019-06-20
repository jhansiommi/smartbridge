           
 #define  F_CPU 16000000UL          
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define E 5
#define RS 7

void send_a_command(unsigned char command);
int main(void)
{
  DDRC=0XFF;//lcd output
  DDRA=0X00;//input
  DDRD=0XFF;//lcd output
  _delay_ms(50);
  
  ADMUX|=(1<<REFS0)|(1<<REFS1);
  ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
  
  int16_t COUNTA=0;
  char SHOWA[3];

  send_a_command(0X01);
  _delay_ms(50);
  send_a_command(0X38);
  _delay_ms(50);

  send_a_command(0X0E);
  _delay_ms(50);

  ADCSRA|=(1<<ADSC);

  while (1)
  {
    COUNTA=ADC;
    send_a_string("smartbridge");
    send_a_command(0X80+0X40+0);
    send_a_string("Temp(C)=");
    send_a_command(0X80+0X40+8);
    itoa(COUNTA,SHOWA,10);
    send_a_string(SHOWA);
    send_a_string(" ");
    send_a_command(0X80+0);
  }
}
void send_a_command(unsigned char command)
{
  
  PORTC=command;
  PORTD&=~(1<<RS);
  PORTD|=(1<<E);
  _delay_ms(50);
  PORTD&=~(1<<E);
  PORTC=0;
}
void send_a_character(unsigned char character)
{
  PORTC=character;
  PORTD|=(1<<RS);
  PORTD|=(1<<E);
  _delay_ms(50);
  PORTD&=~(1<<E);
  PORTC=0;
}


void send_a_string(char*string_of_characters)
{
  
  while(*string_of_characters>0)
  {
    
    send_a_character(*string_of_characters++);
  }
}
