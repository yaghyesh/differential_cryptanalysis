#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
#define number_of_text 68170

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
    mp['a']= "1010"; 
    mp['b']= "1011"; 
    mp['c']= "1100"; 
    mp['d']= "1101"; 
    mp['e']= "1110"; 
    mp['f']= "1111"; 
    string bin=""; 
    for(int i=0; i<s.size(); i++){ 
        bin+= mp[s[i]]; 
    } 
    return bin; 
} 

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
} 

int main()
{
    ifstream in("output_clean.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("out.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    int initial_perm[64]=  
    {    58,50,42,34,26,18,10,2, 
        60,52,44,36,28,20,12,4, 
        62,54,46,38,30,22,14,6, 
        64,56,48,40,32,24,16,8, 
        57,49,41,33,25,17,9,1, 
        59,51,43,35,27,19,11,3, 
        61,53,45,37,29,21,13,5, 
        63,55,47,39,31,23,15,7 
    };
    string word;
    for(int i=0; i<2*number_of_text; i++){
        cin >> word;
        string result;
        for(int i=0; i<word.length(); i++){
            stringstream stream;
            stream << hex << (word[i] - 'f');
            result.append( stream.str());   
        }
        cout << permute(hex2bin(result), initial_perm, 64) << "\n";
    }
    return 0;
}