// Author : Yessica Gaona Morales
//
// Due Date : March 3, 2021
// Programming Assignment Number 3
// Spring 2021 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
// This program acts as a vending machine that sells candies, chips, gums,
// and cookies. The program contains two classes: one used to define a built
// in cash register, and the second defines the dispensers that hold and
// release the products. The program displays a menu that shows the products
// and how to select a particular product.

#include <iostream>
using namespace std;

class CashRegister{
private:
  int cashOnHand;
public:
  CashRegister();
  CashRegister(int amount);
  int getCash();
  void addCash(int amount);
};

CashRegister::CashRegister(){ cashOnHand = 500; }
CashRegister::CashRegister(int amount){ cashOnHand = amount; }
int CashRegister::getCash(){ return cashOnHand; }
void CashRegister::addCash(int amount){ cashOnHand += amount; }

class DispenserType{
private:
  int quantity;
  int price;
public:
  DispenserType(int cost);
  int getQuantity();
  int getPrice();
  void release();
};
DispenserType::DispenserType(int cost){
  quantity = 3;
  price = cost;
}
int DispenserType::getQuantity(){ return quantity; }
int DispenserType::getPrice(){ return price; }
void DispenserType::release(){ quantity--; }

int main()
{
    CashRegister regi;
    DispenserType candy(35);
    DispenserType chip(500);
    DispenserType gum(200);
    DispenserType cookie(1000);

    cout << "*** Welcome to Yessica Gaona's Vending Machine ***\n\n";

    int input;
    int money;
    do{
      cout << "Select one of the following\n\n\t";
      cout << "1 for Candy\n\t";
      cout << "2 for Chips\n\t";
      cout << "3 for Gum\n\t";
      cout << "4 for Cookie\n\t";
      cout << "9 to exit\n";


      try{
        cin >> input;
        if(cin.fail())
            throw input;
        switch(input){
          case 1:
            if (candy.getQuantity() == 0){
              cout << "Sorry this item is sold out.\n";
              break;
            }
            else{
              cout << "Please deposit " << candy.getPrice() << " yen.\n";
              cin >> money;
              if (money < candy.getPrice()){
                  cout << "Please deposit another " << candy.getPrice()-money << " yen\n";
                  cin >> input;
                  if(cin.fail())
                      throw input;
                  if (money+input < candy.getPrice()){
                    cout << "The amount is not enough. Collect what you have deposited.\n";
                    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
                    break;
                  }
                }
              }
              cout << "Collect your item at the bottom and enjoy.\n";
              cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
              candy.release();
              regi.addCash(candy.getPrice());
              break;

          case 2:
            if (chip.getQuantity() == 0){
              cout << "Sorry this item is sold out.\n";
              break;
            }
              else{
                cout << "Please deposit " << chip.getPrice() << " yen.\n";
                cin >> money;
                if (money < chip.getPrice()){
                  cout << "Please deposit another " << chip.getPrice()-money << " yen\n";
                  cin >> input;
                  if(cin.fail())
                    throw input;
                  if (money+input < chip.getPrice()){
                    cout << "The amount is not enough. Collect what you have deposited.\n";
                    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
                    break;
                  }
                }
              }
              cout << "Collect your item at the bottom and enjoy.\n";
              cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
              chip.release();
              regi.addCash(chip.getPrice());
              break;

          case 3:
            if (gum.getQuantity() == 0){
              cout << "Sorry this item is sold out.\n";
              break;
            }
            else{
              cout << "Please deposit " << gum.getPrice() << " yen.\n";
              cin >> money;
              if (money < gum.getPrice()){
                cout << "Please deposit another " << gum.getPrice()-money << " yen\n";
                cin >> input;
                if(cin.fail())
                  throw input;
                if (money+input < gum.getPrice()){
                  cout << "The amount is not enough. Collect what you have deposited.\n";
                  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
                  break;
                }
              }
            }
            cout << "Collect your item at the bottom and enjoy.\n";
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
            gum.release();
            regi.addCash(gum.getPrice());
            break;

          case 4:
            if (cookie.getQuantity() == 0){
              cout << "Sorry this item is sold out.\n";
              break;
            }
            else{
              cout << "Please deposit " << cookie.getPrice() << " yen.\n";
              cin >> money;
              if (money < cookie.getPrice()){
                cout << "Please deposit another " << cookie.getPrice()-money << " yen\n";
                cin >> input;
                if(cin.fail())
                  throw input;
                if (money+input < cookie.getPrice()){
                  cout << "The amount is not enough. Collect what you have deposited.\n";
                  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
                  break;
                }
              }
            }
            cout << "Collect your item at the bottom and enjoy.\n";
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
            cookie.release();
            regi.addCash(cookie.getPrice());
            break;

          case 9:
            cout << "*** Thank you for using Yessica Gaona's Vending Machine ***";
            return 0;
          default:
            cout << "Invalid Selection.\n";
        }
      }
      catch (char input){
        cout << "Invalid Selection.\n";
        cin.clear();
      }
    }while(input != 9 );
