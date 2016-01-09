/*
** this program simulates the "monty hall" problem
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(0));
	
	int trials = 1000000;	
	int wins = 0;	
	int noSwitchWins = 0;	
	int switchWins = 0;
	int correct = 0;
	int choice = 0;
	bool choiceChange = 0;
	
	/*
	 Loops *trials* amount of times
	 the logic within this loop does not account for overall wins or
	 losses. Every iteration of the following loop is a win. 
	*/			
	for (int i = 0; i < trials; ++i){
		correct = (1 + rand() %3);// decides which option is correct
		choice = (1 + rand() %3); // picks 1 of the 3 options
		choiceChange = (rand() %2) == 0; // decides if choice switches
		//if switching obtains the win
		if (choiceChange && choice != correct){
			wins++;
			switchWins++;
		} 
		//if not switching obtains the win
		else if (!choiceChange && choice == correct){
			wins++;
			noSwitchWins++;
		}
	}

	
	cout << switchWins * 100 / wins
	<< " percent success when you switch choice." << endl;
	cout << noSwitchWins * 100 / wins
	<< " percent succes if you stick with original choice." << endl;
}
