template <typename ST,typename CT>
class Sikparser
{
public:
    Sikparser(ST s,CT p='.',CT m=' ', CT mi=',' ):str(s),plusstr(p),modulatestr(m),minusstr(mi){};
    int parse(int now=0);
    void changetext(const ST& t)
    {
        str=t;
    }
private:
    ST str;
    CT plusstr;
    CT modulatestr;
    CT minusstr;
};
template <typename ST,typename CT>
int Sikparser<ST,CT>::parse(int now)
{
    int num=0;
    for(size_t i=now;i<str.size();i++)
    {
        if(plusstr==str[i])
        {
            num++;
        }
        else if(minusstr==str[i])
        {
            num--;
        }
        else if(modulatestr==str[i])
        {
            num=num*parse(i+1);
            break;
        }
        /*
        경우에 따른 오류 처리 필요
        */
    }
    return num;
}