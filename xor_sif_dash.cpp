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

int main(){
    ifstream in("s_e_f-and-s_e_f_star.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("s_i_f_dash.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    string se, se_star;
    for(int i=0; i<number_of_text; i++){
        cin >> se >> se_star;
        cout << xor_(se, se_star) << "\n";
    }
}