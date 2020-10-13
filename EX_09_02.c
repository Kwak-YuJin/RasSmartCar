#include <stdio.h>
#include <wiringPi.h>

#define LEFT_TRACER_PIN 10 
#define RIGHT_TRACER_PIN 11

#define IN1_PIN 1 
#define IN2_PIN 4
#define IN3_PIN 5
#define IN4_PIN 6

#define INIT_VALUE HIGH, HIGH, HIGH , HIGH, "INIT"
#define GO_VALUE HIGH, LOW, HIGH , LOW, "GO"
#define BACK_VALUE LOW, HIGH, LOW , HIGH, "BACK"
#define LEFT_VALUE LOW, HIGH, HIGH , LOW, "LEFT"
#define RIGHT_VALUE HIGH, LOW, LOW , HIGH, "RIGHT"
#define STOP_VALUE LOW, LOW, LOW , LOW, "STOP"

void controlMotor(int _IN1, int _IN2, int _IN3, int _IN4, char
*msg);
void initSensor();
void checkControl();

int main(void)
{
	if(wiringPiSetup() == -1) return 0; 

	initSensor(); 

	while(1)
	{
		checkControl(); 
	}
	return 0;
}

void initSensor()
{
	pinMode(LEFT_TRACER_PIN, INPUT);
	pinMode(RIGHT_TRACER_PIN, INPUT);
	
	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(IN3_PIN, OUTPUT);
	pinMode(IN4_PIN, OUTPUT);

	controlMotor(INIT_VALUE);
}

void controlMotor(int _IN1, int _IN2, int _IN3, int _IN4, char *msg)
{
	digitalWrite(IN1_PIN, _IN1);
	digitalWrite(IN2_PIN, _IN2);
	digitalWrite(IN3_PIN, _IN3);
	digitalWrite(IN4_PIN, _IN4);
	printf("STATE - %s\n", msg) ;
}

void checkControl()
{
	int nLValue = digitalRead(LEFT_TRACER_PIN);
	int nRValue = digitalRead(RIGHT_TRACER_PIN);

	printf("LTracer - %d, RTracer - %d\n", nLValue, nRValue) ;

	if( (nLValue == HIGH) && (nRValue == HIGH))
	{
		printf(" ALL detect ~!!! MOVE ");
		controlMotor(GO_VALUE);
	}else if( nLValue == HIGH){
		printf(" LEFT detect ~!!! MOVE ");
		controlMotor(LEFT_VALUE);
	}else if(nRValue == HIGH){
		printf(" RIGHT detect ~!!! MOVE ");
		controlMotor(RIGHT_VALUE);
	}else{
		controlMotor(STOP_VALUE);
	}
}
