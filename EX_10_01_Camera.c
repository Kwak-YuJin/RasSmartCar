#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMD "raspistill -w 320 -h 240 -o /home/pi/Pictures/test"
#define idx 0


void takePicture();

int gCnt = 3;

int main(void)
{
	if(wiringPiSetup() == -1) return 0;

	while(gCnt-->0)
	{
		takePicture();
		delay(1000);
	}
}

void takePicture()
{
	char cmd[] = CMD;
	char file[3]= { };

	sprintf(file, "%d", idx++);
	strcat(cmd, file);
	strcat(cmd, ".jpg");
	printf("%s \n", cmd);

	system(cmd); 

	printf("Take a picture \n");
}
