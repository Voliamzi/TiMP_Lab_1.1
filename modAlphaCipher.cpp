#include "modAlphaCipher.h"
using namespace std;
modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (unsigned poz=0; poz<Alf.size(); poz++) {
        Alf_N[Alf[poz]]=poz;
    }
    key = convert(skey);
}
wstring modAlphaCipher::encrypt(const wstring& text)
{
    vector<int> encrypt_text = convert(text);
    for(unsigned poz=0; poz < encrypt_text.size(); poz++) {
        encrypt_text[poz] = (encrypt_text[poz] + key[poz % key.size()]);
    }
    return convert(encrypt_text);
}
wstring modAlphaCipher::decrypt(const wstring& text)
{
    vector<int> decrypt_text = convert(text);
    for(unsigned poz=0; poz < decrypt_text.size(); poz++) {
        decrypt_text[poz] = (decrypt_text[poz] + Alf_N.size() - key[poz % key.size()]) % Alf_N.size();
    }
    return convert(decrypt_text);
}
inline vector<int> modAlphaCipher::convert(const wstring& s_v)
{
    vector<int> result;
    for(auto c:s_v) {
        result.push_back(Alf_N[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v_s)
{
    wstring result;
    for(auto poz:v_s) {
        result.push_back(Alf[poz]);
    }
    return result;
}