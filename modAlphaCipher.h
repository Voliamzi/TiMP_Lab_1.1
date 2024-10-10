#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;
class modAlphaCipher
{
private:
    wstring Alf = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //Алфавит
    map <char,int> Alf_N; //Ассоциативный массив "номер по символу"
    vector <int> key; //Ключ
    vector<int> convert(const wstring& s_v); //Преобразование строка-вектор
    wstring convert(const vector<int>& v_s); //Преобразование вектор-строка
public:
    modAlphaCipher()=delete; //Запретим конструктор без параметров
    modAlphaCipher(const wstring& skey); //Конструктор для установки ключа
    wstring encrypt(const wstring& text); //Зашифровка
    wstring decrypt(const wstring& text);//Расшифровка
};