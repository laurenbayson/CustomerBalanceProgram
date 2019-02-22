#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

struct PERSON{
  char Name[20];
  float Balance;
};

//counting the records
int counter(){
  int number = 0;
  string line;

  ifstream file("data.txt");
  while(getline(file, line))
    number++;

    file.close();
    return number;
}

void fillStruct (int N, PERSON P[]){
  string first,last,t;
  double num;
  ifstream file("data.txt");

  for(int i = 0; i<N; i++){
    file>>first>>last>>num;
    getline(file, t);
    string name = first + " " + last;
    strcpy(P[i].Name, name.c_str());
    P[i].Balance = num;
  }
  file.close();
}

void Display(int N, PERSON P[]){
  cout<<"   "<<"Name"<<"        "<<"Balance"<<endl;
  cout<<"----------------------------------"<<endl;
  for(int i=0; i<N;i++){
    cout<<"   "<<P[i].Name<<"   "<<P[i].Balance<<endl;
  }
}

void Richest(int N, PERSON P[]){
  int rich;
  double lo;

  for(int i=0; i<N; i++){
    if(P[i].Balance > lo){
      lo = P[i].Balance;
      rich = i;
    }
  }
  cout<<"Customer with highest balance: "<<P[rich].Name<<endl;
}

void Deposit( string CustName, int N, PERSON P[]){
  CustName.c_str();
  int i = N;
  float deposit;

  while (CustName != P[i].Name){
    i--;
  }

  cout<<P[i].Name<<", how much would you like to deposit: "<<endl;
  cin>>deposit;

  P[i].Balance += deposit;

  cout<<"Your new balance is: "<< P[i].Balance <<endl;
}

void NewCopy(string s, int N, PERSON P[]){
  ofstream file;
  file.open("data.txt");

  for(int i=0; i<N; i++){
    file<<P[i].Name<<" "<<P[i].Balance<<endl;
  }
  file.close();
}

int main(){
  string fullName;
  int N = counter();
  PERSON P[N];

  fillStruct(N,P);
  Display(N,P);
  Richest(N,P);

  cout<<"Enter your full name to deposit money: ";
  cin>>fullName;

  Deposit(fullName,N,P);
  NewCopy("data.txt",N,P);

  return 0;
}
