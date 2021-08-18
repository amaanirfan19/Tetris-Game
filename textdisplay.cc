#include "textdisplay.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
using namespace std;

TextDisplay::TextDisplay(){}

void TextDisplay::displayText(Grid & playerOne, Grid &playerTwo) {
	//cout << "p1 level: " << playerOne.getLevel() << endl;
	playerOne.getType();
	//cout << "p1 level setted: " <<playerOne.getLevel() << endl;;
    int turn = 0;
    vector<string> I =  {{"    "}, {"IIII"}};
    vector<string> S =  {{" SS "}, {"SS  "}};
    vector<string> Z =  {{"ZZ  "}, {" ZZ "}};
    vector<string> O =  {{"OO  "}, {"OO  "}};
    vector<string> T =  {{"TTT "}, {" T  "}};
    vector<string> L =  {{"  L "}, {"LLL "}};
    vector<string> J =  {{"J   "}, {"JJJ "}};

    cout << "Level:" << setfill(' ') << setw(5);
    cout << playerOne.getLevel();
    cout << "       " ;
    cout << "Level:" << setfill(' ') << setw(5);
    cout << playerTwo.getLevel() << endl;
    cout << "Score:" << setfill(' ') << setw(5);
    cout << playerOne.getScore();
    cout << "       " ;
    cout << "Score:" << setfill(' ') << setw(5);
    cout << playerTwo.getScore() << endl;
    if (turn == 0){
         cout << "Turn: PLAYER 1" << endl;
    } else {
         cout << "Turn: PLAYER 2" << endl;
    }
    
    cout << "-----------       -----------" << endl;
    
    int rows = 18;
    int cols = 11;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
             bool filled = playerOne.getCells()[i][j].isFilled();
             
             if (filled){
                  char type = playerOne.getCells()[i][j].getType();
                  //cout << type;
				  if (type == 'I') {
					  cout << "\033[1;31mI\033[0m\n";
				  } else if (type == 'J') {
					  cout << "\033[1;32mJ\031[0m\n";
				  } else if (type == 'O') {
					  cout << "\033[1;36mO\033[0m\n";
				  } else if (type == 'L') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'Z') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'S') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'T') {
					  cout << "\033[1;35mT\033[0m\n";
				  }
             } else {cout << " ";}
        }
        cout << "       ";
          for (int j = 0; j < cols; j++) {
             bool filled = playerTwo.getCells()[i][j].isFilled();
             
             if (filled){
                  char type = playerTwo.getCells()[i][j].getType();
                  if (type == 'I') {
					  cout << "\033[1;31mI\033[0m\n";
				  } else if (type == 'J') {
					  cout << "\033[1;32mJ\031[0m\n";
				  } else if (type == 'O') {
					  cout << "\033[1;36mO\033[0m\n";
				  } else if (type == 'L') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'Z') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'S') {
					  cout << "\033[1;35mT\033[0m\n";
				  } else if (type == 'T') {
					  cout << "\033[1;35mT\033[0m\n";
				  }
             }  else {cout << " ";}
        }
        cout << endl;
    }

    char nbOne = playerOne.getNew_b();
    char nbTwo = playerTwo.getNew_b();
    
    cout << "-----------       -----------" << endl;
    cout << "Next:             Next:      " << endl;
    
    vector<string> blockOne;
    vector<string> blockTwo;
    if (nbOne == 'I') {
         blockOne = I;
    } else if (nbOne == 'S') {
         blockOne = S;
    } else if (nbOne == 'J') {
         blockOne = J;
    } else if (nbOne == 'O') {
         blockOne = O;
    } else if (nbOne == 'T') {
         blockOne = T;
    } else if (nbOne == 'L') {
         blockOne = L;
    } else if (nbOne == 'Z') {
         blockOne = Z;
    } 

    if (nbTwo == 'I') {
         blockTwo = I;
    } else if (nbTwo == 'S') {
         blockTwo = S;
    } else if (nbTwo == 'J') {
         blockTwo = J;
    } else if (nbTwo == 'O') {
         blockTwo = O;
    } else if (nbTwo == 'T') {
         blockTwo = T;
    } else if (nbTwo == 'L') {
         blockTwo = L;
    } else if (nbTwo == 'Z') {
         blockTwo = Z;
    } 

    for (int i = 0; i < 2; ++i){
        cout <<  blockOne[i] << "              " ;
        cout << blockTwo[i];
        cout << endl;
    }    
}