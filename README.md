# Sudoku
These are a suite of C++ programs which deal with Sudoku Puzzles. first programs solves the sudoku puzzle while another program validates if the given sudoku is correct or not.

# Sudoku_Solver
This is a program which solves 9x9 Sudoku puzzles. Written completely in C++ and built wholly from scratch, this program reads input either from a user or from a file containing the Sudoku values and solves the puzzle. It employs concepts such as backtracking and recursion.
  ### Getting started
   - Simply download the sudoku_solver.cpp file found in the Sudoku-Solver/ directory. Run it using any standard C++ compiler. In case of any errors or compatibility issues, submit an issue in this git.
   
   -  Once downloaded, compiled and run; the program will require the user to input the Sudoku puzzle into it. There are two ways to do this.
   
        - The user can either input the values manually one-by-one when the program is running.
        
        - The user can write all the values into a file, seperated by whitespaces. The file can have any name or extension. When the program is running, the user will be prompted to simply enter the name of the file (with extension). Below is an example of how the contents of such a file might look. Look at the sample.txt files in the same directory for more examples.
        
               0 0 0  0 0 0  6 8 0
               0 0 0  0 7 3  0 0 9
               3 0 9  0 0 0  0 4 5
               
               4 9 0  0 0 0  0 0 0
               8 0 3  0 5 0  9 0 2
               0 0 0  0 0 0  0 3 6
               
               9 6 0  0 0 0  3 0 8
               7 0 0  6 8 0  0 0 0
               0 2 8  0 0 0  0 0 0
          
   - Once solved, the Sudoku puzzles shall be displayed like this.
    
               
                    ++=====================================++
                    || 1   7   2 || 5   4   9 || 6   8   3 ||
                    ++-----------++-----------++-----------++
                    || 6   4   5 || 8   7   3 || 2   1   9 ||
                    ++-----------++-----------++-----------++
                    || 3   8   9 || 2   6   1 || 7   4   5 ||
                    ++=====================================++
                    || 4   9   6 || 3   2   7 || 8   5   1 ||
                    ++-----------++-----------++-----------++
                    || 8   1   3 || 4   5   6 || 9   7   2 ||
                    ++-----------++-----------++-----------++
                    || 2   5   7 || 1   9   8 || 4   3   6 ||
                    ++=====================================++
                    || 9   6   4 || 7   1   5 || 3   2   8 ||
                    ++-----------++-----------++-----------++
                    || 7   3   1 || 6   8   2 || 5   9   4 ||
                    ++-----------++-----------++-----------++
                    || 5   2   8 || 9   3   4 || 1   6   7 ||
                    ++=====================================++

  ### How it works
   + start
   + we start with first unassigned cell.
   + we check for possible value and place that value in the unassigned cell. 
   + After assigning we move on to next position and fill it recursively.
   + if no possible number is available for any of the unassigned place then it will come back to previous cell and modify it with another possible value.
   + once all 81 cells are filled sudoku is solved.
   +stop.
   
 # sudoku validator
    This is a program which validates solutions for 9x9 Sudoku puzzles. Written completely in C++ and built wholly from scratch, this program takes in input from the user or from a file containing the values. It then validates the puzzle and then displays whether it is a valid solution or not.
   ### Getting started
   - Simply download the sudoku_solver.cpp file found in the Sudoku-Solver/ directory. Run it using any standard C++ compiler. In case of any errors or compatibility issues, submit an issue in this git.
   
   -  Once downloaded, compiled and run; the program will require the user to input the Sudoku puzzle into it. There are two ways to do this.
   
        - The user can either input the values manually one-by-one when the program is running.
        
        - The user can write all the values into a file, seperated by whitespaces. The file can have any name or extension. When the program is running, the user will be prompted to simply enter the name of the file (with extension). Below is an example of how the contents of such a file might look. Look at the sample.txt files in the same directory for more examples.
        
              8 4 6  9 3 7  1 5 2
              3 1 9  6 2 5  8 4 7
              7 5 2  1 8 4  9 6 3

              2 8 5  7 1 3  6 9 4
              4 6 3  8 5 9  2 7 1
              9 7 1  2 4 6  3 8 5

              1 2 7  5 9 8  4 3 6
              6 3 8  4 7 1  5 2 9
              5 9 4  3 6 2  7 1 8

### How it works.
      The workings of the Sudoku Validator are quite simple, to be honest. Here's a simple algorithm explaining them all.

        - Start
        - The values in all the cells are checked to see if they are in the range 1-9. If not, the puzzle is invalid.
        - Every row is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
        - Every column is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
        - Every 3x3 grid is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
        - If all the criteria have been satisfied, the solution is valid.
        - Stop
   
    
