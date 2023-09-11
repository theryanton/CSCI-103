/* 
maze.cpp
*/

/* Ryan Ton
rton@usc.edu
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
  
   mymaze = read_maze(argv[1], &rows, &cols); // <---TASK: COMPLETE THIS FOR CHECKPOINT 1
   
     
     
   if (mymaze == NULL) {
      cout << "Error, input format incorrect." << endl;
      return 1;
   }
	 //================================
   // When working on Checkpoint 4, you will call maze_search here.
   // But for Checkpoint 1, just assume we found the path.
  
    result = maze_search(mymaze, rows, cols); // <--- TASK: CHANGE THIS FOR CHECKPOINT 4
	
	
   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

	 //================================
   // ADD CODE BELOW
   // to delete all memory that read_maze allocated: CHECKPOINT 2

   for (int i=0; i<rows; i++) // deallocates memory used to read in maze
   {
      char* rows = mymaze[i];
      delete [] rows;
   }
   delete [] mymaze;
  
   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 * NOTE: don't forget to deallocate memory in here too!
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
  // *** You complete **** CHECKPOINT 4
  int sflag=0, fflag=0; // use flags check if f and s characters exist in maze
  Location start, finish;
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<cols; j++)
    {
      if (maze[i][j] == 'S')
      {
        sflag += 1;
        start.row = i;
        start.col = j;
      }
    }
  }
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<cols; j++)
    {
      if (maze[i][j] == 'F')
      {
        fflag += 1;
        finish.row = i;
        finish.col = j;
      }
    }
  }
  if (sflag!=1 || fflag!=1)
  {
    return -1; // poorly formatted maze
  }
  Queue q(rows*cols); // calls queue function to format q of size rows*cols
  q.add_to_back(start); // start checked

  bool **visited = new bool*[rows]; // initialized visited array checks if paths are searched yet
  for (int i=0; i<rows; i++)
  {
    visited[i] = new bool[cols];
  }
  for (int i=0; i< rows; i++)
  {
    for (int j=0; j<cols; j++)
    {
      visited[i][j] = false;
    }
  }

  Location **predecessor = new Location*[rows]; // use location type to initialize 2d array for predecessor
  for (int i=0; i<rows; i++)
  {
    predecessor[i] = new Location[cols];
  }

  while (q.is_empty() == false) // while elements in queue
  {
    Location top, north, south, west, east;
    top = q.remove_from_front();
    if (maze[top.row][top.col] == 'F') // if finish mark is hit
    {
      Location l = predecessor[finish.row][finish.col]; // element preceding finish
      while (l.row != start.row || l.col != start.col) // iterate through predecessor array, marking correct path back to start
      {
        maze[l.row][l.col] = '*';
        l = predecessor[l.row][l.col]; // change current loc in predecessor array to previous
      }

      for (int i=0; i<rows; i++) // deallocate memory used for visited and predecessor array if correct path exists
      {
        bool *rows = visited[i];
        delete [] rows;
      }
      delete [] visited;

      for (int i=0; i<rows; i++)
      {
        Location *rows = predecessor[i];
        delete [] rows;
      }
      delete [] predecessor;

      return 1;
    }
    if (top.row-1 >= 0) // north neighbor
    {
      if (maze[top.row-1][top.col] != '#') // check if hitting wall
      {
        if (visited[top.row-1][top.col] == false) // check if index jas already been visited
        {
          north.row = top.row-1;
          north.col = top.col;
          q.add_to_back(north);
          visited[north.row][north.col] = true;
          predecessor[north.row][north.col] = top;
        }
      }
    }
    if (top.row+1 < rows) // south neighbor
    {
      if (maze[top.row+1][top.col] != '#') 
      {
        if (visited[top.row+1][top.col] == false)
        {
          south.row = top.row+1;
          south.col = top.col;
          q.add_to_back(south);
          visited[south.row][south.col] = true;
          predecessor[south.row][south.col] = top;
        }
      }
    }
    if (top.col-1 >=0) //west neighbor
    {
      if (maze[top.row][top.col-1] != '#') 
      {
        if (visited[top.row][top.col-1] == false)
        {
          west.row = top.row;
          west.col = top.col-1;
          q.add_to_back(west);
          visited[west.row][west.col] = true;
          predecessor[west.row][west.col] = top;
        }
      }
    }
    if (top.col+1 < cols) // east neighbor
    {
      if (maze[top.row][top.col+1] != '#') 
      {
        if (visited[top.row][top.col+1] == false)
        {
          east.row = top.row;
          east.col = top.col+1;
          q.add_to_back(east);
          visited[east.row][east.col] = true;
          predecessor[east.row][east.col] = top;
        }
      }
    }
  }
  for (int i=0; i<rows; i++) // deallocate memory if correct path does not exist
  {
    bool *rows = visited[i];
    delete [] rows;
  }
  delete [] visited;

  for (int i=0; i<rows; i++)
  {
    Location *rows = predecessor[i];
    delete [] rows;
  }
  delete [] predecessor;

  return 0;
}