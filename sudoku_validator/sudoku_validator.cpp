/*
 *========================
 *    Sudoku Validator
 *========================
 
 * Objective: To verify whether a completed Sudoku puzzle is valid or not.
*/

#include<iostream>
#include<fstream>
using namespace std;


class validator
{
    int grid[9][9];   // This array will hold all the values in the matrix.
    
    // constructor calls the respective member function to read the sudokuframe.
    public: validator(int opt)
    {
        if (opt == 1)
            readFrameValues();
        else if (opt == 2)
            readFrameValuesFile();
        else
        {
            while (true)
            {
                cout << "\nYou seem to have entered an invalid option. Try again.\n";
                cout << "\t   --> ";
                cin >> opt;

                if (opt == 1)
                    readFrameValues();
                else if (opt == 2)
                    readFrameValuesFile();
                else
                    continue;

                break;
            }
        }
            validate();
    }

    //Reads the values for the Sudoku Frame cell-by-cell.
	private:void readFrameValues(){
		cout<<"\nEnter the specified value when prompted.\n";
		cout<<"Enter 0 if cell is empty.\n\n";
		
		int rowIter, colIter;

		for(rowIter=0; rowIter<9; rowIter++){ //Iterating over cells to read vals.
			for(colIter=0; colIter<9; colIter++){
				int enteredValue;

				cout<<"Enter value for cell["<<rowIter+1<<"]["<<colIter+1<<"] --> ";
				cin>>enteredValue;

				if(!(enteredValue>=0 && enteredValue<=9)){ //Checking for bounds in input.
					while(true){ //We loop until valid input is read from user.
						cout<<"Oops! You seem to have entered a wrong value! Try again.\n";
						cout<<"Enter value for cell ["<<rowIter+1<<"]["<<colIter+1<<"] --> ";
						cin>>enteredValue;

						if(enteredValue>=0 && enteredValue<=9) break;
					}
				}

				grid[rowIter][colIter]=enteredValue;

				
			}
			cout<<"-------\n"; //Display a break after every row for convenience.
		}
	}
    
	//Reads the values from a file containing the frame values seperated by whitespaces.
    private:void readFrameValuesFile(){

		string filename; //Getting filename.

		cout<<"\nEnter the name of the file that contains the Sudoku Puzzle.\n";
		cout<<"\t   --> ";
		cin>>filename;

		ifstream sudokuFile; //Opening file for reading.
		sudokuFile.open(filename,ios::in);
		
		int rowIter, colIter;

		for(rowIter=0; rowIter<9; rowIter++){ //Iterating over file values.
			for(colIter=0; colIter<9; colIter++){
				int readValue;

				sudokuFile>>readValue;
		
				if(!(readValue>=0 && readValue<=9)){ //Checking bounds for input.
					cout<<"\nValue "<<((rowIter*9)+colIter+1)<<" in "<<filename;
					cout<<" seems to be wrong! Correct the value and try again!\n";
					exit(EXIT_FAILURE);
				}

				grid[rowIter][colIter]=readValue;

				if(sudokuFile.eof()) break; //Breaking if EOF is reached.
			}
		}
		
		//Gotta have a line which lets us check the frame for any errors

		sudokuFile.close();
	}

	// check if num is valid in current row
    private:bool checkrow(int row, int num, int numcol)
	{
		for (int col = 0; col < 9; col++)
			if (grid[row][col] == num  && numcol!=col)
				return false;
		return true;
	}
    // check if num is valid in current column
	private:bool checkcol(int col, int num,int numrow)
	{
		for (int row = 0; row < 9; row++)
			if (grid[row][col] == num && numrow!=row)
				return false;
		return true;
	}
    	// check if num is valid in current 3*3 box
	private:bool checkbox(int boxStartRow,int boxStartCol, int num,int numrow,int numcol)
	{
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
               
				if (grid[row + boxStartRow][col + boxStartCol] ==num  && numrow!=row + boxStartRow &&numcol!=col + boxStartCol)
					return false;
                
		return true;
	}

    //check for all validating condition of sudoku
    public:bool validate()
    {
        int num;
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                num=grid[row][col];
                if(num>=0 &&num<=9)
                {
                    if(checkbox(row - row % 3, col - col % 3, num,row,col)&&checkcol(col,num,row)&&checkrow(row,num,col))
                    continue;
                    else 
                    return false;
                   
                }
                else
                return false;
            }
        }
        return true;
    }
};

int main()
{
     // display the menu of all options available to user.

         cout<<"\n======================\n";
         cout<<"   Sudoku Validator\n";
         cout<<"======================\n\n";

         cout<<"Welcome to Sudoku Validator!\n";
         cout<<"Before we start, you will have to input the puzzle into this program.\n\n";
         cout<<"You can either:-\n";
         cout<<"\t1. Input the puzzle by entering the values manually. (Enter 1)\n";
         cout<<"\t2. Input the puzzle by reading a file with values in it. (Enter 2)\n";
         cout<<"\t   The file must not have a name > 30 characters.\n";
         cout<<"\t   The file must be in the same directory as this C++ file.\n";
         cout<<"\t   The file must have all 81 values seperated with spaces.\n";
         cout<<"\t   Blank cells must be filled in as 0 (eg; 1 2 9 8 1 9 ...).\n";
         cout<<"\t   --> ";

    int option;
    cin >> option;
    validator V(option);  //object of solver is initialised

    if(V.validate()==true)
    {
        cout<<"your puzzle is valid";
    }
    else{
        cout<<"your puzzle is invalid";
    }
}