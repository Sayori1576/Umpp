#pragma once
#include "Default.h"
#include "Datatype.h"

template <typename ST, typename CT>
class Sikparser
{
public:
    Sikparser(const Datatype &d, CT p = L'.', CT m = L' ', CT mi = L',', CT v = L'어')
        : data(d), plusstr(p), modulatestr(m), minusstr(mi), varstr(v){};
    int parse(const ST &str, int now = 0);

private:
    Datatype data;
    CT plusstr;
    CT modulatestr;
    CT minusstr;
     CT varstr;
};
template <typename ST, typename CT>
int Sikparser<ST, CT>::parse(const ST &str, int now)
{
    int num = 0;
    for (size_t i = now; i < str.size(); i++)
    {
        if (plusstr == str[i])
        {
            num++;
        }
        else if (minusstr == str[i])
        {
            num--;
        }
        else if(str[i]==varstr)
        {
           // cout<<"엄"<<endl;
            size_t j;
            for(j=i;j<str.size();j++)
            {
                if(str[j]!=varstr)
                {
                    break;
                }
            }
            j--;
            cout<<j<<" "<<data.getvalue(j-i)<<endl;
            num+=data.getvalue(j-i);
            i=j;
        }
        else if (modulatestr == str[i])
        {
            num = num * parse(str, i + 1);
            break;
        }
        /*
        경우에 따른 오류 처리 필요
        */
    }
    return num;
}