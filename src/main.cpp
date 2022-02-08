#include "Default.h"
#include "SikParser.hpp"
int main()
{
    Sikparser<std::string,char> parser("........... ........");
    
   cout<<parser.parse()<<endl;
   parser.changetext("... ,,, ...");
   cout<<parser.parse()<<endl;
}