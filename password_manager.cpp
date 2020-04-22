#include<bits/stdc++.h>
using namespace std;

string RandomPassword(int n);
string EncryptMessage(string s);
string DecryptMessage(string s);
void DisplayWelcome();
void DisplayOption();
void Write_to_file(string s);
string ReadFromFile();
string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"};
string key      {"F9ODXJR4Ybt7emEBl3S5HoTP2yxpLWf0aVQsgAhnKwM1CNUI6v8ujqGkZrdzci"};

int main(){
    int choice{};
    while(true){
        DisplayWelcome();
        cin>>choice;
        cout<<"\n\t\t\t\t\t\t ------------------------------------------------\n";
        if(choice == 4)
            break;
        else if(choice == 1){
            int n{};
            cout<<"\t\t\t\t\t\t\t    Enter length of password: ";
            cin>>n;
            string pass;
            pass = RandomPassword(n);
            cout<<"\n\t\t\t\t\t\tThe Random Password generated is: "<<pass<<"\n";
            label_1_1:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                Write_to_file(pass);
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
            string s;
            if(choice == 1){
                cout<<"Enter text to be Encrypted: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,s);
                s = EncryptMessage(s);
                cout<<"\nEncrypted Text is: "<<s<<"\n\n";
            }
            else if(choice == 2){
                s = ReadFromFile();
            }
            else{
                cout<<"\nChoose a valid option: \n";
                goto label_2_1;
            }
            label_2_2:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                Write_to_file(s);
            }
            else if(choice == 2){
                
            }
            else{
                cout<<"\nChoose a valid option: \n\n";
                goto label_2_2;
            }
        }
        else if(choice == 3){
            label_3_1:
            cout<<"\nWould you like to:\n" 
                <<"1.)Enter text to be decrypted.\n"
                <<"2.)Decrypt a text file.\n"
                <<"Enter your choice: ";
            cin>>choice;
            string s;
            if(choice == 1){
                cout<<"Enter text to be decrypted: ";
                getline(cin,s);
                s = DecryptMessage(s);
            }
            else if(choice == 2){
                s = ReadFromFile();
            }
            else{
                cout<<"\nChoose a valid option: \n";
                goto label_3_1;
            }
            cout<<"\nDecrypted Text is: "<<s<<"\n";
            label_3_2:
            DisplayOption();
            cin>>choice;
            if(choice == 1){
                Write_to_file(s);
            }
            else if(choice == 2){
                
            }
            else{
                cout<<"\nChoose a valid option: \n";
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
        s += (rand()%79+48);
    return s;
}
string EncryptMessage(string s){
    string encrypted_message;
    for(char &c: s){
        size_t position = alphabet.find(c);
        if(position != string::npos)
            encrypted_message += key.at(position);
        else
            encrypted_message += c;
    }
    return encrypted_message;
}
string DecryptMessage(string s){
    string decrypted_message;
    for(char c: s){
        size_t position = key.find(c);
        if(position != string::npos)
            decrypted_message += alphabet.at(position);
        else
            decrypted_message += c;
    }
    return decrypted_message;
}
void DisplayWelcome(){
    cout<<"\n*************************************************************Welcome to Password Manager"
        <<"*************************************************************\n"
        <<"\t\t\t\t\t\t\t     1.)Generate Random Password.\n"
        <<"\t\t\t\t\t\t\t     2.)Encrypt a message.\n"
        <<"\t\t\t\t\t\t\t     3.)Decrypt a message.\n"
        <<"\t\t\t\t\t\t\t     4.)Exit.\n"
        <<"\n\t\t\t\t\t\t\t    What would you like to do: ";
}
void DisplayOption(){
    cout<<"\n\t\t\t\t\t\t\t    What would you like to do: " 
        <<"1.)Save this Text(Encrypted).\n"
        <<"2.)Send this Text(Encrypted).\n"
        <<"Enter your choice: ";
}
void Write_to_file(string s){
    string web;
    cout<<"What's this text for? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,web);
    ofstream out_file{"./myfile.txt",ios::app};
    if(out_file){
        out_file << "\n\t\t\t" << web << "\t\t\t\t    --\t\t\t\t" << s;
        cout<<"\nThe text has been sucessfully written to file : myfile.txt\n";
    }
    else{
        cout<<"The file does not exist!\n";
    }
    out_file.close();
}
string ReadFromFile(){
    ifstream in_file;
    string filename;
    cout<<"Enter filename to be read from: ";
    cin >> filename;
    string str;
    in_file.open(filename);
    if(in_file){
        string line;
        while(getline(in_file,line))
            str += line + '\n';
    }
    in_file.close();
    return str;
}
