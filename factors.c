#include "main.h"
void factors(unsigned long int num)
{
unsigned long int i;
for (i = 2; i < num; ++i)
{
if (num % i == 0)
{
printf("%lu=%lu*%lu\n", num, i, (num / i));
return;
}
}
}



int main(int argc, char *argv[])
{
unsigned long int num, fd, i;
char ch;
char buf[20];
char *buffer;
buffer = buf;
fd = open(argv[1], O_RDONLY);
num = 1;
while(num != 0)
{
ch = 'a';
i = 0;
while(ch != '\n')
{
read(fd, &ch, 1);
buf[i] = ch;
++i;
}
buf[i - 1] = '\0';
num = atoi(buffer);
factors(num);
}
close(fd);
return (0);
}
