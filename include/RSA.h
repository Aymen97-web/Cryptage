#ifndef CHIFFREMENT_RSA_H_INCLUDED
#define CHIFFREMENT_RSA_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
class RSA
{private:
int p,q,n,phi; //cle publique
int e; //cle publique
int d; //cle privée
int bloc; //nombre de blocs
string text;
public:
RSA ();
void settexte(string texte);
string gettexte();
void getcle();
void transformertexte();
int inverse_module (int b , int n);
void cle_public(int k,int l,int m,int o);
void cle_privee();
void crypter();
void decrypter();
int puissance_modulo(int x,int k,int n);
int* euclide_etendu (int a , int b);
int pgcd(int a , int b);
int condition_RSA();
int premier(int a);
};
#endif
