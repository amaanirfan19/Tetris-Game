#include "controller.h"
#include "block.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

Controller::Controller(int level, string fileOne, string fileTwo): level{level} {
    playerOne.setFile(fileOne);
    playerTwo.setFile(fileTwo);
}

void Controller::restart() {
    //cout << "Player 1's score: " << Grid1.getScore() << endl;
    //cout << "Player 2's score: " << Grid2.getScore() << endl;
    // wip; [compare players score to determine winner]
}

void Controller::reset() {
    // wip; [reset all parameters to grid to 0 or ""]
}

void Controller::end() {
    cout << "Player 1's score: " << playerOne.getScore() << endl;
    cout << "Player 2's score: " << playerTwo.getScore() << endl;
      if (playerOne.getScore() > playerTwo.getScore()) {
        cout << "Player 1 Wins!";
    } else if (playerOne.getScore() < playerTwo.getScore()){
        cout << "Player 2 Wins!";
    } else if (playerOne.getScore() == playerTwo.getScore()) {
        cout << "Player 1 and Player 2 are Tied!";
    }
    cout << "Congratulations!" << endl;
}

void Controller::playGame() {
    string cmd;
    string aux; 
    ifstream fs;
    bool readFile = false;  // flag to read sequence file or not

	bool p1Turn = false;
	//cout << "running" << endl;
	playerOne.displayNextBlock();
	//cout << "running" << endl;
	playerTwo.displayNextBlock();
	//cout << "print newb below:" << endl;
	//cout << playerOne.getNew_b() << endl;
    int start_key = 0;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓ WELCOME  TO  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓ BIQUADRIS ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓ INPUT ANY KEY TO START PLAYING ▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓" << endl;
    while (1) {
		if (playerOne.getGame_over() || playerTwo.getGame_over()) {
			end();
			break;
		}
        if (cin.eof()) {
			end();
            break;
        }

        if (readFile) {
            if (!(fs >> cmd)) {
                if (readFile) readFile = false;
                if (!(cin >> cmd)){
                   break;
                }
            } 
            
            if (fs >> cmd) {
                cout << cmd << endl;
            }
        } else if (!(cin >> cmd)) {
            break;
        }

        istringstream is{cmd};
        is >> aux;

        if (aux.substr(0, 3) == "lef") { 
			if (p1Turn) {
				//playerOne.displayNextBlock();
				//playerTwo.displayNextBlock();
				playerOne.checkLeft();
			}  else {
				playerTwo.checkLeft();
			} // left
        } else if (aux.substr(0, 2) == "ri") { // right
			if (p1Turn) {
				//playerOne.displayNextBlock();
				//playerTwo.displayNextBlock();
				playerOne.checkRight();
				
			}  else {
				playerTwo.checkRight();
			}
        } else if (aux.substr(0, 2) == "do") {  // down
		if (p1Turn) {
				//playerOne.displayNextBlock();
				//playerTwo.displayNextBlock();
				playerOne.checkDown();
				
			}    else {
				playerTwo.checkDown();
			}
        }  else if (aux.substr(0,2) == "cl") { 
            if (p1Turn) {
                playerOne.checkClockwise();    
            }    else {
                playerTwo.checkClockwise();
            }

        } else if (aux.substr(0,2) == "co") { 
            if (p1Turn) {
                for (int i = 1; i <= 3; ++i) {
                playerOne.checkClockwise(); 
                }   
            }    else {
                for (int i = 1; i <= 3; ++i) {
                playerTwo.checkClockwise(); 
                } 
            }

        } else if (aux.substr(0, 2) == "dr") { 
			if (p1Turn) {
				playerOne.checkDrop();
				playerOne.displayNextBlock();
			}   else {
				playerTwo.checkDrop();
				playerTwo.displayNextBlock();
			} // drop 

        } else if (aux.substr(0, 6) == "levelu") {   // levelup
        if (p1Turn) {
                playerOne.levelUp();
			}   else {
                playerTwo.levelUp();
			}
            
        } else if (aux.substr(0, 6) == "leveld") {  // leveldown
        if (p1Turn) {
                playerOne.levelDown();
			}   else {
                playerTwo.levelDown();
			}

        } else if (aux.substr(0,1)  == "n"){    //norandom file
            
        } else if (aux.substr(0,2)  == "ra"){ //set back to random

        } else if (aux.substr(0, 2) == "se") { // sequence file
        
    
            string f;
            cin >> f;   // file name
            fs = ifstream{f};
            if (!readFile) readFile = true; 
        }  else if (aux == "I" || aux == "J" || aux == "L" ||
                   aux == "O" || aux == "Z" || aux == "S" ||
                   aux == "T") {
            // change block to aux 
        } else if (aux.substr(0, 2)  == "re") { // restart
            //restart();
        } else {
            if (start_key == 0) {
                start_key++;
                cout << "The Game begins..." << endl;
            } else {
                cout << "ERROR: Invalid Command!" << endl;
            }
            
        }

/*
        int rowsremoved = 0;
        if (p1Turn){
                for (int i = 0; i < 18; i++) {
                   bool full = true;
                     for (int j = 0; j < 11; j++) {
                         if (!playerOne.findcell(i,j).isFilled()){
                            full = false;
                            break;
                    } 
            }
            if (!full) {
                 
                continue;
                 }
            
            playerOne.deleteRow(i); // delete a row, move everything down
            playerOne.setScore(playerOne.getScore()+10);
            rowsremoved++;
            i = 0;
        }     
       } else {
               for (int i = 0; i < 18; i++) {
                   bool full = true;
                     for (int j = 0; j < 11; j++) {
                         if (!playerTwo.findcell(i,j).isFilled()){
                            full = false;
                            break;
                    }
            }
            if (!full) {
                 
                continue;
                 }
            
            playerTwo.deleteRow(i); // delete a row, move everything down
            rowsremoved++;
            playerTwo.setScore(playerTwo.getScore()+(playerTwo.getLevel() + rowsremoved*rowsremoved));
            
            i = 0;
        }            
    }
	*/
        // if (rowsremoved >= 2){
            // cout << "You have cleared 2+ rows!" << endl;
            // cout << "Choose a special move: Blind! Heavy! or Force!" << endl;
            
        //}
        
		//
		playerOne.removeRows();
		playerTwo.removeRows();
		//
        td.displayText(playerOne, playerTwo);

		if (p1Turn == true) {
			p1Turn = false;
		} else {
			p1Turn = true;
		}

        // check endgame on grid 
    }
    return;
}