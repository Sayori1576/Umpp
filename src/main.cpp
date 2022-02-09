#include "Default.h"
#include "SikParser.hpp"
int main()
{
    Datatype d;
    Sikparser<std::wstring,wchar_t> parser(d);
    
   cout<<parser.parse(L"어. 어어")<<endl;
}