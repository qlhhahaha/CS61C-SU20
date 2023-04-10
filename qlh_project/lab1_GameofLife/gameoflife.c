/************************************************************************
**
** NAME:        gameoflife.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-23
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "imageloader.h"

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int ring(int n, int m)
{
	return (n + m) % m;
}

// Determines what color the cell at the given row/col should be. This function allocates space for a new Color.
// Note that you will need to read the eight neighbors of the cell in question. The grid "wraps", so we treat the top row as adjacent to the bottom row
// and the left column as adjacent to the right column.
Color *evaluateOneCell(Image *image, int row, int col, uint32_t rule)
{
	// YOUR CODE HERE
	Color *next_state = (Color *)malloc(sizeof(Color));
	int alive_neighbours_R = 0, alive_neighbours_G = 0, alive_neighbours_B = 0;
	int is_alive_R, is_alive_G, is_alive_B;
	int next_R, next_G, next_B;

	is_alive_R = (*(image->image + row * image->cols + col))->R == 255;
	is_alive_G = (*(image->image + row * image->cols + col))->G == 255;
	is_alive_B = (*(image->image + row * image->cols + col))->B == 255;

	for (int i = 0; i < 8; i++)
	{
		int new_row = ring(row + dx[i], image->rows);
		int new_col = ring(col + dy[i], image->cols);
		if ((*(image->image + new_row * image->cols + new_col))->R == 255)
		{
			alive_neighbours_R++;
		}
		if ((*(image->image + new_row * image->cols + new_col))->G == 255)
		{
			alive_neighbours_G++;
		}
		if ((*(image->image + new_row * image->cols + new_col))->B == 255)
		{
			alive_neighbours_B++;
		}
	}
	
	next_R = 9 * is_alive_R + alive_neighbours_R;
	next_G = 9 * is_alive_G + alive_neighbours_G;
	next_B = 9 * is_alive_B + alive_neighbours_B;

	if (rule & (1 << next_R))
		next_state->R = 255;
	else
		next_state->R = 0;

	if (rule & (1 << next_G))
		next_state->G = 255;
	else
		next_state->G = 0;

	if (rule & (1 << next_B))
		next_state->B = 255;
	else
		next_state->B = 0;

	return next_state;
}

// The main body of Life; given an image and a rule, computes one iteration of the Game of Life.
// You should be able to copy most of this from steganography.c
Image *life(Image *image, uint32_t rule)
{
	// YOUR CODE HERE
	Image *new_img = (Image *)malloc(sizeof(Image));
	new_img->cols = image->cols;
	new_img->rows = image->rows;
	new_img->image = (Color **)malloc(sizeof(Color *) * (image->rows) * (image->cols));
	Color **p = new_img->image;
	for (int i = 0; i < new_img->rows; i++)
		for (int j = 0; j < new_img->cols; j++)
		{
			*p = evaluateOneCell(image, i, j, rule);
			p++;
		}
	return new_img;
}

/*
Loads a .ppm from a file, computes the next iteration of the game of life, then prints to stdout the new image.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a .ppm.
argv[2] should contain a hexadecimal number (such as 0x1808). Note that this will be a string.
You may find the function strtol useful for this conversion.
If the input is not correct, a malloc fails, or any other error occurs, you should exit with code -1.
Otherwise, you should return from main with code 0.
Make sure to free all memory before returning!

You may find it useful to copy the code from steganography.c, to start.
*/
int main(int argc, char **argv)
{
	// YOUR CODE HERE
	if (argc != 3)
	{
		printf("usage: ./gameOfLife filename rule\nfilename is an ASCII PPM file (type P3) with maximum value 255.\nrule is a hex number beginning with 0x; Life is 0x1808.");
		return 1;
	}
	Image *img = readData(argv[1]);
	uint32_t rule = strtol(argv[2], NULL, 16);
	Image *life_mage = life(img, rule);
	writeData(life_mage);
	freeImage(img);
	freeImage(life_mage);
	return 0;
}
