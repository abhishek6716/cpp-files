#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string IntToRom(int num){
    string units[]={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[]={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[]={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[]={"", "M", "MM", "MMM"};

    return thousands[num/1000]+hundreds[(num%1000)/100]+tens[(num%100)/10]+units[num%10];
}

int RomToInt(string s){
        int num = 0;
        bool iFlag = false;
        bool xFlag = false;
        bool cFlag = false;
        for(int i = 0; i < s.length(); i++){
            char temp = s.at(i); //III will give me I
            switch(temp){
                case 'I':
                    num += 1;
                    iFlag = true;
                    break;
                case 'V':
                    if(iFlag == true){
                        num += 3;
                        iFlag = false;
                    }else{
                        num += 5;
                    }
                    break;
                case 'X':
                    if(iFlag == true){
                        num += 8;
                        iFlag = false;
                    }else{
                        num += 10;  
                        xFlag = true;
                    }
                    break;
                case 'L':
                    if(xFlag == true){
                        num += 30;
                        xFlag = false;
                    }else{
                        num += 50;
                    }
                    break;
                case 'C':
                    if(xFlag == true){
                        num += 80;
                        xFlag = false;
                    }else{
                        num += 100;
                        cFlag = true;
                    }
                    break;
                case 'D':
                    if(cFlag == true){
                        num += 300;
                        cFlag = false;
                    }else{
                        num += 500;
                    }
                    break;
                case 'M':
                    if(cFlag == true){
                        num += 800;
                        cFlag = false;
                    }else{
                        num += 1000;
                    }
                    break;
                default:
                    num += 0;
            }
        }
        return num;
}

int main(){
    int n; cin>>n;
    string roman=IntToRom(n);
    cout<<roman;
}
/*

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

*/