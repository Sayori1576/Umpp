#pragma once
#include "Default.h"
#include "SikParser.hpp"
template <typename ST, typename CT,typename STR>
class ByeonsuParser
{
public:
    ByeonsuParser(SikParser<ST, CT,STR> p, CT pl=L'어', CT m=L'ㅋ')
        : parser(p), plusstr(pl), modechangestr(m)
    {
    }
    int parse(ST str);

private:
    CT plusstr;
    CT modechangestr;
    SikParser<ST, CT,STR> parser;
};
template <typename ST,typename CT,typename STR>
int ByeonsuParser<ST,CT,STR>::parse(ST str)
{
return 0;
}