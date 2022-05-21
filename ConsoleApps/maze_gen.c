#include <stdlib.h>
#include "maze_gen.h"

/*
 * See maze_gen.h for descriptions of functions.
 */

int inBounds(int x, int y, int n) {
	if ((x + 1 >= n) || (y + 1 >= n) || (x - 1 < 0) || (y - 1 < 0))
	   return 0;
	return 1;
}


int joinsSameColor(char **maze, int x, int y, int n) {
	char a = 0, b = 0, c = 0, d = 0;

	if (inBounds(x + 1, y, n))
	   a = maze[x + 1][y];
	if (a == '#')
	   a = 0;

	if (inBounds(x - 1, y, n))
	   b = maze[x - 1][y];
	if (b == '#')
	   b = 0;

	if (inBounds(x, y + 1, n))
	   c = maze[x][y + 1];
	if (c == '#')
	   c = 0;

	if (inBounds(x, y - 1, n))
	   d = maze[x][y - 1];
	if (d == '#')
	   d = 0;

	if ((a == b) && a)
	   return 1;
	if ((a == c) && a)
	   return 1;
	if ((a == d) && a)
	   return 1;
	if ((b == c) && b)
	   return 1;
	if ((b == d) && b)
	   return 1;
	if ((c == d) && c)
	   return 1;

	return 0;
}


int joinsSomethingUseful(char **maze, int x, int y, int n) {
	char a = 0, b = 0, c = 0, d = 0;

	int cnt = 0;

	if (inBounds(x + 1, y, n))
	   a = maze[x + 1][y];
	if (a == '#')
	   a = 0;

	if (inBounds(x - 1, y, n))
	   b = maze[x - 1][y];
	if (b == '#')
	   b = 0;

	if (inBounds(x, y + 1, n))
	   c = maze[x][y + 1];
	if (c == '#')
	   c = 0;

	if (inBounds(x, y - 1, n))
	   d = maze[x][y - 1];
	if (d == '#')
	   d = 0;

	if (a) cnt++;
	if (b) cnt++;
	if (c) cnt++;
	if (d) cnt++;

	if (cnt >= 2)
	   return 1;

	return 0;
}

int wall_status_update(char **maze, int **wall_status, int n) {

	int numEligible = 0, x, y;

	for (x = 1; x < (n - 1); x++)
	    for (y = 1; y < (n - 1); y++)
	        if (wall_status[x][y]) {
	           if (maze[x][y] != '#')
	              wall_status[x][y] = 0;
	           else if (joinsSameColor(maze, x, y, n))
	              wall_status[x][y] = 0;
	           else if (joinsSomethingUseful(maze, x, y, n)) {
	              wall_status[x][y] = 1;
	              numEligible++;
	           }
	           else
	              wall_status[x][y] = -1;
	        }

	return numEligible;
}


int maze_color(char **maze, int x, int y, char color, int n) {

	if (!(inBounds(x, y, n)))
	   return 0;
	if ((maze[x][y] == '#') || maze[x][y] == color)
	   return 0;

	maze[x][y] = color;
	maze_color(maze, x + 1, y, color, n);
	maze_color(maze, x - 1, y, color, n);
	maze_color(maze, x, y + 1, color, n);
	maze_color(maze, x, y - 1, color, n);

	return 0;
}

int remove_wall(char **maze, int **wall_status, int wall, int n) {

	int x, y, rx, ry, cnt = -1;
	char color;

	/* Find wallth wall in wall_status grid that is equal to 1 */
	for (x = 1; x < (n - 1); x++)
	    for (y = 1; y < (n - 1); y++)
	        if (wall_status[x][y] == 1)
	           if (++cnt == wall) {
	              rx = x;
	              ry = y;
	           }

	/* Laziness... I'm not rewriting all the x's and y's below. */
	x = rx;
	y = ry;

	/* Find a color adjacent to the wall being removed */
	if (inBounds(x + 1, y, n) && (maze[x + 1][y] != '#')) {
	   color = maze[x + 1][y];
	   maze_color(maze, x - 1, y, color, n);
	   maze_color(maze, x, y + 1, color, n);
	   maze_color(maze, x, y - 1, color, n);
	}
	if (inBounds(x - 1, y, n) && (maze[x - 1][y] != '#')) {
	   color = maze[x - 1][y];
	   maze_color(maze, x, y + 1, color, n);
	   maze_color(maze, x, y - 1, color, n);
	}
	if (inBounds(x, y + 1, n) && (maze[x][y + 1] != '#')) {
	   color = maze[x][y + 1];
	   maze_color(maze, x, y - 1, color, n);
	}

	maze[rx][ry] = color;

	return 0;
}


int maze_create(char *my_maze, int maze_size) {

	char **maze;
	int **wall_status;
	int n = maze_size, i, x, y, cnt;
	int color = 65;
	int numEligible;
	int wall;
	char fileName[20];
	FILE *outFile;

	/* Dynamically allocate 2D character array for maze */
	maze = malloc(sizeof(char *) * n);
	for (i = 0; i < n; i++)
	    maze[i] = malloc(sizeof(char) * n);

	/* Dynamically allocate 2D character array for wall status grid */
	wall_status = malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
	    wall_status[i] = malloc(sizeof(int) * n);

	/* Initialize grid */
	for (x = 0; x < n; x++)
	    for (y = 0; y < n; y++)
	        if (!(x % 2) || !(y % 2))
	           maze[x][y] = '#';
	        else {
	           maze[x][y] = color;
	           color++;
	        }

	/* Wall status codes:
	 * 0 permanently defunct
	 * Not eligible for removal now
	 * Eligible for removal now
	 */

	/* Set up wall status grid */
	for (x = 1; x < (n - 1); x++)
	    for (y = 1; y < (n - 1); y++)
	        if (maze[x][y] == '#')
	           wall_status[x][y] = -1;
	        else
	           wall_status[x][y] = 0;

	/* Cement perimeter of maze in place */
	for (x = 0; x < n; x ++) {
		wall_status[0][x] = 0;
		wall_status[n - 1][x] = 0;
		wall_status[x][0] = 0;
		wall_status[x][n - 1] = 0;
	}

	/* Seed random number generator with the time */
	srand(time(NULL));

	while (numEligible = wall_status_update(maze, wall_status, n)) {
	      wall = rand() % numEligible;
	      remove_wall(maze, wall_status, wall, n);
	}

	/* Clean up ASCII maze */
	for (x = 0; x < n; x++)
	    for (y = 0; y < n; y++)
	        if (maze[x][y] != '#')
	           maze[x][y] = ' ';

	/* Pick a random starting point */
	x = rand() % (maze_size - 2) + 1;
	while (maze[x][1] != ' ')
	      x = rand() % (maze_size - 2) + 1;
	maze[x][0] = 's';

	/* Pick a random ending point */
	y = rand() % (maze_size - 2) + 1;
	while (maze[y][maze_size - 2] != ' ')
		y = rand() % (maze_size - 2) + 1;
	maze[y][maze_size - 1] = 'e';

	/* Drop the maze into the array passed to the function by the user */

	cnt = 0;

	for (x = 0; x < maze_size; x++)
	    for (y = 0; y < maze_size; y++) {
	        my_maze[cnt] = maze[x][y];
	        cnt++;
	    }

	return 0;
}
