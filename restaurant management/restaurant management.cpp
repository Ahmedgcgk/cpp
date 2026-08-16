#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
using string = std::string;

struct fooditem{
    string Name;
    double price;    
};
fooditem Starter[]= {{"Soup", 1.5},{"Nuggets", 2.0}, {"Fish", 3.5}, {"Cracker", 1}};
fooditem Main[] = {{"Biryani", 3.0}, {"Pulao", 3.0}, {"Burger", 4.0}, {"Pizza", 5.0}, {"Karahi", 2.0}, {"Shawarma", 2.0}};
fooditem Drinks[]= {{"Pepsi", 1.0},{"Seven Up", 1.0}, {"Mirinda", 1.0}};         
bool corr;

void DisplayOrders(int choice1, int choice2, int Servings);
void TakeOrder(string choice1, double &totalPrice, string &FoodName);
bool isInteger(const std::string& str);
bool check(std::string a);
bool CardCheck(string num,double totalPrice);
void PrintList(int paychoice, double total, string foodname, string Name, int seatNo);

int main() { 
    string Name;
    int seatNo;
    string choice;
    string choice2;
    int servings;
    int payChoice;
    int payment;
    double TotalPrice = 0;
    string FoodName = "";
    int num;
    
    
    do{
        std::cout << "Welcome To The Restaurant\n";
        std::cout << "Please Enter Your Name> ";
        getline(std::cin >> std::ws, Name);
        std::cout << "Enter Your Seat Number> ";
        std::cin >> seatNo;
        std::cout << "What would you like to order?\n1.Starters\n2.Main\n3.Drinks\n> ";
        
        do{
           std::cin >> choice;
           corr = isInteger(choice);
           if(corr){
            num = std::stoi(choice);
           }
        }while(!corr || num > 3 || num < 1);

        if(choice == "1"){
            for (fooditem dish : Starter){
                std::cout << dish.Name << "---" << dish.price<< "\n";
            }
            TakeOrder(choice,TotalPrice,FoodName);
            
        }else if(choice == "2"){
            for (fooditem dish : Main){
                std::cout << dish.Name << "---" << dish.price<< "\n";
            }
            TakeOrder(choice,TotalPrice,FoodName);
        }else if(choice == "3"){
            for (fooditem dish : Drinks){
                std::cout << dish.Name << "---" << dish.price<< "\n";
            }
            TakeOrder(choice,TotalPrice,FoodName);
        }
        std::cout << "Total Price> " << TotalPrice<< "\n";
        std::cout << "Pay by cash or credit?\n1.Cash\n2.Credit> ";
        std::cin >> payChoice;
        PrintList(payChoice,TotalPrice,FoodName,Name,seatNo);


    
    }while (1);

    return 0;
}

void DisplayOrders(int choice1, int choice2, int Servings){
    if(choice1 == 1){
            std::cout << Starter[choice2-1].Name<< "---" << Starter[choice2-1].price * Servings << "\n";
    
    }else if(choice1 == 2){
        std::cout << Main[choice2-1].Name<< "---" << Main[choice2-1].price * Servings<< "\n";

    }else if(choice1 == 3){
        std::cout << Drinks[choice2-1].Name<< "---" << Drinks[choice2-1].price * Servings<< "\n";           
    }
}

void TakeOrder(string choice1, double &totalPrice, string &FoodName){
    string choice2;
    int servings;
    int num2;
    int size;
    std::cout << "What would you like to order? (Type Num) > ";
    do{

        if (choice1 == "1"){
            size = sizeof(Starter)/sizeof(Starter[0]);
        }else if(choice1 == "2"){
            size = sizeof(Main)/sizeof(Main[0]);
        }else if(choice1 == "3"){
            size = sizeof(Drinks)/sizeof(Drinks[0]);
        }
        
        std::cin >> choice2;
        corr = isInteger(choice2);
        if(corr){
            num2 = std::stoi(choice2);
        }
        

    }while(!corr || size < num2 || num2 < 1);
    std::cout << "How many servings? > ";
    std::cin >> servings;
    
    if(choice1 == "1"){
        FoodName = Starter[num2-1].Name;
        totalPrice = Starter[num2-1].price * servings;
    
    }else if(choice1 == "2"){
        FoodName = Main[num2-1].Name;
        totalPrice = Main[num2-1].price * servings;

    }else if(choice1 == "3"){
        FoodName = Drinks[num2-1].Name;
        totalPrice = Drinks[num2-1].price * servings;           
    }
}
void PrintList(int paychoice, double total, string foodname, string Name, int seatNo){
    string Cnum;
    int payment;
    if(paychoice == 1){
        std::cout << "Enter Money to pay> ";
        std::cin >> payment;
        std::cout << "Your ORDER\n";
        std::cout << Name << " Seat No. " << seatNo << "\n";
        std::cout << foodname << " --- "<< total << "\n";
        std::cout << "Balance> " << total - payment;
    }else if(paychoice == 2){
        bool paychecker;
        do{
            std::cout << "Enter credit num> ";
            std::cin >> Cnum;
            paychecker = CardCheck(Cnum,total);
        }while(!paychecker);
    }   
}
bool CardCheck(string num,double totalPrice){
    std::fstream myfile;
    myfile.open("cards.txt", std::ios::in);
    if( myfile.is_open()) {
        string line;
        while(getline(myfile,line)){
            string number = line.substr(0,14);
            if(number == num){
                string Pin;
                std::cout << "Enter pin> ";
                std::cin >> Pin;
                string chPin = line.substr(15,4);
                if (Pin == chPin){
                    string bal = line.substr(20);
                    int bal2 = std::stoi(bal);
                    if(bal2 >= totalPrice){
                        std::cout << "Paid!\n";
                        return 1;
                    }else{
                        std::cout << "insuffcient funds\n";
                        return 0;
                    }

                }
            }
        }
        std::cout << "Wrong Number or Pin\n";
        return 0;
    }
    
}
bool isInteger(const string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-') {
        if (str.length() == 1) return false; 
        start = 1;
    }

    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool check(std::string a){
    if (!isInteger(a)) {
        return false;
    }
    
    int num = std::stoi(a);
    if (num >= 1 && num <= 3) {
        return true;  
    }

    return false;
}