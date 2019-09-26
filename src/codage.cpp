#include "include/codage.h"



chiffredecesar::chiffredecesar(int k ,string t)
{cle=k;
text=t;}

void chiffredecesar :: crypter()
{
 string res="";
for(int i=0;text[i];i++)
{if (text[i]>='a' && text[i]<='z') res+=(text[i]-'a'+cle)%26+'a';
else {if (text[i]>='A' && text[i]<='Z') res+=(text[i]-'A'+cle)%26+'A';
else res+=text[i];}
}text=res;
}
void chiffredecesar :: decrypter()
{
    string res="";
    for(int i=0;text[i];i++)
    {if (text[i]>='a' && text[i]<='z') res+=(text[i]-'a'-cle+26)%26+'a';
    else {if (text[i]>='A' && text[i]<='Z') res+=(text[i]-'A'-cle+26)%26+'A';
    else res+=text[i];}
    }text=res;
}
string chiffredecesar ::gettexte()
{
    return text;
}
/*********************************************************************/

chiffreduche::chiffreduche(string k,string t)
{cle=k;
text=t;}

void chiffreduche ::crypter()
{
    string res="";
    int t[26]={6,38,32,4,8,30,36,34,39,31,78,72,70,76,9,79,71,58,2,0,52,50,56,54,1,59};
    int i,j,k;
    for (i=0,j=0,k=-1;text[i]; i++,j++) {

         if ((j+1)%6==0 )
            {res+=' ';
            j++;
            }
         if (text[i]>='A' && text[i]<='Z')
          {if (t[text[i]-'A']/10!=0)
            {res+=(t[text[i]-'A']/10+cle[(++k)%5]-'0')%10+'0';
            j++;
           if ((j+1)%6==0 )
            {res+=' ';
            j++;
            }
            res+=(t[text[i]-'A']%10+cle[(++k)%5]-'0')%10+'0';

            }
        else res+=(t[text[i]-'A']+cle[(++k)%5]-'0')%10+'0';
           }else
         {if (t[text[i]-'a']/10!=0)
             {res+=(t[text[i]-'a']/10+cle[(++k)%5]-'0')%10+'0';
             j++;
            if ((j+1)%6==0 )
             {res+=' ';
             j++;
             }
             res+=(t[text[i]-'a']%10+cle[(++k)%5]-'0')%10+'0';

             }
         else res+=(t[text[i]-'a']+cle[(++k)%5]-'0')%10+'0';
            }}
text=res;

}
void chiffreduche :: decrypter()
{   string res="";
    map<int,char> m={{6,'A'},{38,'B'},{32,'C'},{4,'D'},{8,'E'},{30,'F'},{36,'G'},{34,'H'},{39,'I'},{31,'J'},{78,'K'},{72,'L'},{70,'M'},{76,'N'},{9,'O'},{79,'P'},{71,'Q'},{58,'R'},{2,'S'},{0,'T'},{52,'U'},{50,'V'},{56,'W'},{54,'X'},{1,'Y'},{59,'Z'}};
    int i,j,k,nb;
    string b="";
    for (j=0,k=-1,i=0;text[i];i++) {

        if (text[i]!=' ')
            {b+=(text[i]-'0'+(10-cle[(++k)%5]+'0'))%10+'0';
            j++;}
    }
    for (i=0,j=0;b[i];i++)
    { if (b[i]=='3' || b[i]=='5' || b[i]=='7')
        {nb=(b[i]-'0')*10+b[i+1]-'0';
        i++;
        res+=m[nb];
        j++;}
        else
        {res+=m[b[i]-'0'];
        j++;
        }
    }
text=res;
}
string chiffreduche :: gettexte ()
{return text  ;}
/******************************************************************************************/



chiffredevigenere::chiffredevigenere(string k,string t)
{text=t;
cle=k;}

void chiffredevigenere :: crypter()
{string res="";
 char c;
 for (int i=0,k=-1;text[i]; ++i) {
     c=cle[(++k)%(cle.length())];
     if ((text[i]>='A')&&(text[i]<='Z'))
     {if(c>='a' && c<='z')  res+='A'+(text[i]+c-'A'-'a')%26;
       else res+='A'+(text[i]+c-2*'A')%26;}
     else {if ((text[i]>='a')&&(text[i]<='z'))
          { if (c>='a' && c<='z')
         res+='a'+(text[i]+c-2*'a')%26;
         else res+='a'+(text[i]+c-'a'-'A')%26;}
         else res+=text[i];}}

text=res;
}

void chiffredevigenere :: decrypter()
{string res;
 char c;
    for (int i=0,k=-1;text[i]; ++i) {
        c=cle[(++k)%(cle.length())];
        if ((text[i]>='A')&&(text[i]<='Z'))
        {if(c>='a' && c<='z')  res+='A'+(text[i]-c-'A'+'a'+26)%26;
          else res+='A'+(text[i]-c+26)%26;}
        else {if ((text[i]>='a')&&(text[i]<='z'))
             { if (c>='a' && c<='z')
            res+='a'+(text[i]-c+26)%26;
            else res+='a'+(text[i]-c-'a'+'A'+26)%26;}
            else res+=text[i];}}
    text=res;
}
string chiffredevigenere :: gettexte()
{
   return text;
 }


chiffredemorse::chiffredemorse(string t)
{text=t;
    v[0]="._";
    v[1]="_...";
    v[2]="_._.";
    v[3]="_..";
    v[4]=".";
    v[5]=".._.";
    v[6]="__.";
    v[7]="....";
    v[8]="..";
    v[9]=".___";
    v[10]="_._";
    v[11]="._..";
    v[12]="__";
    v[13]="_.";
    v[14]="___";
    v[15]=".__.";
    v[16]="__._";
    v[17]="._.";
    v[18]="...";
    v[19]="_";
    v[20]=".._";
    v[21]="..._";
    v[22]=".__";
    v[23]="_.._";
    v[24]="_.__";
    v[25]="__..";
}
void chiffredemorse::crypter()
{
    string res="";
    for (unsigned int i=0;i<text.length();i++)
    {
        if (text[i]>='a' && text[i]<='z') text[i]-=32;
        if (text[i]>='A' && text[i]<='Z')
        res+=v[text[i]-65]+" ";
        else res+="/ ";
    }res[res.length()]=0;
    text=res;
}
void chiffredemorse::decrypter()
{
    string res="";
    string chaine="";
    for (unsigned int i=0;i<text.length();i++)
    {
        if (text[i]!=' '  && i<text.length())
            chaine+=text[i];

        else {for(int j=0;j<26 ;j++)
        {
            if (chaine==v[j])
            {res+=(char)(j+65);
            chaine="";
            }
            else{
                if (chaine=="/")
                {res+=" ";
                chaine=""; }
                }
     }
    }

}
text=res;}
string chiffredemorse::gettexte()
{
    return text;
}


/********************************************************************************************/
chiffredeplayfair :: chiffredeplayfair (string key,string t)
{
    text=t;
    createKey(key);
}
void chiffredeplayfair :: crypter() {
      int j,k,p,q;
      string res="";
      transformerText();
      for(unsigned int i=0;i<text.length(); i+=2 ) {

         if( getPos(text[i], j, k ) )
         if( getPos(text[i+1], p, q)) {

            //for same row
            if( j == p ) {
               res+= getChar( j, k+1 );
               res += getChar( p, q+1 );
            }
            //for same column
            else {if( k == q ) {
               res += getChar( j+1, k );
               res += getChar( p+1, q );}
                else {
               res += getChar( p, k );
               res += getChar( j, q );
                   }         }
      }}
      text = res;
      cout<<text<<endl;
}

char chiffredeplayfair::getChar( int a, int b ) { //get the characters
      return n[ (b + 5) % 5 ][ (a + 5) % 5 ];
   }
   bool chiffredeplayfair:: getPos( char l, int &c, int &d ) { //get the position
      for( int y = 0; y < 5; y++ )
      for( int x = 0; x < 5; x++ )
      if( n[y][x] == l ) {
         c = x;
         d= y;
      return true;
      }
      return false;
   }
   void chiffredeplayfair:: transformerText() {
   string res="";
      for(unsigned int i=0;i<text.length(); i++) {
         text[i]= toupper(text[i]);
         if( text[i]< 65 || text[i] > 90 )
            continue;
         res +=text[i];
      }text=res;
      res="";
         for(unsigned int x = 0; x <text.length(); x += 2 ) {
            res += text[x];
            if( x + 1 <text.length() ) {
               if( text[x] == text[x + 1] ) res += 'X';
               res += text[x + 1];
            }
         }
         text = res;
      if( text.length() & 1 )
      text += 'X';
   }
   void chiffredeplayfair:: createKey( string key) { //creation of the key table
      if( key.length() < 1 )
      key= "KEYWORD";
      key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";
      string s= "";
      for(unsigned int i=0;i<key.length();i++) {
         key[i]= toupper(key[i] );
         if(key[i]< 65 || key[i]> 90 )
            continue;
         if( s.find(key[i]) == -1 )
            s +=key[i];
      }
      copy( s.begin(), s.end(), &n[0][0] );
      cout<<"key= "<<s<<endl;
   }
string chiffredeplayfair:: gettexte() {
    return text;}
