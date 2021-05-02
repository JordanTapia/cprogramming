#include <stdint.h>
#include <time.h>

/*






*/



int main(){

	/*
	############################# struct example ############################
	*/
	struct WeatherSample {
		float temp;
		uint8_t wind_s;
		uint8_t wind_d;
		uint16_t humidity;
		uint8_t sun;
		// @var time_t \
		the number of seconds since the start of the Unix epoch
		time_t t;			
	};

	struct WeatherSample sample;
	sample.temp = 22.5;
	sample.t = time(NULL);


	/*
	############################# enum example ############################
	*/
	enum month{
		// <enum_name> = <enum_value>
		JANUARY = 1,
		FEBRUARY = 2
	};

	enum month m = JANUARY; 











	return 0;
}





















