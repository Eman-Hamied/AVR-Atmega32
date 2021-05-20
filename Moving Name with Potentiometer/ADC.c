#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "ADC.h"

void ADC_vidInit(void) {

	ADMUX = 0b01000000; //Or set_bit(ADMUX,6);
	ADCSRA = 0b10000110; //Or set_bit(ADMUX,1); set_bit(ADMUX,2);
}

u16 ADC_u16ReadDigital(void){
	//start conversion
	set_bit(ADCSRA,6);

	while(get_bit(ADCSRA,4)==0); //Polling
	set_bit(ADCSRA,4);

	return ADC;
}

