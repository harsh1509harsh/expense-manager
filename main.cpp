#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Account.h"
int main(){
    std::cout<<"Welcome to expense-manager"<<std::endl;
    bool running = true;
    bool isLogged = false;
    std::fstream logFile;
    logFile.open("loginData.txt");
    if(!logFile.is_open()){
        std::cout<<"Error opening Log File"<<std::endl;
        return -1;
    }
    std::vector<Account> accounts;
    std::string line;
    while(std::getline(logFile, line)){
        accounts.push_back(line);
    }
    Account currUser;
    while(running){
        std::cout<<"Select a option : \n1. Add Account.\n2.Log in.\n3.Log out.\n4.Add expense.\n5.Show expense."<<std::endl;
        int ans; std::cin>>ans;
        if(ans == 3){
            if(isLogged) isLogged = false;
            continue;
        }
        if(ans == 1){
            std::cout<<"Please Tell the Account Name : "<<std::endl;
            std::string username; cin>>username;
            for(Account& account : accounts) if(account.name == username){
                std::cout<<"Provided Username already exists!"<<std::endl;
                continue;
            }
            logFile<<username<<"\n";
            continue;
        }
        if(ans == 2){
            std::cout<<"Please Enter the Username : "<<std::endl;
            std::string username; cin>>username;
            bool isFound = false
            for(Account& account : accounts) if(account.name == username){
                isFound = true;
                isLogged = true;
                currUser = account;
            }
            if(!isFound){
                std::cout<<"Given Username doesn't exists"<<std::endl;
                continue;
            }
        }
        //now here we are logged in.
        if(ans == 4){
            std::string category;
            std::cout<<"Enter the category of expense : "<<std::endl; std::cin>>category;
            int amount; std::cout<<"Enter the Amount : "<<std::endl; std::cin>>amount;
            currUser.addExpense(category, amount);
        }
        if(ans == 5){
            currUser.show();
        }
        else {
            std::cout<<"Incorrect Option Selected"<<std::endl;
        }
    }
    return 0;
}
