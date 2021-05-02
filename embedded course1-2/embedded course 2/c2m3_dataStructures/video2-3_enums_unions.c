#include <stdint.h>
#include <time.h>
#include <stdio.h>
/*

	Pre proc directives and consts eliminate buncha random constants all across code.
		Bug prone, no type-checking
		Consts allocate memory that has high latency in the code region
	Enums are alternate!
		doesn't need mem
		type int




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
	
	Enum best practices:

		typedef enum
		enum constants in all caps
		each new enum has same base name

	*/
	enum month{
		// <enum_name> = <enum_value>
		JANUARY = 1,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};

	enum month m = JANUARY; 



	/*
	############################# union example ############################
	
	Union:
		Derived data type ocntaining multiple data members that occupy the 
		same address.
		Unlike a struct, wher eeach data comes one after the other in memory, each
		member of union has some overlap with other members defined in the same type. 

	Usage:
		Interpret data type diff per function. Apparently assign x = whatever, and y,z = whatever too.
		So yeah!

		Used in CMSIS, Core uController Std IF SW to provde core CPU reg struct defs
		core_cm4.h
		Two unions used by CMSIS:
			CONTROL_Type
				31:3	reserved
				2		FPCA
				1		SPSEL
				0		nPRIV
			IPSR_Type

		Allows for efficient memory usage, e.g. reused between 2 diff functions


	*/

	typedef union {
		uint8_t x;
		uint8_t y;
		uint8_t z;
	} ex1;

	ex1 point;
	point.x = 0x15;


	printf("size of union ex1: %lu byte\n",sizeof(ex1));




/*
	############################# abstract data structs ############################

	ADS's need to:
		add new data
		remove data
		init a struct
		clear a struct
*/



/*
	############################# bit fields ############################




*/
	return 0;
}





















