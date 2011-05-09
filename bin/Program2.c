#include <stdio.h>
#include <stdlib.h>

union myunion_s
{
    unsigned long int network;
    unsigned char net[4];    
}myunion_t;


union mymask_s
{
    unsigned long int mask;
    unsigned char pos[4];   
}mymask_t;


void optainvalues(long int argc, char *argv[])
{
    myunion_t.network = strtoul(argv[1],NULL,0);
}

void optainmask(long int argc, char *argv[])
{
    mymask_t.mask = 0xFFFFFFFF;   
    unsigned char cidr_mask = atoi(argv[2]);
    if(cidr_mask == 0)
    	mymask_t.mask = 0;
    else
        mymask_t.mask <<= (32-cidr_mask);  
}


void applymask()
{
   myunion_t.network &= mymask_t.mask;
}



int main(int argc, char *argv[])
{
    optainvalues(argc, argv);
    optainmask(argc, argv);	
    applymask();
    printf("The network is: %d.%d.%d.%d, Mask is: %d.%d.%d.%d\n",myunion_t.net[3],myunion_t.net[2],
           myunion_t.net[1],myunion_t.net[0],mymask_t.pos[3],mymask_t.pos[2],mymask_t.pos[1],mymask_t.pos[0]); 
    return 0;
}