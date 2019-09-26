#include "include/RSA.h"


RSA :: RSA ()
{};
void RSA :: settexte (string texte)
{text=texte;}
std::string RSA :: gettexte ()
{return text;}

int RSA :: pgcd (int a, int b)
{int c;
while(b != 0)
{c=a;
a=b;
b= c % a;}
return a;
}
int RSA::premier(int a)
{for(int i=1;i<=(a/2);i++)
    {
        if (pgcd(a,i)!=1) return 0;
    }return 1;
}
 int* RSA ::  euclide_etendu(int a, int b)
{int* z;
z=(int*)malloc(3);
int u=1,uu=0;
int v=0,vv=1;
int r,rr,rs,vs,us,q;
r=a;
rr=b;
while(rr != 0)
{q= r / rr;
rs = r;
us = u;
vs = v;
r = rr;
u = uu;
v = vv;
rr = rs - q *rr;
uu = us - q*uu;
vv = vs - q*vv;
};
*z=r;
*(z+1)=u;
*(z+2)=v;
return z;
};
int RSA :: puissance_modulo(int a, int b,int c)
{
     long x=1;
    long long y=a;
    while(b > 0)
        {
        if((b % 2) == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c;
        b = b / 2;
    }
    return (int) x%c;
}
int RSA :: inverse_module (int b , int n)
{int n0 = n;
int b0=b;
int t0 = 0;
int t= 1 ;
int q = n0 / b0 ;
int r = n0 - q * b0;
int temp;
while (r>0)
{temp = t0 - q * t;
if (temp >= 0) {temp = temp % n;}
               else {temp=n - ((-temp) %n); }
t0 =t;
t=temp;
n0=b0;
b0=r;
q=n0 / b0;
r = n0 - q * b0;}
return t;}

void RSA :: cle_public(int l,int k,int m,int o)
{p=l;
q=k;
n=p*q;
phi=(p-1)*(q-1);
e=m;
bloc=o;
}
void RSA :: cle_privee()
{d=inverse_module(e,phi);
}
void RSA :: crypter()
{int k=1;
string chaine="",res="";
int message;
for(unsigned int i=0;i<text.length();i++)
{ message = (int) text[i];
  ostringstream oss;
  oss << message;
  string resultat = oss.str();
  if(message<100) {resultat='0'+resultat;}
  res+=resultat;
  }
text=res;
res="";
for(unsigned int i=0;i< text.length();i++ )
{
                     chaine+=text [i];
                     k++;
                     if(k % (bloc+1) ==0 || i==text.length()-1) {istringstream ss(chaine);
                                   int result;
                                   ss >> result;
                                   chaine = "";
                                   message = puissance_modulo(result,e,n);
                                   ostringstream oss;
                                   oss << message;
                                   string resultat = oss.str();
                                   res+=resultat;
                                   res+=' ';
                                    k=1;}}
text=res;
}
void RSA :: getcle()
{cout<<"n=";
cout<<n<<endl;
cout<<"phi = ";
cout<<phi<<endl;
cout<<"e=";
cout<<e<<endl;
cout<<"d=";
cout<<d<<endl;}
void RSA :: decrypter()
{string chaine,res="";
for(unsigned int i=0;i<text.length();i++)
{if(text[i] != ' ')
                   {chaine+=text[i];}
                   else {istringstream ss(chaine);
                         int result;
                         ss >> result;
                         chaine = "";
                         int message = puissance_modulo(result,d,n);
                           ostringstream oss;
                           oss << message;
                           string resultat = oss.str();
                           if (text.length()-i>=bloc)
                           while (resultat.length()!=bloc) resultat='0'+resultat;
                           res+=resultat;
                           }
                         }
text=res;
res="";
int k=1;
for(unsigned int i=0;i< text.length();i++ )
{
                     chaine+=text [i];
                     k++;
                     if(k % (4) ==0 || i==text.length()-1) {
                         istringstream ss(chaine);
                         int result;
                         ss >> result ? result : 0;
                         chaine = "";
                         res+=(char)result;
                         k=1;}}

text=res;}

int RSA :: condition_RSA()
{
   if(! premier(p)) return 1;
   else {if (! premier(q)) return 2;
          else {if (p>=e || q>=e) return 3;
                else {if (pgcd(e,phi)!=1) return 4;
                    else{ if (n<pow(10,bloc)-1) return 5;
                        else return 0;}}}
}}
