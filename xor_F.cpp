#include<bits/stdc++.h>
using namespace std;
#define number_of_text 68170

string xor_(string a, string b){ 
    string ans= ""; 
    for(int i=0; i<a.size(); i++){ 
        if(a[i]==b[i]){ 
            ans+= "0"; 
        }else{ 
            ans+= "1"; 
        } 
    } 
    return ans; 
} 

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
}

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

int main(){
    ifstream in("out.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("s_o_f_dash.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    string t1, t2, r, F, s_i_dash;
    string a = hex2bin("04000000");
    int inv_p[32] = {
    9, 17, 23, 31,
    13, 28, 2, 18,
    24, 16, 30, 6,
    26, 20, 10, 1,
    8, 14, 25, 3,
    4, 29, 11, 19,
    32, 12, 22, 7,
    5, 27, 15, 21 };
    for(int i=0; i<number_of_text; i++){
        cin >> t1 >> t2;
        r = (xor_(t1, t2)).substr(32, 64);
        F = xor_(r, a);
        s_i_dash = permute(F, inv_p, 32);
        cout << s_i_dash << "\n"; 
    }
    return 0;
    // F' = a' ^ D' ^ l'
}