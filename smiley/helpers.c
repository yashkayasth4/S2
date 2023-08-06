#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the color you want to change black pixels to
    int red = 255;   // Set the desired red value
    int green = 0;   // Set the desired green value
    int blue = 0;    // Set the desired blue value

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // Change the RGB values to represent the desired color
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
            }
        }
    }
}
