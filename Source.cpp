#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
using namespace std;

int delay = 1;    // This is the initial value for the delay in seconds between frames of animation
void wait(int wait_time);  // declaration of void function for wait which is used in animation, function is below

//In this Tic Tac Toe Program you can pick if X or if O go first in this game.
char XorO(int k) 
{

	{
	if(k==-1)
	{return 'X'; }
	if(k==0)
	{	return ' ';}
	if(k==1)
	{return 'O';}
	else
	{return 0;}
	}
}

void displayboard(int positionplayttt[9]) 
{
	wait(delay);     //This animations the screen and waits a declared amount of seconds.
	system("cls");   //This will clear the screen after each function call. 
	cout<<" "<< XorO(positionplayttt[0])<<" | "<<XorO(positionplayttt[1])<<" | "<<XorO(positionplayttt[2])<<endl;  //This is the first row printed out on the screen.
	cout<<"---+---+---"<<endl;                                                                                     //This will help print out the visual asci image of the tic tac toe board. 
	cout<< " "<<XorO(positionplayttt[3])<< " | "<<XorO(positionplayttt[4])<<" | "<<XorO(positionplayttt[5])<<endl; //This is the second row printed out on the screen.
	cout<< "---+---+---"<<endl;                                                                                    //This will help print out the visual asci image of the tic tac toe board on the screen. 
	cout<< " "<<XorO(positionplayttt[6])<<" | "<<XorO(positionplayttt[7])<< " | "<<XorO(positionplayttt[8])<<endl; //This is the third row printed out on the screen.
}

int declarefinalresult(int tttpositon[9])      //This function declars the result and checks for wins it is used in cout-ing the final position in the consule window. It is also used as conditions for the while loops in the program such as there is currently no win so far.
{
	// Check for 1st row winner ...
	if (( tttpositon[0] != 0) && ( tttpositon[1] != 0) && ( tttpositon[2] != 0))
	{
		if (( tttpositon[0] ==  tttpositon[1]) && ( tttpositon[0] ==  tttpositon[2]))
		{
			return  tttpositon[2];
		}
	}

	// Check for 2nd row winner ...
	if (( tttpositon[3] != 0) && ( tttpositon[4] != 0) && ( tttpositon[5] != 0))
	{
		if (( tttpositon[3] ==  tttpositon[4]) && ( tttpositon[3] ==  tttpositon[5]))
		{
			return  tttpositon[5];
		}
	}

	// Check for 3rd row winner ...
	if (( tttpositon[6] != 0) && ( tttpositon[7] != 0) && ( tttpositon[8] != 0))
	{
		if (( tttpositon[6] ==  tttpositon[7]) && ( tttpositon[6] ==  tttpositon[8]))
		{
			return  tttpositon[8];
		}
	}

	// Check for 1st column winner ...
	if (( tttpositon[0] != 0) && ( tttpositon[3] != 0) && ( tttpositon[6] != 0))
	{
		if (( tttpositon[0] ==  tttpositon[3]) && ( tttpositon[0] ==  tttpositon[6]))															
		{
			return  tttpositon[6];
		}
	}

	// Check for 2nd column winner ...
	if (( tttpositon[1] != 0) && ( tttpositon[4] != 0) && ( tttpositon[7] != 0))
	{
		if (( tttpositon[1] ==  tttpositon[4]) && ( tttpositon[1] ==  tttpositon[7]))
		{
			return  tttpositon[7];
		}
	}

	// Check for 3rd column winner ...
	if (( tttpositon[2] != 0) && ( tttpositon[5] != 0) && ( tttpositon[8] != 0))
	{
		if (( tttpositon[2] ==  tttpositon[5]) && ( tttpositon[2] ==  tttpositon[8]))
		{
			return  tttpositon[8];
		}
	}

	// Check for 1st diagonal winner ...
	if (( tttpositon[0] != 0) && ( tttpositon[4] != 0) && ( tttpositon[8] != 0))
	{
		if (( tttpositon[0] ==  tttpositon[4]) && ( tttpositon[0] ==  tttpositon[8]))
		{
			return  tttpositon[8];
		}
	}

	// Check for 2nd diagonal winner ...
	if (( tttpositon[2] != 0) && ( tttpositon[4] != 0) && ( tttpositon[6] != 0))
	{
		if (( tttpositon[2] ==  tttpositon[4]) && ( tttpositon[2] ==  tttpositon[6]))
		{
			return  tttpositon[6];
		}
	}
	return 0;
}


int enginecomputer(int XandOtable[9], int variable12) //This will calculate the correct move value for computer to play, and it will return the value calculated which will be used in the void function for the computers choice of move. 
{
	
	int champion = declarefinalresult(XandOtable);
	if (champion != 0) 
	{
		return variable12*champion;
	}
	int tryplacespace = -1;
	int table = -3;  
	int s;
	s=0;
	while (s < 9) 
	{
	
		if (XandOtable[s] == 0) 
		{
			XandOtable[s] = variable12;     
			int thenew = -enginecomputer(XandOtable, variable12*-1);
			if (thenew > table) 
			{   tryplacespace = s;
				
			table = thenew;
				
			}
			
			XandOtable[s] = 0;   
		}
	s++;}
	if (tryplacespace == -1) return 0;
	return table;
}

void enginecomputemove(int array1[9])      //This is the method for computing the computers move when it is the computers turn to play in the tic tac toe game. 
{   
	int nowtotal=-3;
	int stepup=-2;
	int tv;
	tv=0;
	while(tv<9)
	{
		{
		if (array1[tv] == 0)       //This loops for all possible moves of the game of tic tac toe and will play the best move in the current position. 
		{
			array1[tv] = 1;
			int foo = -enginecomputer(array1, -1);
			array1[tv] = 0;
			if (foo > nowtotal) 
			{
				nowtotal = foo;
				stepup = tv;
			}
		}
	} 

tv++;}
	array1[stepup] = 1; //This will be implemented when the while loop is complete and this best move will be played on the tic tac toe board. 
 
}

void humanplayerMove(int array2[9])   //This is the function where the human is going to enter a move into the program. 
{
	int playtime = 0;
	while (playtime == 0)    //This will loop for every move of the human and will break when the human enters a move. 
	{
		cout << endl << "Input move as an integer number from 0 to 8 with 0 at top left and 8 at bottom right: ";
		cin >> playtime;
		cout << endl;
		if (cin.fail())
		{
			cout << endl << "Invalid move, value is unacceptable or square is already taken - try again" << endl;
			displayboard(array2);
			playtime = 0;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if ((playtime < 9 && playtime >= 0) && (array2[playtime] == 0))
		{
			array2[playtime] = -1;
			break;
		}
		else
		{
			cout << endl << "Invalid move, value is unacceptable or square is already taken - try again" << endl;
			displayboard(array2);
			playtime = 0;
		}
	}
	return;    }


void wait(int wait_time)                     //This is the function which allows the program to animate the position in the game of Tic Tac Toe.
{
	long *start_time = new long;
	*start_time = time(0);

	while ((*start_time + wait_time) > time(0)) 
	{
	};

	delete start_time;
	return;
};





int main() 
{   
	int XOintegerbd[9] = { 0,0,0,0,0,0,0,0,0};    //This makes the beginning position all empty spaces.
	char playagainanswer = 'N';
	int playagain=0;
	while(playagain==0)
	{
	int XOintegerbd[9] = { 0,0,0,0,0,0,0,0,0};    //This makes the beginning position all empty spaces.
	cout << "Please enter the time delay for animation in seconds: ";
	cin >> delay;
	wait(delay);
	system("cls");
	cout << "In this game the player will play with 'X' and the computer will always play with 'O' " << endl << endl;
	cout << "Press '1' to play as player number one or instead press '2' and play as player number two: ";
	int value123 = 0;
	cin >> value123;             //This number deciedes if the player will go first or second. 
	cout << endl;
	int step;
	step=0;
	while ( step < 9 && declarefinalresult(XOintegerbd) == 0)   //This loops for all moves of the tic tac toe game if there is no win or draw in the current position. 
	{
		if ((step + value123) % 2 == 0)                        //This will let the engine move first if step+val divided by two has a remanider of 0 because 0+1 dived by two remanider, 
		{	enginecomputemove(XOintegerbd);                    //Is not going to be equal to zero so the human player will play first, however if the value123 is equal to '2', then 
		}                                                      //the mod of (0+2) is going to be zero so the logic of the if statement is true and so the computer will play first. 
		else 
		{
			displayboard(XOintegerbd);                        //This will display the current board position on the screen by calling the function displayboard(XOintegerbd);
			humanplayerMove(XOintegerbd);                     //This function calls the human move parameter and the human inputs a int number which is turned into a charcter from 
		}                                                     //the string on the Char array. 
	step++;
	}
	
		if(declarefinalresult(XOintegerbd)==0)                 //This will cout the result on the consule window if there is a final result based of the game logic of the program. 
		{
			displayboard(XOintegerbd);
			cout<<endl<<"Game was a draw, you are a worthy opponent ..."<<endl;     //The checks if the game was a draw.
		}
        
		if(declarefinalresult(XOintegerbd)==1)
		{
			displayboard(XOintegerbd);
			cout<<endl<<"I am sorry but you lose, maybe try again later ..."<<endl;  //This check if the computer has won the game.
		}
	
		if(declarefinalresult(XOintegerbd)==-1)
		{
			displayboard(XOintegerbd);
			cout<<endl<<"You win, this is impossible!  I will self destruct in 10 seconds ... .Yout must have cheated in the game!!"<< endl;  //This checks if the player has won the game which should never happen because the computer is a perfect player.
		}
		cout << endl << "Would you like to play again?  Enter Y or N: ";
		cin >> playagainanswer;
		if (playagainanswer == 'Y')
		{
			playagain = 0;
		}
		else
		{
			playagain = 1;
		}
	}
    
return 0;   
}