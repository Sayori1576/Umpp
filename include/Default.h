#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
#include <climits>
#include <thread>
#include <chrono>
#include <string_view>
#pragma once
using std::cin;
using std::cout;
using std::endl;
inline void cinnum()
{

	cin.clear();

	cin.ignore(INT_MAX, '\n');

	cout << "잘못된 값을 입력하셨습니다. 숫자만 입력해주세요.\n";
}
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
inline void Sleep(clock_t milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
const int sleeptime = 1000;

inline std::string utf8_substr(const std::string& str, unsigned int start, unsigned int leng)
{
    if (leng==0) { return ""; }
    size_t c, i, ix, q, min=std::string::npos, max=std::string::npos;
    for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
    {
        if (q==start){ min=i; }
        if (q<=start+leng || leng==std::string::npos){ max=i; }

        c = (unsigned char) str[i];
        if      (
                 //c>=0   &&
                 c<=127) i+=0;
        else if ((c & 0xE0) == 0xC0) i+=1;
        else if ((c & 0xF0) == 0xE0) i+=2;
        else if ((c & 0xF8) == 0xF0) i+=3;
        //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
        //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
        else return "";//invalid utf8
    }
    if (q<=start+leng || leng==std::string::npos){ max=i; }
    if (min==std::string::npos || max==std::string::npos) { return ""; }
    return str.substr(min,max);
}
#ifdef _WIN32

// 화면을 모두 지운다.
inline void clrscr()
{
	system("cls");
}

#else
inline void clrscr()
{
	system("clear");
}

#endif
