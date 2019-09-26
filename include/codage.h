#ifndef CODAGE_H
#define CODAGE_H
#include<bits/stdc++.h>
using namespace std ;


class chiffredecesar
{private:
        int cle;
        string text;
public:
        chiffredecesar(int k,string t);
        void crypter();
        void decrypter();
        string gettexte();
};



class chiffreduche
{private:
        string cle;
        string text;
 public:
        chiffreduche(string k,string t);
        void crypter();
        void decrypter();
        string gettexte();
 };

 class chiffredevigenere
 {private:
        string text;
        string cle;

 public:
        chiffredevigenere(string k,string t);
        string gettexte();
        void crypter();
        void decrypter();
 };

 class chiffredemorse
 {private:
     string text;
     string v[26];
  public:
     chiffredemorse(string t);
     void crypter();
     void decrypter();
     string gettexte();
};

 class chiffredeplayfair
 {private:
     string text;
     char n[5][5];
  public:
     chiffredeplayfair(string key,string t);
     void transformerText();
     string gettexte();
     void crypter();
     //void decrypter();
     void createKey(string key);
     char getChar( int a, int b );
     bool getPos( char l, int &c, int &d );
};
#endif
