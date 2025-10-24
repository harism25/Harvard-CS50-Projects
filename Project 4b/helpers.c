#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Going through every row of the image
    for (int i = 0; i < height; i++)
    {
        // And to every pixel of each row
        for (int j = 0; j < width; j++)
        {
            // Getting the original red, green, blue values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Finding the average color value (use of 3.0 for float number)
            int average = round((red + green + blue) / 3.0);

            // Setting all colors to the same average value
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through every row of the image
    for (int i = 0; i < height; i++)
    {
        // And through every pixel in this row
        for (int j = 0; j < width; j++)
        {
            // Setting the original color values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Calculating the new sepia values
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Cap values at 255 (color values can’t go above 255)
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            // Putting new sepia values back to the pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through each row
    for (int i = 0; i < height; i++)
    {
        // Only looping through half of the pixels, since we will swap both sides
        for (int j = 0; j < width / 2; j++)
        {
            // Storing pixel from the left temporarily
            RGBTRIPLE temp = image[i][j];

            // Moving pixel from right to left
            image[i][j] = image[i][width - 1 - j];

            // Moving left pixel (now in temp) to right
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Making copy of the image so we don’t use updated pixels too early
    RGBTRIPLE copy[height][width];

    // Copying each pixel’s color values into new image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Now blur using the copied image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            int counter = 0;

            // Checking all surrounding pixels (3x3 box)
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int currentRow = i + row;
                    int currentCol = j + col;

                    // Making sure we stay inside image boundaries
                    if (currentRow >= 0 && currentRow < height && currentCol >= 0 &&
                        currentCol < width)
                    {
                        totalRed += copy[currentRow][currentCol].rgbtRed;
                        totalGreen += copy[currentRow][currentCol].rgbtGreen;
                        totalBlue += copy[currentRow][currentCol].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Calculating average of surrounding pixels
            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
}
