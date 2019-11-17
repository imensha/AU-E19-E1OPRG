#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define SECOND 1000;

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	for (size_t i = 0; i < 6; i++)
	{
		ledOn(i);
	}

	Wait(5 * SECOND);

	for (size_t i = 0; i < 6; i++)
	{
		ledOff(i);
	}

	return 0;
}