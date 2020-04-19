#include<bits/stdc++.h>
using namespace std;

string RandomPassword(int n);
string EncryptMessage(string s);
string DecryptMessage(string s);
void DesplayWelcome();
void DisplayOption();

int main(){
    int choice{};
    while(true){
        DesplayWelcome();
        cin>>choice;
        if(choice == 4)
            break;
        else if(choice == 1){
            int n{};
            cout<<"Enter length of password: ";
            cin>>n;
            string pass;
            pass = RandomPassword(n);
            cout<<"\nThe Random Password generated is: "<<pass<<"\n\n";
            label_1_1:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                
            }
            else if(choice == 2){
            
            }
            else{
                cout<<"\n\nChoose a valid option: \n";
                goto label_1_1;
            }
        }

        else if(choice == 2){
            label_2_1:
            cout<<"\nWould you like to:\n" 
                <<"1.)Enter text to be encrypted.\n"
                <<"2.)Encrypt a text file.\n"
                <<"Enter your choice: ";
            cin>>choice;
            if(choice == 1){
                string s;
                cout<<"Enter text to be Encrypted: ";
                cin>>s;
                s = DecryptMessage(s);
                cout<<"\nEncrypted Text is: "<<s<<"\n\n";
            }
            else if(choice == 2){

            }
            else{
                cout<<"\n\nChoose a valid option: \n";
                goto label_2_1;
            }
            label_2_2:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                
            }
            else if(choice == 2){
                
            }
            else{
                cout<<"\n\nChoose a valid option: \n";
                goto label_2_2;
            }
        }
        else if(choice == 3){
            label_3_1:
            cout<<"Would you like to:\n" 
                <<"1.)Enter text to be decrypted.\n"
                <<"2.)Decrypt a text file.\n"
                <<"Enter your choice: ";
            cin>>choice;
            if(choice == 1){
                string s;
                cout<<"Enter text to be decrypted: ";
                cin>>s;
                s = DecryptMessage(s);
                cout<<"\nDecrypted Text is: "<<s<<"\n\n";
            }
            else if(choice == 2){

            }
            else{
                cout<<"\n\nChoose a valid option: \n";
                goto label_3_1;
            }
            label_3_2:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                
            }
            else if(choice == 2){
                
            }
            else{
                cout<<"\n\nChoose a valid option: \n";
                goto label_3_2;
            }
        }
        else{
            cout<<"\nChoose valid option: \n";
        }
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
string EncryptMessage(string s){
    string s1{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    string key{};
}
string DecryptMessage(string s){
    return s;
}
void DesplayWelcome(){
    cout<<"\nWelcome to Password Manager\n"
        <<"1.)Generate Random Password.\n"
        <<"2.)Encrypt a message.\n"
        <<"3.)Decrypt a message.\n"
        <<"4.)Exit.\n"
        <<"What would you like to do: ";
}
void DisplayOption(){
    cout<<"Would you like to:\n" 
        <<"1.)Save this Text(Encrypted).\n"
        <<"2.)Send this Text(Encrypted).\n"
        <<"Enter your choice: ";
}
