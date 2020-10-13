#include <stdio.h>
#include <wiringPi.h>

#define LEFT_TRA_PIN 10
#define RIGHT_TRA_PIN 11

int main(void)
{
	if(wiringPiSetup() == -1) return 0;

	pinMode(LEFT_TRA_PIN, INPUT);
	pinMode(RIGHT_TRA_PIN, INPUT);

	while(1)
	{
		printf("L=%d, R=%d\n", digitalRead(LEFT_TRA_PIN),
								digitalRead(RIGHT_TRA_PIN));
	}
	return 0;
}
