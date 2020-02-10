#include <bits/stdc++.h>
using namespace std;
#define number_of_text 68170

void xor_(char* a, char* b, char* ans, int n){ 
    for(int i=0; i<n; i++){ 
        if(a[i]==b[i]){ 
            ans[i] = '0'; 
        }else{ 
            ans[i] = '1'; 
        } 
    } 
} 

void decToBinary(int n, char* binaryNum, int size){
    int i = 0;
    for(int j=0; j<size; j++)
        binaryNum[j] = '0'; 
    while (n > 0) { 
        if(i >= size) return;
        binaryNum[i] = n % 2 + '0'; 
        n = n / 2; 
        i++; 
    } 
}  

int main(){
    int S[8][4][16] = {{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8, 
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 
    }, 
    { 
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5, 
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 
    }, 
  
  
    { 
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1, 
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 
    }, 
    { 
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9, 
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 
    }, 
    { 
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6, 
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 
    }, 
    { 
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8, 
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 
    }, 
    { 
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6, 
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 
    }, 
    { 
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2, 
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 
    }};
    FILE *f_sef, *f_sif_dash, *f_sof_dash, *f_key, *fd;
    f_sef = fopen("s_e_f-and-s_e_f_star.txt","r+");
    f_sif_dash = fopen("s_i_f_dash.txt","r+");
    f_sof_dash = fopen("s_o_f_dash.txt","r+");
    f_key = fopen("key.txt","w+");
    long long int count[8][64];
    for(int i=0; i<8; i++)
        for(int j=0; j<64; j++)
            count[i][j]=0;
    
    for(int text = 0 ; text < number_of_text; text++){
        char sef[64], sef_star[64], sif_dash[64], sof_dash[64], sef_dash[64];
        sef[48] = sef_dash[48] = sef_star[48] = sif_dash[48] = sof_dash[32] = '\0';
        fscanf(f_sef,"%s",sef);
        fscanf(f_sef,"%s",sef_star);
        fscanf(f_sif_dash,"%s",sif_dash);
        fscanf(f_sof_dash,"%s",sof_dash);
        xor_(sef, sef_star, sef_dash, 48);
        for(int s_box=0; s_box<8; s_box++){
            cout << "sbox no " << s_box << endl;
            char Ssi_dash[7], Sse[7], Sse_star[7], Sso_dash[7], Ssi[7], Ssi_star[7];
            for(int i=0; i<6; i++){
                Ssi_dash[i] = sif_dash[6*s_box + i];
                Sse[i] = sef[6*s_box + i];
                Sse_star[i] = sef_star[6*s_box + i];
            }
            Sse[6] = Ssi_dash[6] = Sse_star[6] = Sso_dash[6] = Ssi[6] = Ssi_star[6]= '\0';
            for(int i=0; i<4; i++){
                Sso_dash[i] = sof_dash[4*s_box + i];
            }
            for(int si=0; si<64; si++){
                cout << "si = " << si << endl;
                decToBinary(si, Ssi, 6);
                xor_(Ssi_dash, Ssi, Ssi_star, 6); // si_star = si_dash ^ si
                //calculate S(si)
                char sOfsi[4], sOfsi_star[4], sOfsi_dash[4];
                int row= 2*int(Ssi[0]-'0')+ int(Ssi[5]-'0'); 
                int col= 8*int(Ssi[1 ]-'0')+ 4*int(Ssi[2]-'0')+  
                                    2*int(Ssi[3]-'0')+ int(Ssi[4]-'0');
                if(row >= 4 || col >= 16) cout << "row and col out of bounds\n"; 
                int val= S[s_box][row][col]; 
                sOfsi[3]= char(val/8+ '0'); 
                val= val%8; 
                sOfsi[2]= char(val/4+ '0'); 
                val= val%4; 
                sOfsi[1]= char(val/2+ '0'); 
                val= val%2; 
                sOfsi[0]= char(val+ '0');
                //calculate S(si_star)
                row= 2*int(Ssi_star[0]-'0')+ int(Ssi_star[5]-'0'); 
                col= 8*int(Ssi_star[1 ]-'0')+ 4*int(Ssi_star[2]-'0')+  
                                    2*int(Ssi_star[3]-'0')+ int(Ssi_star[4]-'0'); 
                val= S[s_box][row][col]; 
                sOfsi_star[3]= char(val/8+ '0'); 
                val= val%8; 
                sOfsi_star[2]= char(val/4+ '0'); 
                val= val%4; 
                sOfsi_star[1]= char(val/2+ '0'); 
                val= val%2; 
                sOfsi_star[0]= char(val+ '0');
                //calculate S(si_star) ^ S(si)
                xor_(sOfsi, sOfsi_star, sOfsi_dash, 4);
                
                bool isEqual = true;
                for(int i=0; i<4; i++){
                    if(sOfsi_dash[i] != Sso_dash[i])
                        isEqual = false;
                }
                if(isEqual){
                    //key1 = si ^ se, key2 = si ^ se_star
                    char* end;
                    long int temp1, temp2, key1, key2;
                    temp1 = strtol(Sse_star, &end, 2);
                    temp2 = strtol(Sse, &end, 2);
                    cout << "Sse_star: " << Sse_star << " Sse = " << Sse <<"temp1 = " << temp1 << " temp2 = " << temp2 << " si = " << si << "\n";
                    cout << "key values are: " << (temp1^si) << " " << (temp2^si) << "\n";
                    count[s_box][temp1^si]+=1;
                    count[s_box][temp2^si]+=1;
                }
            }
        }
    }
    for (int i = 0; i < 8; ++i){
        fprintf(f_key, "sbox - %d\n", i);
      for(int j = 0 ; j < 64 ; ++j)
        fprintf(f_key, "%d = %lld\n",j,count[i][j]);
      fprintf(f_key, "---------------------------------\n");
    }

    return 0;
}