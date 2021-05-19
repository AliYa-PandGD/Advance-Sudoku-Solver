#include <iostream>
#include <fstream>
using namespace std;
void GETdata(int adad[9][9]){
    //get data from file
    string get;
    fstream getData ("Data.txt");
    int j = 0 , k = 0;
    while(getline(getData , get)){
        for(int i=0;i<get.size();i++){
            if(get[i] == ' '){
                continue;
            }
            else if( 48<=get[i] && get[i] <= 57){
                adad[j][k] = (int)get[i] - 48;
                k++;
            }
        }
        k = 0;
        j++;
    }
}
bool clomnChe(int check , int adad[9][9]){
    return true;
}
bool RowChe(int check , int adad[9][9]){
    return true;
}
void emptySqu(int check){
    int numPo = 0;
    int address[10][2];
    for(int i =c;i<3+c;i++){
        for(int j=h;j<3+h;j++){
            if(adad[i][j] == 0){
               bool CloRes = clomnChe(check , adad);
               bool RowRes = RowChe(check , adad);
               if(CloRes && RowRes){
                    address[numPo][numPo] = i;
                    address[numPo][numPo+1] = j;
                    numPo++;
               }
            }
        }
    }
    if(numPo==2){
        clone[address[0][0]][address[0][1]][check-1] = 1;
        clone[address[1][0]][address[1][1]][check-1] = 1;
        if(address[0][0] == address[1][0]){

        }
    }
}
// in clone 0 means is not possible and 1 is possible;
void del(int adad[9][9] , int check[9] , int c , int h , int clone[9][9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                clone[i][j][k] = 0;
            }
        }
    }
    bool exist = false;
    for(int k=0;k<9;k++){
        for(int i =c;i<3+c;i++){
            for(int j=h;j<3+h;j++){
                if(check[k] == adad[i][j]){
                    exist = true;
                }
            }
        }
        if(exist){
            continue;
        }
        emptySqu(check[k]);
    }
}


void setupADV(int adad[9][9] , int clone[9][9][9]){
    int check[9] = { 1 ,2 , 3,4,5,6,7,8,9} ;
    del(adad , check , 6 , 6);
}
int main()
{
    int adad[9][9];
    int clone[9][9][9];
    GETdata(adad);
    setupADV(adad , clone)
    return 0;
}
