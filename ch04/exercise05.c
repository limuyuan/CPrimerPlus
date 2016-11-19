//Programming Exercise 4.8.5
#include <stdio.h>
int main()
{
	float speed, size, time;

	printf("Please enter your download speed(Mb/s):\n");
	scanf("%f", &speed);
	printf("Please enter the size of file(MB):\n");
	scanf("%f", &size);

	time = size * 8 / speed;

	printf("At %.2f megabits per second, a file of %.2f megabytes\n\
downloads in %.2f seconds.\n", speed, size, time);

	return 0;
}
