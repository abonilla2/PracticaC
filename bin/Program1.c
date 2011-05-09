#include <stdio.h>
#include <stdlib.h>

union myunion_s
{
    unsigned long int network;
    unsigned char net[4];
    
}myunion_t;

void optainvalues(int arg, char *argv[])
{
    myunion_t.network = strtoul(argv[1],NULL,257);
}

int main(int arg, char *argv[])
{
    int i;
    optainvalues(arg, argv);
    printf("%ld\n",myunion_t.network);
    printf("The network is: %d.%d.%d.%d\n",myunion_t.net[3],myunion_t.net[2],myunion_t.net[1],myunion_t.net[0]);
    scanf("%d", &i);
    return 0;
}