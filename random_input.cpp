#include <bits/stdc++.h>
using namespace std;
#define number_of_text 100000

string hex2bin(string s){ 
	unordered_map<char, string> mp; 
	mp['0']= "0000"; 
	mp['1']= "0001"; 
	mp['2']= "0010"; 
	mp['3']= "0011"; 
	mp['4']= "0100"; 
	mp['5']= "0101"; 
	mp['6']= "0110"; 
	mp['7']= "0111"; 
	mp['8']= "1000"; 
	mp['9']= "1001"; 
	mp['A']= "1010"; 
	mp['B']= "1011"; 
	mp['C']= "1100"; 
	mp['D']= "1101"; 
	mp['E']= "1110"; 
	mp['F']= "1111"; 
	string bin=""; 
	for(int i=0; i<s.size(); i++){ 
		bin+= mp[s[i]]; 
	} 
	return bin; 
} 
string bin2hex(string s){ 
		// binary to hexadecimal conversion 
	unordered_map<string, string> mp; 
	mp["0000"]= "0"; 
	mp["0001"]= "1"; 
	mp["0010"]= "2"; 
	mp["0011"]= "3"; 
	mp["0100"]= "4"; 
	mp["0101"]= "5"; 
	mp["0110"]= "6"; 
	mp["0111"]= "7"; 
	mp["1000"]= "8"; 
	mp["1001"]= "9"; 
	mp["1010"]= "A"; 
	mp["1011"]= "B"; 
	mp["1100"]= "C"; 
	mp["1101"]= "D"; 
	mp["1110"]= "E"; 
	mp["1111"]= "F"; 
	string hex=""; 
	for(int i=0; i<s.length(); i+=4){ 
		string ch=""; 
		ch+= s[i]; 
		ch+= s[i+1]; 
		ch+= s[i+2]; 
		ch+= s[i+3]; 
		hex+= mp[ch]; 
	} 
	return hex; 
} 

int main()
{
  FILE *fi,*fo;
  fi = fopen("random_bits.txt","r+");
  fo = fopen("omega1_P.txt","w+");
  long long int i = 0;
  long long int k;
  char P[64];
  long long int P_dash[64];
  char  s1[17],s2[17];
  string inverse_omega1 = "0000801000004000";
  string inverse_omega2 = "0000080100100000";
  string s = hex2bin(inverse_omega1);

  while(i < number_of_text)
  {
    fscanf(fi,"%s",P);
    for(int j = 0 ; j < 64 ; j++)
    {
      P_dash[j] =((long long int)(P[j] - 48)^(long long int)(s[j] - 48));
    }
    int l;
    for(l = 0 ; l < 16 ; l++)
    {
      int h1,h2;
      h1 = (P[l*4]-48)*8+(P[l*4+1]-48)*4+(P[l*4+2]-48)*2+(P[l*4+3]-48);
      h2 = P_dash[l*4]*8+P_dash[l*4+1]*4+P_dash[l*4+2]*2+P_dash[l*4+3];
      h1 += 102;
      h2 += 102;
      s1[l] = h1;
      s2[l] = h2;
    }
    s1[l] = '\0';
    s2[l] = '\0';
    i++;
    fprintf(fo, "%s\n",s1);
    fprintf(fo, "%s\n",s2);
    //k temp
  }
}