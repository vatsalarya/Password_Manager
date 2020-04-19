#include<bits/stdc++.h>
using namespace std;

string RandomPassword(int n);

int main(){
    cout<<"Welcome to Password Manager\n"
        <<"What would you like to do?\n"
        <<"1.)Generate Random Password.\n"
        <<"2.)Encrypt a message.\n"
        <<"2.)Decrypt a message.\n";
    int choice{};
    cin>>choice;
    if(choice == 1){
        int n{};
        cout<<"Enter length of password: ";
        cin>>n;
        string pass;
        pass = RandomPassword(n);
        cout<<"The Random Password generated is: "
        for(auto p : pass)
            cout<<p;
        cout<<endl;
    }
    return 0;
}

string RandomPassword(int n){
    srand(time(nullptr));
    string s;
    while(n--)
        s.push_back(rand()%127+48);
    return s;
}
