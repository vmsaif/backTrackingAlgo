# Maze Solver
This program is designed to solve a maze using a backtracking algorithm. The program will take a maze as input and determine if a mouse can escape from it by systematically trying all the routes through the maze until it either finds the escape hatch or exhausts all possible routes (and concludes that the mouse is trapped in the maze). If the backtracking algorithm finds a dead end, it retraces its path until it reaches a position from which there is an untried path. The backtracking algorithm always tries all directions from any position, and always in the same order.

## Input
The input to the algorithm is a maze with walls (represented by '1' characters) and open passage ways (represented by '0' characters). The starting position of the mouse is represented by 'r' and the escape hatch from the maze by 'e'. The first line of the input will contain the number of rows and the number of columns in the maze.

An example of what a maze might look like as input:

    6 5
    1 1 1 1 1
    1 0 0 e 1
    1 1 1 0 1
    1 r 1 0 1
    1 0 0 0 1
    1 1 1 1 1
The maze will always have a wall around the outside, so you need not be concerned about the mouse falling off the maze as it explores all directions. The maze is stored in a two-dimensional array in the program. It is ensured that the program avoids subscripting the array "out of bounds" to avoid crashing or giving incorrect results.

## Algorithm
The backtracking algorithm keeps a list of positions that are the beginnings of paths it has yet to try. From the current position, the algorithm adds any untried open neighbouring positions (if there are any), always looking forward, backward, left and right from the current position. At each step, the algorithm gets the next position from the list and adds into the list the untried neighbouring positions. Finally, the algorithm must mark each visited position with a period ('.') to avoid revisiting positions – so that it will not loop forever trying the same routes.

Here is a pseudocode description of the algorithm:


    read in the maze;
    initialize the list;
    goalCell = the position of the escape hatch in the maze;
    startCell = the initial position of the mouse in the maze;
    currentCell = startCell;
    while (currentCell != goalCell and list is not empty)
      for each direction d in {forward, backward, left, right} do
        if (currentCell is not a wall and currentCell is not a visited position) then
          add currentCell to the list;
          mark currentCell as visited;
          if (currentCell == goalCell) then
            print "Escape found!";
      currentCell = next position in the list;
    if (currentCell == goalCell) then
      print "Escape found!";
    else
      print "No escape possible.";

## Design by Contract

This program will be using the principles of Design by Contract to ensure that our code is correct and robust. This involves writing preconditions, postconditions, and invariants for our functions, as well as using assertions to check that these conditions are met.

## How to Run
To run this program, follow these steps:

Compile the program using a C compiler, such as clang.
    
    clang -o maze_start maze_start.c

Run the program and provide the maze input through standard input.

    ./maze_start
        
    Enter Maze Filename:
    maze1.txt

You can replace maze1.txt (Which is included in the project root directory) with the path to any other maze input file you wish to use.
The program will output whether or not the mouse was able to find the escape hatch.

## What I Have Learned

- How to implement a backtracking algorithm
- How to use dynamic memory allocation and resource management
- How to apply the principles of Design by Contract

## A sample output

    ./maze_start 
    Enter Maze Filename: 
    maze1.txt

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 0 0 1 e 1 0 0 1 1 
    1 1 0 1 0 1 0 0 0 1 
    1 r 0 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 0 0 1 e 1 0 0 1 1 
    1 1 0 1 0 1 0 0 0 1 
    1 . 0 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 0 0 1 e 1 0 0 1 1 
    1 1 0 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 0 0 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 0 . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 0 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 0 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 0 0 0 0 0 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . 0 0 0 0 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . 0 0 0 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . 0 0 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . 0 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . 0 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . 0 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . 0 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 0 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 0 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . 0 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 0 0 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 0 . 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 0 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . 0 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . 0 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . . 1 
    1 . . 1 0 0 0 1 0 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . . 1 
    1 . . 1 0 0 0 1 . 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . . 1 
    1 . . 1 0 0 . 1 . 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . . 1 
    1 . . 1 0 . . 1 . 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 0 1 . . . 1 
    1 . . 1 . . . 1 . 1 
    1 1 1 1 1 1 1 1 1 1 

    1 1 1 1 1 1 1 1 1 1 
    1 . . . . . . . . 1 
    1 . 1 0 1 0 1 . 1 1 
    1 . 1 1 1 1 1 . . 1 
    1 . . 1 e 1 . . 1 1 
    1 1 . 1 . 1 . . . 1 
    1 . . 1 . . . 1 . 1 
    1 1 1 1 1 1 1 1 1 1 

    The mouse is free!!!!

    End of processing