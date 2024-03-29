#include <stdio.h>
#include <iostream>
#include <cctype>
#include "PermutationCipher.h"
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        PermutationCipher skey(key);
        wcout<<skey.CoderPermutationCipher(key, s)<<endl;
        wstring g=skey.CoderPermutationCipher(key, s);
        wcout<<skey.DecoderPermutationCipher(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"pROceSsIng",5);
    check(L"pROceSsIng",7);
    check(L"GRTMNEBYMD",3);
    return 0;
}