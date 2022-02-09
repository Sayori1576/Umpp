#pragma once
#include "Default.h"
class Datatype
{
public:
int getvalue(int num);
void setvalue(int num,int value);
Datatype()
{
    data.resize(100);
    for(int i=0;i<100;i++)
    {
        data[i]=i+1;
    }
}
private:
std::vector<int> data;
};