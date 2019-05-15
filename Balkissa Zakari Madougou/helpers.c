//Balkissa Zakari Madougou
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

int duration(string fraction)
{
    int kiss=atoi(&fraction[0]);
    int madougou=atoi(&fraction[3]);
    if(kiss>0&&madougou>0&&(madougou%2==0))
    {
        return (float) (kiss/madougou);
    }
    else
    {
        return 1;
    }
}
int frequency(string note)
{
    int cs50;
    char NOTES=note[0];
    int orange=note[strlen(note)- 1]- 48;
    if(NOTES=='C')
    {
        cs50=1;
    }
    if(NOTES=='D')
    {
        cs50=3;
    }
    if(NOTES=='E')
    {
        cs50=5;
    }
    if(NOTES=='F')
    {
        cs50=7;
    }
    if(NOTES=='G')
    {
        cs50=9;
    }
    if(NOTES=='A')
    {
        cs50=11;
    }
    if(NOTES=='B')
    {
        cs50=13;
    }
    if(note[1]=='#')
    {
        cs50++;
    }
    if(note[1]=='b')
    {
        cs50--;
    }

    float freq= 440 * (powf(2,(cs50- 10/ (float) 12)));
    return round (freq * (powf(2, orange- 4)));
}
bool is_rest(string s)
{
    if(strcmp(s,"\0")==0)
    {return true;}
    else
    {return false;}
}
