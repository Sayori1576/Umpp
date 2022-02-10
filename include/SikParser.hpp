#pragma once
#include "Default.h"
#include "Datatype.h"

template <typename ST, typename CT, typename STRT>
class SikParser
{
public:
    SikParser(const Datatype &d, CT p = L'.', CT m = L' ', CT mi = L',', CT v = L'어', const ST &in = L"식?", STRT i = std::wcin)
        : data(d), plusstr(p), modulatestr(m), minusstr(mi), varstr(v), inputstr(in), is(i),inputtemp(0){};
    int parse(const ST &str, int now = 0);

private:
    Datatype data;
    CT plusstr;
    CT modulatestr;
    CT minusstr;
    CT varstr;
    ST inputstr;
    STRT is;
    int inputtemp;
};
template <typename ST, typename CT, typename STRT>
int SikParser<ST, CT, STRT>::parse(const ST &str, int now)
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
        else if (str[i] == varstr)
        {
            // cout<<"엄"<<endl;
            size_t j;
            for (j = i; j < str.size(); j++)
            {
                if (str[j] != varstr)
                {
                    break;
                }
            }
            j--;
            cout << j << " " << data.getvalue(j - i) << endl;
            num += data.getvalue(j - i);
            i = j;
        }
        else if (str[i] == inputstr[0] && str[i + 1] == inputstr[1])
        {
            is>>inputtemp;
            num+=inputtemp;
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