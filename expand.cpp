#include<bits/stdc++.h>
using namespace std;
#define number_of_text 68170

string permute(string k, int* arr, int n){ 
    string per=""; 
    for(int i=0; i<n ; i++){ 
        per+= k[arr[i]-1]; 
    } 
    return per; 
} 

int main(){
    ifstream in("out.txt");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to in.txt!

    ofstream out("s_e_f-and-s_e_f_star.txt");
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect cout to out.txt!
    int exp_d[48]=  
    {    32,1,2,3,4,5,4,5, 
        6,7,8,9,8,9,10,11, 
        12,13,12,13,14,15,16,17, 
        16,17,18,19,20,21,20,21, 
        22,23,24,25,24,25,26,27, 
        28,29,28,29,30,31,32,1 
    };
    string word;
    for(int i=0; i<number_of_text * 2; i++){
        cin >> word;
        string f= word.substr(0, 32);
        string right_expanded= permute(f, exp_d, 48);
        cout << right_expanded << "\n";
    }

    return 0;
}