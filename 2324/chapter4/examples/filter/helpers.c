#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            //calc average via the 255 RGB values and set to avg
            BYTE avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            //set each color to according avg
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        //width / 2 --> flipping half of the image over the center
        for (int j = 0; j < width / 2; j++){

            //swap pixels --> is there a function/better way to do this?
            RGBTRIPLE temp = image[i][j];
            //width - 1 - j  --> mirroring pixels ACROSS CENTER
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            //vars for sum of pixels
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            //interate over neighboring pixels
            //"di" & "dj" meaning delta i and delta j --> apparently its "good practice"
            //-1, 0,1 --> accesses entire 3x3 grid, (0,0) being the middle pixel
            for (int di = -1; di <= 1; di++){
                for (int dj = -1; dj <= 1; dj++){

                    int newRow = i + di;
                    int newCol = j + dj;

                    //check if neighboring pixels are within image
                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width){
                        sumBlue += image[newRow][newCol].rgbtBlue;
                        sumGreen += image[newRow][newCol].rgbtGreen;
                        sumRed += image[newRow][newCol].rgbtRed;
                        count++;
                    }
                }
            }

            //calc avg for each color channel
            temp[i][j].rgbtBlue = round((float)sumBlue / count);
            temp[i][j].rgbtGreen = round((float)sumGreen / count);
            temp[i][j].rgbtRed = round((float)sumRed / count);
        }
    }

    //copy blured values back in original image
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            //assign
            image[i][j] = temp[i][j];
        }
    }
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //sobel gx and gy kernels
    //   Gx: -1 0 1     Gy: -1 -2 -1
    //       -2 0 2          0  0  0
    //       -1 0 1          1  2  1
    //calc for two gradients for each pixel: G = sqrt(Gx^2 + Gy^2)
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2,}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE temp[height][width];

    //apply gx and gy to each pixel, looped thru pixels
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sumRedX = 0, sumGreenX = 0, sumBlueX = 0;
            int sumRedY = 0, sumGreenY = 0, sumBlueY = 0;

            //check if neighboring pixels are within image
            for (int di = -1; di <= 1; di++){
                for (int dj = -1; dj <= 1; dj++){
                    int x = i + di;
                    int y = j + dj;

                    //check if within bounds
                    if (x >= 0 && x < height && y >= 0 && y < width){
                        //apply thru compute
                        sumRedX += image[x][y].rgbtRed * Gx[di + 1][dj + 1];
                        sumGreenX += image[x][y].rgbtGreen * Gx[di + 1][dj + 1];
                        sumBlueX += image[x][y].rgbtBlue * Gx[di + 1][dj + 1];

                        sumRedY += image[x][y].rgbtRed * Gy[di + 1][dj + 1];
                        sumGreenY += image[x][y].rgbtGreen * Gy[di + 1][dj + 1];
                        sumBlueY += image[x][y].rgbtBlue * Gy[di + 1][dj + 1];
                    }

                }
            }
        }

        //calc new values thru sum of squared values sqrted
        temp[i][j].rgbtRed = round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY));
        temp[i][j].rgbtGreen = round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY));
        temp[i][j].rgbtBlue = round(sqrt(sumBlueX* sumBlueX + sumBlueY * sumBlueY));
    }

    //copy edge values back to original image
    for (int i = 0; i <  height; i++){
        for (int j = 0; j < width; j++){
            image[i][j] = temp[i][j];
        }
    }
}
