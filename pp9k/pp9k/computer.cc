#include "computer.h"
#include <cstdlib>
Computer::Computer(int level, int playerNum): Player(playerNum), level(level) {}

bool Computer::movePiece() {
    switch (level) {
        case 1:
            {
if(turn == 0){
    // fill an array from 1 to length
    int length = p1pieces.size();
	int arr[length];
	for(int i = 0; i < length; i++)
		arr[i] = i;

	//random swap so the order of numbers is random
	for(int i = 0; i < length; i++){
		int ran = rand() % length - 1;
		int temp = arr[i];
		arr[i] = arr[ran];
		arr[ran] = temp;
	}
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
	while(i < length;){
		vector<int> valid;
		for(int j = 1; j < 9; j++){
			for(int k = 1; k < 9; k++){
			if(p1pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
				
			if(valid.size() != 0){
				int k = rand() % len;
				p1pieces.at(i).move(valid.at(k));
				return 1;
			}
		i++;

	}//while

	}
else{
	int length = p1pieces.size();
	int arr[length];
	for(int i = 0; i < length; i++)
		arr[i] = i;
	//random swap
	for(int i = 0; i < length; i++){
		int ran = rand() % length - 1;
		int temp = arr[i];
		arr[i] = arr[ran];
		arr[ran] = temp;
	}

	while(i < length){
		vector<int> valid;

		for(int j = 1; j < 9; j++){
			for(int k = 1; k < 9; k++){
			if(p1pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
			
		if(valid.size() != 0){
			int k = rand() % len;
			p2pieces.at(i).move(valid.at(k));
			return 1;
		}
		i++;

	}//while

}
return 0;
}
            break;
            
        case 2:
            
            break;
            
        case 3:
            
            break;
            
        case 4:
            
            break;
            
        default:
            break;
    }
}
