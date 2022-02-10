#include "Default.h"
#include "SikParser.hpp"
#include "ByeonsuParser.hpp"
int main()
{
    Datatype d;
    SikParser<std::wstring,wchar_t,std::wistream&> parser(d);
    
   cout<<parser.parse(L"식? 식?")<<endl;
}