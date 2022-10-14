/*
====================
    sudoku solver

Takes in sudoku solver and output its solution
====================
*/

#include <iostream>
#include <fstream>

using namespace std;

/**
 *	This class contain all the data member and member function that are required for solving sudoku
 */

class solver
{
    int grid[9][9];   // This array will hold all the values in the matrix.
    
    // constructor calls the respective member function to read the sudokuframe.
    public: solver(int opt)
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
		SolveSudoku();
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

	//finds blank position in grid
	private:bool FindUnassignedLocation(int &row, int &col)
	{
		for (row = 0; row < 9; row++)
			for (col = 0; col < 9; col++)
				if (grid[row][col] == 0)
					return true;
		return false;
	}

	/**
	 * Check if 'num' is not already placed in
		current row, current column
		and current 3x3 box 
		*/
	private:bool isSafe(int row,int col, int num)
	{
		return checkrow(row, num) && checkcol(col, num) && checkbox(row - row % 3, col - col % 3, num) && grid[row][col] == 0;
	}

	// check if num is present in current row
	private:bool checkrow(int row, int num)
	{
		for (int col = 0; col < 9; col++)
			if (grid[row][col] == num)
				return false;
		return true;
	}

	// check if num is present in current column
	private:bool checkcol(int col, int num)
	{
		for (int row = 0; row < 9; row++)
			if (grid[row][col] == num)
				return false;
		return true;
	}

	// check if num is present in current 3*3 box
	private:bool checkbox(int boxStartRow,int boxStartCol, int num)
	{
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				if (grid[row + boxStartRow][col + boxStartCol] ==num)
					return false;
		return true;
	}

	//make assignment to unassigned location iteratively 
	public:bool SolveSudoku()
	{
		int row, col;

		// If there is no unassigned location,
		// we are done
		if (!FindUnassignedLocation(row, col))
			// success!
			return true;

		// Consider digits 1 to 9
		for (int num = 1; num <= 9; num++)
		{

			// Check if looks promising
			if (isSafe(row, col, num))
			{

				// Make tentative assignment
				grid[row][col] = num;

				// Return, if success
				if (SolveSudoku())
					return true;

				// Failure, unmake & try again
				grid[row][col] = 0;
			}
		}

		// This triggers backtracking
		return false;
	}

	//print solved sukdoku
	public:void printgrid(){

		cout<<"------------sudoku is solved--------------\n";
		cout<<"Here is the solution\n";

		cout<<"\033[0;36m++=====================================++";
		int rowIter, colIter;

		for(rowIter=0; rowIter<9; rowIter++){
			int cellIter=1;

			cout<<"\n\033[0;36m||";
			for(colIter=0; colIter<9; colIter++){
				if(cellIter==3){
					cout<<"\033[0m "<<grid[rowIter][colIter]<<" ";
					cout<<"\033[0;36m||";
					cellIter=1;
				}
				else{
					cout<<"\033[0m "<<grid[rowIter][colIter]<<"  ";
					cellIter++;	
				}
			}

			if(rowIter%3!=2) cout<<"\n\033[0;36m++-----------++-----------++-----------++";
			else cout<<"\n\033[0;36m++=====================================++";
		}

	}
};





int main()
{
    // display the menu of all options available to user.

    cout << "\n======================\n";
    cout << "    Sudoku Solver\n";
    cout << "======================\n\n";

    cout << "Welcome to Sudoku Solver!\n";
    cout << "Before we start, you will have to input the puzzle into this program.\n\n";
    cout << "You can either:-\n";
    cout << "\t1. Input the puzzle by entering the values manually. (Enter 1)\n";
    cout << "\t2. Input the puzzle by reading a file with values in it. (Enter 2)\n";
    cout << "\t   The file must not have a name > 20 characters.\n";
    cout << "\t   The file must be in the same directory as this C++ file.\n";
    cout << "\t   The file must have all 81 values seperated with spaces.\n";
    cout << "\t   Blank cells must be filled in as 0 (eg; 1 0 0 2 0 0 ...).\n";
    cout << "\t   --> ";

    int option;
    cin >> option;
    solver s(option);  //object of solver is initialised

	if(s.SolveSudoku()==true)
	{
		s.printgrid();
	}
	else{
		cout << "No solution exists";
	}
}