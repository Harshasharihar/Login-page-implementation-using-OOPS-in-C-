#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#define NUL 0
using namespace std;

class Login{
    private:
            struct data{
                char name[100];
                char pwd[100];
                struct data *next;
            }*start;

    public:
            Login();
            void registration(char a[],char b[]);
            void signin(char a[], char b[]);
};

Login :: Login(){
    start = NUL;
}

void Login :: registration(char user_id[],char psswd[]){
    struct data *temp,*node;
    if(start == NUL){
        temp = new struct data;
        if(temp == NUL){
            cout<<"User Registration Failed.. Try Again..!!\n\n\n\n";
        
        }
        strcpy(temp->name,user_id);
        strcpy(temp->pwd,psswd);
        temp->next = NUL;
        start = temp;
        cout<<"Registration Successfull..!!\n\n\n\n";
    }
    else{
        node = new struct data;
        temp = start;
        if(node == NUL){
            cout<<"User Registration Failed.. Try Again..!!\n\n\n\n";
    
        }
        while(temp->next != NUL){
            temp = temp->next;
        }
        temp->next = node;
        strcpy(node->name,user_id);
        strcpy(node->pwd,psswd);
        node->next = NUL;
    }
}

void Login :: signin(char user_id[],char psswd[]){
    struct data *temp;
    temp = start;
    while(temp!=NUL){
        if(strcmp(user_id,temp->name) == 0){
            if(strcmp(psswd,temp->pwd) == 0){
                cout<<"Login Successfull..!!\n\n\n\n";   
            }
            else{
                cout<<"Incorrect password.. Please try Again...\n";
            }
        }
        else{
            cout<<"Incorrect Username Or Password..!!\n\n\n\n";
            break;
        }
        temp=temp->next;            

    }
}

int main(){
    Login u;
    int choice;
    char user_name[100],password[100];
    while(1){
        cout<<"Enter 1 to Register....\n";
        cout<<"Enter 2 to Login.......\n";
        cout<<"Enter 3 to Exit........\n";
        cin>>choice;

        switch(choice){
            case 1: cout<<"Welcome to the Registration Portal..!!\n\n\n\n";
                    cout<<"Username :  \n";
                    cin>>user_name;
                    cout<<"Password :  \n";
                    cin>>password;
                    u.registration(user_name,password);  
                    break;
            case 2: cout<<"Welcome to the Login Portal..!!\n\n\n\n";
                    cout<<"Username :  \n";
                    cin>>user_name;
                    cout<<"Password :  \n";
                    cin>>password;
                    u.signin(user_name,password);
                    break;
            case 3: cout<<"Exiting Now...\n";
                    exit(0);
            default:cout<<"Server Down !! ... Try Again\n\n\n\n";
        }
    }
}