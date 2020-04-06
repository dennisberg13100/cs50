#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            int n = round((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);

            image[i][j].rgbtRed = n;
            image[i][j].rgbtGreen = n;
            image[i][j].rgbtBlue = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = floor(width / 2); j < w; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            int count = 0;

            for (int k = -1; k < 2; k++)
            {
                if (i + k >= 0 && i + k < height)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if (j + l >= 0 && j + l < width)
                        {
                            sumRed = sumRed + temp[i + k][j + l].rgbtRed;
                            sumGreen = sumGreen + temp[i + k][j + l].rgbtGreen;
                            sumBlue = sumBlue + temp[i + k][j + l].rgbtBlue;

                            count++;
                            //printf("i+k = %i and j+l =%i", (i+k), (j+l));
                        }
                    }
                }
            }
            //printf("\ni = %i and j = %i count = %i\n", i , j, count);
            image[i][j].rgbtRed = (int)round(sumRed / count);
            //printf("%f\n", round(sumRed/count));
            image[i][j].rgbtGreen = (int)round(sumGreen / count);
            //printf("%f\n", round(sumGreen/count));
            image[i][j].rgbtBlue = (int)round(sumBlue / count);
            //printf("%f\n", round(sumBlue/count));
        }
    }
    return;

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy[3][3] =
    {
        {-1, -2, -1},
        { 0, 0, 0},
        { 1, 2, 1}
    };

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            int gxRed[3][3];
            int gyRed[3][3];

            int gxBlue[3][3];
            int gyBlue[3][3];

            int gxGreen[3][3];
            int gyGreen[3][3];

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && i + k < height)
                    {
                        if (j + l >= 0 && j + l < width)
                        {
                            gxRed[k + 1][l + 1] = (temp[i + k][j + l].rgbtRed) * gx[k + 1][l + 1];
                            gyRed[k + 1][l + 1] = (temp[i + k][j + l].rgbtRed) * gy[k + 1][l + 1];

                            gxBlue[k + 1][l + 1] = (temp[i + k][j + l].rgbtBlue) * gx[k + 1][l + 1];
                            gyBlue[k + 1][l + 1] = (temp[i + k][j + l].rgbtBlue) * gy[k + 1][l + 1];

                            gxGreen[k + 1][l + 1] = (temp[i + k][j + l].rgbtGreen) * gx[k + 1][l + 1];
                            gyGreen[k + 1][l + 1] = (temp[i + k][j + l].rgbtGreen) * gy[k + 1][l + 1];
                        }
                        else // if its ouside the image horizontaly
                        {
                            gxRed[k + 1][l + 1] = 0;
                            gyRed[k + 1][l + 1] = 0;

                            gxBlue[k + 1][l + 1] = 0;
                            gyBlue[k + 1][l + 1] = 0;

                            gxGreen[k + 1][l + 1] = 0;
                            gyGreen[k + 1][l + 1] = 0;
                        }
                    }
                    else // if it's ouside the image verticaly
                    {
                        gxRed[k + 1][l + 1] = 0;
                        gyRed[k + 1][l + 1] = 0;

                        gxBlue[k + 1][l + 1] = 0;
                        gyBlue[k + 1][l + 1] = 0;

                        gxGreen[k + 1][l + 1] = 0;
                        gyGreen[k + 1][l + 1] = 0;
                    }
                }
            }
            // Sum The matrix red
            double redX = 0;
            double redY = 0;
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    redX += gxRed[m][n];
                    redY += gyRed[m][n];
                }
            }
            redX *= redX;
            redY *= redY;
            int red = round(sqrt(redX + redY));
            if (red > 255)
            {
                red = 255;
            }

            // Sum The matrix blue
            double blueX = 0;
            double blueY = 0;
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    blueX += gxBlue[m][n];
                    blueY += gyBlue[m][n];
                }
            }
            blueX *= blueX;
            blueY *= blueY;
            int blue = round(sqrt(blueX + blueY));
            if (blue > 255)
            {
                blue = 255;
            }

            // Sum The matrix green
            double greenX = 0;
            double greenY = 0;
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    greenX += gxGreen[m][n];
                    greenY += gyGreen[m][n];
                }
            }
            greenX *= greenX;
            greenY *= greenY;
            int green = round(sqrt(greenX + greenY));
            if (green > 255)
            {
                green = 255;
            }
            //printf("x = %f, y = %f, red = %i\n", redX, redY, red);

            image[i][j].rgbtRed = red;
            //printf("%f\n", round(sumRed/count));
            image[i][j].rgbtGreen = green;
            //printf("%f\n", round(sumGreen/count));
            image[i][j].rgbtBlue = blue;
            //printf("%f\n", round(sumBlue/count));
        }
    }

    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         printf("[%i]", gy[i][j]);
    //     }
    //     printf("\n");
    // }

    return;
}
