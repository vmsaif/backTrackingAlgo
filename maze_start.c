
//-----------------------------------------/
// NAME: Saif Mahmud
// VERSION: 02/23/2020
// Purpose: Implementing backtracking algorithm to solve a maze.
//-----------------------------------------/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

#define MAX_DIMENSION 20

// constant definitions for the different cell states
const char WALL    = '1';
const char SPACE   = '0';
const char VISITED = '.';
const char MOUSE   = 'r';
const char EXIT    = 'e';
typedef enum BOOL { false, true } Boolean;

struct CELL
{
  int row;
  int column;
};
typedef struct CELL Cell;
typedef struct CELL_NODE CellNode;
struct CELL_NODE
{
  Cell     cell;
  CellNode *next;
};

//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

CellNode *top = NULL;

// a 2D array used to store the maze
char maze[MAX_DIMENSION][MAX_DIMENSION];
int mazeRows;
int mazeCols;

// holds the location of the mouse and escape hatch
Cell mouse;
Cell escape;

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

// basic cell manipulation

// returns true if the cells are at the same position in our maze
Boolean equalCells(const Cell cell1, const Cell cell2);
// returns a new cell object
Cell makeCell(const int row, const int col);
// returns true if the cell is within our maze
Boolean validCell(const Cell theCell);

// routines for managing our backtracking

// returns true if there are no more cells to try
Boolean noMoreCells();
// returns the next cell to try for a path out of the maze
Cell nextCell();
// introduces a new cell to try
void addCell(const Cell cell);

void printMaze();
void loadMaze();

// returns true if there's a solution to the maze
Boolean solveMaze();

// our invariant checker
void checkState();

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

int main( int argc, char *argv[] )
{
    loadMaze();
    if ( solveMaze() )
      printf( "The mouse is free!!!!\n" );
    else
      printf( "The mouse is trapped!!!!\n" );
    
    printf( "\nEnd of processing\n" );
    
  return EXIT_SUCCESS;
}
Boolean solveMaze()
{
    Boolean hasSolution = true;
    Boolean gotSolution = false;
    printf("\n");
    printMaze();
    Cell curr = mouse;
    char item;

    validCell(mouse);
    validCell(escape);
    checkState();

    while(hasSolution == true && gotSolution == false && equalCells(curr, escape) == false )
    {
        maze[curr.row][curr.column] = VISITED; //mark curr/start as visited

        if(maze[curr.row+1][curr.column] == EXIT || maze[curr.row][curr.column+1] == EXIT ||
           maze[curr.row-1][curr.column] == EXIT || maze[curr.row][curr.column-1] == EXIT)
            // that means got just in one step ahead.
        {
            gotSolution = true;
        }
        else if(gotSolution == false)
        {
            if(maze[curr.row+1][curr.column] == SPACE ) // going down
            {
                addCell(makeCell(curr.row+1, curr.column));
            }
            if(maze[curr.row][curr.column+1] == SPACE ) // going right
            {
                addCell(makeCell(curr.row, curr.column+1));
            }
            if(maze[curr.row-1][curr.column] == SPACE ) // going up
            {
                addCell(makeCell(curr.row-1, curr.column));
            }
            if(maze[curr.row][curr.column-1] == SPACE ) // going left
            {
                addCell(makeCell(curr.row, curr.column-1));
            }

            if(noMoreCells() == true )
            {
                hasSolution = false;
            } else {
                curr = nextCell();
                validCell(curr);
            }
        }
        printMaze();
    }
    return hasSolution;
}
Boolean equalCells(const Cell cell1, const Cell cell2)
{
    validCell(cell1);
    validCell(cell2);

    Boolean result = false;
    if(cell1.column == cell2.column && cell1.row == cell2.row)
    {
        result = true;
    }
    return result;
}
Cell makeCell(const int row, const int col)
{
    Cell newCell;
    newCell.row = row;
    newCell.column = col;
    validCell(newCell);
    return newCell;
}
Boolean validCell(const Cell theCell)
{
    assert(theCell.row <= mazeRows);
    assert(theCell.column <= mazeCols);
    assert(theCell.row <= MAX_DIMENSION);
    assert(theCell.column <= MAX_DIMENSION);

    Boolean result = false;
    if(theCell.row <= mazeRows && theCell.column <= mazeCols)
    {
        result = true;
    }
    return result;
}
Boolean noMoreCells()
{
    Boolean result = false;
    if(top == NULL)
    {
        result = true;
    }
    return result;
}
Cell nextCell()
{
    checkState();
    Cell out;
    out = top->cell;
    top = top->next;
    validCell(out);
    return out;
}
void addCell(const Cell cell)
{
    validCell(cell);
    CellNode *myNode = (CellNode *) malloc(sizeof(CellNode));
    myNode->cell = cell;
    myNode->next = top;
    top = myNode;
    checkState();
}

void checkState()
{
#ifdef NDEBUG
    assert(mazeRows > 0);
    assert(mazeCols > 0);
    assert(mazeRows <= MAX_DIMENSION);
    assert(mazeCols <= MAX_DIMENSION);

    validCell(mouse);
    validCell(escape);
    CellNode *curr = top;

    while(curr != NULL)
    {
        validCell(curr->cell);
        curr = curr->next;
    }
#endif
}
void loadMaze()
{
    FILE *f;
    char fileName[100];
    
    printf("Enter Maze Filename: \n");
    fscanf(stdin, "%s", fileName);
    f = fopen(fileName, "r");
    char oneLine[MAX_DIMENSION];
    char row, col;
    fscanf(f, "%s", &row);
    mazeRows = strtol(&row, NULL, 10);
    fscanf(f, "%s", &col);
    mazeCols = strtol(&col, NULL, 10);

    assert(mazeRows > 0);
    assert(mazeRows <= MAX_DIMENSION);
    assert(mazeCols > 0);
    assert(mazeCols <= MAX_DIMENSION);

    for (int i = 0; i < mazeRows; i++) // fill maze array and set mouse, escape cell
    {
        for (int j = 0; j < mazeCols; j++)
        {
            fscanf(f, "%s", &maze[i][j]);
            if ( maze[i][j] == MOUSE )
            {
                mouse = makeCell( i, j );
            }
            else if ( maze[i][j] == EXIT )
            {
                escape = makeCell(i, j);
            }
        }
    }
    fclose(f);
}
void printMaze() {
    for (int i = 0; i < mazeRows; i++)
    {
        for (int j = 0; j < mazeCols; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}