#include "computer.h"
#include <cstdlib>
Computer::Computer(int level, int playerNum): Player(playerNum), level(level) {}

/*
bool Computer::movePiece() {
    switch (level) {
        case 1:
<<<<<<< HEAD
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
=======
            {
if(turn == 1){
    // fill an array from 1 to length
    int length = game->p1pieces.size();
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
			if(game->p1pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
				
			if(valid.size() != 0){
				int k = rand() % len;
				game->p1pieces.at(i).move(valid.at(k));
				return 1;
			}
		i++;

	}//while

	}
else{
	int length = game->p1pieces.size();
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
			if(game->p1pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
			
		if(valid.size() != 0){
			int k = rand() % len;
			game->p2pieces.at(i).move(valid.at(k));
			return 1;
		}
		i++;

	}//while

}
return 0;
}
>>>>>>> origin/master
            break;
            
        case 2:
            if(turn == 1){
    // fill an array from 1 to length
    int length = game->p1pieces.size();
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
		length1 = game->p2pieces.size()
		//finds all valid attacks, stores in first parts of stack
		for(int j = 1; j < length1; j++){
			if(game->p1pieces.at(i).isValidMove(game->p2pieces.at(j).getPos()))
				valid.push_back(calcPosition(j,k));
		}
		//finds rest of valid moves, stores after valid attacks
		for(int j = 1; j < 9; j++){
			for(int k = 1; k < 9; k++){
			if(game->p1pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
				//returns the first move
			if(valid.size() != 0){
				game->p1pieces.at(i).move(valid.at(1));
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
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
	while(i < length;){
		vector<int> valid;
		length1 = game->p1pieces.size()
		//finds all valid attacks, stores in first parts of stack
		for(int j = 1; j < length1; j++){
			if(game->p2pieces.at(i).isValidMove(game->p1pieces.at(j).getPos()))
				valid.push_back(calcPosition(j,k));
		}
		//finds rest of valid moves, stores after valid attacks
		for(int j = 1; j < 9; j++){
			for(int k = 1; k < 9; k++){
			if(game->p2pieces.at(i).isValidMove(calcPosition(j,k)))
				valid.push_back(calcPosition(j,k));
			}
		}
	//checks all positions for which are valid positions for the given piece, stores all valid in a vector
				//returns the first move2
			if(valid.size() != 0){
				game->p1pieces.at(i).move(valid.at(1));
				return 1;
			}
		i++;

	}//while

}
return 0;
}
            break;
            
        case 3:
            
            break;
            
        case 4:
            
            break;
            
        default:
            break;
    }
}*/
