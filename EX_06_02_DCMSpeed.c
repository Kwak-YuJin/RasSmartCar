#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define IN1_PIN 1
#define IN2_PIN 4
#define IN3_PIN 5
#define IN4_PIN 6

#define MAX_SPEED 100
#define MIN_SPEED 0

void initDCMotor();
void go();
void stop();

int gCnt = 3;
int gSpeed = MIN_SPEED;
int nLevel =0;

int main(void)
{
	if(wiringPiSetup() == -1) return 0; 

	initDCMotor(); 
	
	while(gCnt-->=0)
	{
		if(gCnt == 0)
		{
			gSpeed = MIN_SPEED;
			stop();
			delay(1000);
		}else{
			for(nLevel=0; nLevel<=MAX_SPEED; nLevel +=10)
			{
				gSpeed = nLevel;
				go();
				delay(500);
			}
		}
	}
	return 0;
}

void initDCMotor()
{
	pinMode(IN1_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN2_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN3_PIN, SOFT_PWM_OUTPUT);
	pinMode(IN4_PIN, SOFT_PWM_OUTPUT);

	softPwmCreate(IN1_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN2_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN3_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN4_PIN, MIN_SPEED, MAX_SPEED);
}

void go()
{
	softPwmWrite(IN1_PIN, gSpeed);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, gSpeed);
	softPwmWrite(IN4_PIN, MIN_SPEED);
}

void stop()
{
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
}
