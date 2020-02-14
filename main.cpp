#include<iostream>
#include"functions.h"
#include <ostream>
using namespace std;



//  int board[] = {1,2,3,   10,11,12,   19,20,21,
//                 4,5,6,   13,14,15,   22,23,24,
//                 7,8,9,   16,17,18,   25,26,27};
char boardchar[] = {'a','b','d', 
                    'd','e','f',   
                    'g','h','i',  

                                'j','k','l',
                                'm','n','o',   
                                'p','q','r',

                                            's','t','u',    
                                            'v','w','x',   
                                            'y','z','$'};
char boardchar2[27];



int main()
{
    greetAndInstruct();
    while (true){
    displayBoard(boardchar);
    int input;
    cout<<"Enter a number: "<<endl;
    cin >>input;
    if (checkIfLegal(input,boardchar)){
        boardchar[input-1]='X';
        ComputerMove(boardchar);

    }
    if (ChecWinner(boardchar)){
        displayBoard(boardchar);
        exit(0);
    }
    }
    }
    


       
