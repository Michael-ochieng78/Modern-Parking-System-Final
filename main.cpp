

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    int slot[5]={0};
    string plate[5];
    int inH[5]={0};
    while(1){
        cout<<"\n1.Display 2.Entry 3.Exit 4.Admin 5.Close\nchoice: ";
        int c; cin>>c;
        if(c==1){
            for(int i=0;i<5;i++){
                if(slot[i]==0) cout<<i+1<<" FREE\n";
                else cout<<i+1<<" "<<plate[i]<<"\n";
            }
        }
        else if(c==2){
            int p=-1;
            for(int i=0;i<5;i++) if(slot[i]==0){p=i; break;}
            if(p==-1){cout<<"full\n"; continue;}
            cout<<"plate: "; cin>>plate[p];
            cout<<"hour in: "; cin>>inH[p];
            slot[p]=1;
            cout<<"bay "<<p+1<<" open\n";
            ofstream f1("db.txt", ios::app);
            f1<<plate[p]<<" in "<<inH[p]<<"\n";
            f1.close();
        }
        else if(c==3){
            string s; cout<<"plate: "; cin>>s;
            int p=-1;
            for(int i=0;i<5;i++) if(plate[i]==s){p=i; break;}
            if(p==-1){cout<<"no car\n"; continue;}
            int out; cout<<"hour out: "; cin>>out;
            int hrs=out-inH[p]; if(hrs<=0) hrs=1;
            cout<<"hours "<<hrs<<"\n";
            int fee;
            if(hrs<=1) fee=0;
            else if(hrs<=2) fee=50;
            else if(hrs<=4) fee=100;
            else if(hrs<=6) fee=300;
            else fee=500;
            cout<<"fee "<<fee<<"\n";
            cout<<"pay 1.mpesa 2.card 3.cash: ";
            int m; cin>>m;
            string pay;
            if(m==1) pay="mpesa"; else if(m==2) pay="card"; else pay="cash";
            int vat=fee*0.16;
            cout<<"vat "<<vat<<" method "<<pay<<"\n";
            cout<<"pay y/n: "; char y; cin>>y;
            if(y=='y'){
                cout<<"barrier open\n";
                ofstream f2("audit.txt", ios::app);
                f2<<s<<" hrs "<<hrs<<" fee "<<fee<<" vat "<<vat<<" pay "<<pay<<"\n";
                f2.close();
                slot[p]=0; plate[p]="";
            }
        }
        else if(c==4){
            string line;
            ifstream f3("audit.txt");
            while(getline(f3,line)) cout<<line<<"\n";
            f3.close();
        }
        else break;
    }
}