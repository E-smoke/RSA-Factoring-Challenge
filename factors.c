#include "main.h"
void factors(unsigned long int num)
{
unsigned long int i;
for (i = 2; i < num; ++i)
{
if (num % i == 0)
{
printf("%lu=%lu*%lu\n", num, (num / i), i);
return;
}
}
}



int main(int argc, char *argv[])
{
	FILE *fptr;
	unsigned long int count;
	unsigned long int line;
	unsigned long int num;
	char *buffer = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while((line = getline(&buffer, &count, fptr)) != -1)
	{
		num = atoi(buffer);
		factors(num);
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
return (0);
}
