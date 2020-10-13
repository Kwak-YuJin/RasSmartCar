#include <stdio.h>
#include <wiringPi.h>

#define LEFT_IR_PIN 27
#define RIGHT_IR_PIN 26

int main(void)
{
	int lValue =0, rValue = 0;
	if(wiringPiSetup() == -1) return 0;

	pinMode(LEFT_IR_PIN, INPUT);
	pinMode(RIGHT_IR_PIN, INPUT);

	while(1)
	{
		lValue = digitalRead(LEFT_IR_PIN);
		rValue = digitalRead(RIGHT_IR_PIN);
		printf("L=%d, R=%d\n", lValue, rValue);
		delay(500);
	}
	return 0;
}
