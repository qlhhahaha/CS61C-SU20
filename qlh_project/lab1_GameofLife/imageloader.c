/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

// Opens a .ppm P3 image file, and constructs an Image object.
// You may find the function fscanf useful.
// Make sure that you close the file with fclose before returning.
Image *readData(char *filename)
{
	// YOUR CODE HERE
	FILE *image_ptr = fopen(filename, "r");
	if (image_ptr == NULL)
	{
		printf("fail to open %s.\n", filename);
		return NULL;
	}

	Image *my_img = (Image *)malloc(sizeof(Image));
	char tmp[3];
	int maxcolor;

	fscanf(image_ptr, "%s", tmp);
	if (tmp[0] != 'P' || tmp[1] != '3')
	{
		printf("%s is not a fucking correct ppm format\n", filename);
		return NULL;
	}

	fscanf(image_ptr, "%u", &my_img->cols);
	fscanf(image_ptr, "%u", &my_img->rows);
	fscanf(image_ptr, "%u", &maxcolor);
	if (my_img->cols < 0 || my_img->rows < 0 || maxcolor != 255)
	{
		printf("wrong ppm size\n");
		return NULL;
	}

	int total_pixels = my_img->cols * my_img->rows;
	my_img->image = (Color **)malloc(sizeof(Color *) * total_pixels);

	for (int i = 0; i < total_pixels; i++)
	{
		*(my_img->image + i) = (Color *)malloc(sizeof(Color));
		Color *pixel = *(my_img->image + i);
		fscanf(image_ptr, "%hhu %hhu %hhu", &pixel->R, &pixel->G, &pixel->B);
	}

	fclose(image_ptr);
	return my_img;
}

// Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	// YOUR CODE HERE
	printf("P3\n%d %d\n255\n", image->cols, image->rows);
	Color **p = image->image;
	for (int i = 0; i < image->rows; i++)
	{
		for (int j = 0; j < image->cols - 1; j++)
		{
			printf("%3hhu %3hhu %3hhu   ", (*p)->R, (*p)->G, (*p)->B);
			p++;
		}
		printf("%3hhu %3hhu %3hhu\n", (*p)->R, (*p)->G, (*p)->B);
		p++;
	}
}

// Frees an image
void freeImage(Image *image)
{
	// YOUR CODE HERE
	int total_pixels = image->cols * image->rows;
	for (int i = 0; i < total_pixels; i++)
	{
		free(*(image->image + i));
	}
	free(image->image);
	free(image);
}