/* 	Eli Allen 
	eeallen1@go.olemiss.edu 
	CSCI 390 
	assignment3
	"In keeping with the Honor Code policies of the University of Mississippi, the School of Engineering, and the Department of Computer and Information Science, I 	affirm that I have neither given nor received inappropriate assistance on this programming assignment." 
	University object has an array of students and has the functions to calculate the average age of students and to print all names 
 */
#include <stdlib.h>     
#include <time.h>  
#include <string>     
#include <iostream>
#include <fstream>
#include <stdlib.h>     
#include <time.h>       
using namespace std; 
string get_state();
void play();
void choice();
int countSetBits(unsigned int n);
void lock_file(); 
void unlock(); 
bool is_locked(); 



ofstream game;
ifstream infile;
fstream lock; 
int board[4];
bool done;
int main(){
	string tokens[5], line = "empty", delim = ">", state, locked; 
	int count, start = 1;
	while(!line.compare("empty")){
		if(!is_locked()){
		//if(!infile.is_open() && !game.is_open()){
			lock_file(); 
			cout << "Initializing game for player 0" << endl; 
			infile.open("gameFile.txt");
			getline(infile, line);
			infile.close();  
			unlock(); 
		}
	}

	//populate board with numbers from file
	for(int i = 0; i < 5; ++i){
		tokens[i] = line.substr(start, line.find(delim)-1);
		line.replace(start, line.find(delim)+1,""); 
		if(i > 0)
			sscanf(tokens[i].c_str(), "%d", &board[i-1]);
			
	}
	play(); 
	return 0; 
}



void play(){
	while((get_state().compare("0W")) || (get_state().compare("FW"))){
	//cout << "stuck in loop" << endl;
	if(!(get_state()).compare("0")){
		cout << "player 0 begin turn" << endl;
		choice();
	
	
	}
	
	cout << "Waiting for playerF to move" << endl; 
	/*else if(!(get_state()).compare("F")){
	choice();
	
	
	
	}*/
	}
	cout << "Game over!" << endl;
}

string get_state(){
	string state, locked;
	int cont = 0; 
	while(cont == 0){
		if(!is_locked()){
		//if(!infile.is_open() ){
			lock_file(); 
			infile.open("gameFile.txt");
			getline(infile, state); 
			infile.close();
			state = state.substr(1, state.find(">")-1);
			cont = 1; 
			unlock(); 
		}
	}
	return state;
}

void choice(){
	int num = 0, mask = 0xF, cont = 0; 
	string move, state, locked; 
	//game.open("gameFile.txt");
	cout << "Would you like to:\n1) see the bits on a line\n2) make a move" << endl;
	cin >> num; 
	if(num == 1){
		//do stuff for seeing bits
		cout<<"which row would you like to see (1-4)?" << endl;
		cin >> num; 
		if(num > 0 && num < 5){
		cout << "Row " << num << " has " << countSetBits(board[num-1]) << " bits set. " << endl;
		choice(); 
		}
		else{
			cout << "That row does not exits - start over" << endl;
			choice();
			}
	}
else if(num == 2){
		//do stuff for make a move
		cout << "Which row would you like to manipulate?" << endl;
		cin >> num; 
		if(num < 5 && num > 0){
			cout << "Your choices for a move are\n1) Right shift (>>)\n2) Left shift (<<)\n3) Not(~)\n4) No move(.)\nPlease enter >>, <<, or ~ for your choice or . for no move" << endl; 
			cin >> move; 
			if(!(move.compare(">>"))){
				//right shift
				board[num-1] >>= 1; 
				cont = 0; 
				while(cont == 0){
					if(!is_locked()){
						if(!get_state().compare("0")){	
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<0T>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close();
							
						}
						else if(!get_state().compare("F")){
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<FT>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close(); 
						}
						else
							cout <<"someting went horribly wrong and there's probably no chance I'll fix it" << endl;
						
						cont = 1;
					}
				}
			}
			else if(!(move.compare("<<"))){
				//left shift
				board[num-1] <<= 1;
				board[num-1] &= mask; 
				cont = 0; 
				while(cont == 0){
					if(!is_locked()){
						if(!get_state().compare("0")){	
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<0T>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close();
							
						}
						else if(!get_state().compare("F")){
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<FT>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close(); 
						}
						else
							cout <<"someting went horribly wrong and there's probably no chance I'll fix it" << endl;
						
						cont = 1;
					}
				}
			}
			else if(!(move.compare("~"))){
				//not
				board[num-1] = ~board[num-1];
				cont = 0; 
				while(cont == 0){
					if(!is_locked()){
						if(!get_state().compare("0")){	
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<0T>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close();
							
						}
						else if(!get_state().compare("F")){
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<FT>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close(); 
						}
						else
							cout <<"someting went horribly wrong and there's probably no chance I'll fix it" << endl;
						
						cont = 1;
					}
				}
			}
			else if(!(move.compare("."))){
				//no move 
				cont = 0; 
				while(cont == 0){
					if(!is_locked()){
						if(!get_state().compare("0")){	
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<0T>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close();
							
						}
						else if(!get_state().compare("F")){
							lock_file(); 
							game.open("gameFile.txt"); 
							game << "<FT>" << "<"<< board[0] << ">"<< "<"<< board[1] << ">"<< "<"<< board[2] << ">"<< "<"<< board[3] << ">";
							unlock(); 
							game.close(); 
						}
						else
							cout <<"someting went horribly wrong and there's probably no chance I'll fix it" << endl;
						
						cont = 1;
					}
				}
			}
			else{
				cout << "That isn't a valid move - start over" << endl;
				//choice(); 
				}
			}
		else{
			cout << "That row does not exist - start over" << endl;
			//choice(); 
		}	
	}
	else{
		cout << "That choice is invalid, try again" << endl;
		//choice(); 
		}

		cout << "Waiting for validation and enemy move.." << endl;
		play();
}

int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

void lock_file(){

lock.open("lock.txt", fstream::app|fstream::out);
lock << "y";
lock.close();

}

void unlock(){
lock.open("lock.txt", fstream::out);
lock << "lock:"; 
lock.close(); 

}

bool is_locked(){
string locked; 
lock.open("lock.txt", fstream::app|fstream::in); 
getline(lock, locked); 
lock.close();
if(!(locked.compare("lock:")))
	return false; 
else 
	return true; 
}
