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

using namespace std;
bool validate(); 
bool game_over();
int countSetBits(unsigned int n);
void lock_file(); 
void unlock(); 
bool is_locked(); 

int board[4];
ofstream game; 
ifstream infile;
fstream lock;


	
int main(){
	lock.open("lock.txt");
	lock << "lock:" << endl; 
	lock.close(); 
	string locked; 
	srand(time(NULL)); 

    board[0]= rand() % 14 + 1;
	board[1]= rand() % 14 + 1;
	board[2]= rand() % 14 + 1;
	board[3]= rand() % 14 + 1;
	int cont = 0;
	while(cont ==0){
		if(!is_locked()){
			lock_file(); 
			game.open ("gameFile.txt");
			game << "<0>" ;
			//generate numbers
			for (int i = 0; i < 4; ++i){
				game << "<"<<board[i]<<">"; 
			}
			game.close();
			cont = 1;
			unlock(); 
		}
	}
	cout << "Game Start! First move is player 0" << endl;
	validate();
	return 0; 
}

bool validate(){
int cont = 0, num; 
string line, state, tokens[5], delim = ">";
	while(!game_over()){
		cont = 0; 
		//cout << "Checking for valid move" << endl;
		while(cont == 0){ 
			if(!is_locked()){
				lock_file(); 
				//cout << "stuck in loop" << endl;
				infile.open("gameFile.txt");
				getline(infile, line);
				infile.close();
				cont = 1; 
				unlock(); 
			}
		}
			
			//cout << line << endl;
			int start = 1;
			for(int i = 0; i < 5; ++i){
				tokens[i] = line.substr(start, line.find(delim)-1);
				
				//start+= line.find(delim);
				line.replace(start, line.find(delim)+1,""); 
				
			}
			
			state = tokens[0];
			// if the move operation is valid
			if(!state.compare("0T")){
			//0 made a move and needs to validate
				for(int i = 1; i < 5; ++i){	
				//convert token to int
				sscanf(tokens[i].c_str(), "%d", &num);
					if(num < 0 || num > 14){
						cout << "An illegal move was made by player 0. Player F wins" << endl;
						cout <<"num was " << num << endl;
						return false; 
						}
					else{
						tokens[0] = "F";
						//write back to file with new state
						cont = 0;
						while(cont ==0){
							if(!is_locked()){
								lock_file(); 
								game.open("gameFile.txt");
								for(int i = 0; i < 5; ++i){
									game << "<" << tokens[i] << ">"; 
									cont = 1;
									unlock(); 
								}
							game.close();
				
		
							}
			
						}
					}
				 
				}
			validate();
			}
			if(!state.compare("FT")){
			//F made a move and needs to validate
			cout << "we got to FT" << endl;
				for(int i = 1; i < 5; ++i){
				//convert token to int
				sscanf(tokens[i].c_str(), "%d", &num);
					cout << num << endl; 
					if(num < 1 || num > 14){
						cout << "An illegal move was made by player F. Player 0 wins" << endl;
						cout <<"num was " << num << endl;
						return false;
						}
					else {
						tokens[0] = "0";
						//write back to file with new state
						cont = 0;
						while(cont ==0){
							if(!is_locked()){
								lock_file(); 
								game.open("gameFile.txt");
								for(int i = 0; i < 5; ++i){
									game << "<" << tokens[i] << ">"; 
									cont = 1;
									unlock(); 
								}
							game.close();
				
		
							}
			
						}
						
					}
				 
				}
			validate();
			}
			//write game with new state to file if there were no invalid moves
			cont = 0;
			while (cont ==0){ 
				if(!is_locked()){
					lock_file(); 
					game.open("gameFile.txt");
					for(int i = 0; i < 5; ++i){
						//cout << tokens[i] << endl; 
						game << "<" << tokens[i] << ">"; 
					}
					game.close();
					cont = 1;
					unlock(); 
				}
			}
		
	}//end big while loop
	return true;
}

bool game_over(){
	string tokens[5], line = "linetext", locked, delim = ">"; 
	int count, nums[4], start = 1, cont = 0;;
	while(cont ==0){
		if(!is_locked()){
				lock_file();
				infile.open("gameFile.txt");  
				getline(infile, line);
				//cout << line << endl;
				infile.close(); 
				cont = 1;
				unlock(); 
		}
	}
	//cout <<line << endl; 
	//get values from file and put them in an int array
	for(int i = 0; i < 5; ++i){
		 
		tokens[i] = line.substr(start, line.find(delim)-1);
		//cout << tokens[i] << endl;
		line.replace(start, line.find(delim)+1,""); 
		if(i > 0)
			sscanf(tokens[i].c_str(), "%d", &nums[i-1]);
	}
	
	//check to see if all bits are set or not set
	for(int i = 0; i < 4; ++i){
		count += countSetBits(nums[i]); 
		//cout << nums[i] << ": " << countSetBits(nums[i]) << endl;
	}
	
	//if count is 0 or 9 then the game is won
	if(count == 0){
		tokens[0] = "0W";
	}
	if(count == 9){
		tokens[0] = "FW";
	}
	if(count == 0 || count == 9){
		//write back to file with who won
		cont = 0;
		while(cont ==0){
			if(!is_locked()){
				lock_file(); 
				game.open("gameFile.txt");
				for(int i = 0; i < 5; ++i){
					game << "<" << tokens[i] << ">"; 
					cont = 1;
					unlock(); 
				}
				game.close();
				
				return true; 
			}
			
		}
	}

return false; 
}

/* Function to get num of set bits in binary
   representation of passed binary no. */
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
