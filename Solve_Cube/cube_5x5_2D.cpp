#include<iostream>
#include"cube_5x5_2D.h"

using namespace std;

int pre_Face5[25] = {0, 4, 24, 20, 1, 2, 3, 9, 14, 19, 23, 22, 21, 15, 10, 5, 6, 8, 18, 16, 7, 13, 17, 11, 12};
int after_Face5[25] = {4, 24, 20, 0, 9, 14, 19, 23, 22, 21, 15, 10, 5, 1, 2, 3, 8, 18, 16, 6, 13, 17, 11, 7, 12};

int B_locate5[6][20] = {{0, 1, 2, 3, 4, 0, 1, 2, 3, 4,
                        0, 1, 2, 3, 4, 0, 1, 2, 3, 4}, //UP
                        {20, 15, 10, 5, 0, 4, 9, 14, 19, 24,
                        20, 15, 10, 5, 0, 20, 15, 10, 5, 0}, //LEFT
                        {24, 23, 22, 21, 20, 4, 9, 14, 19, 24,
                        0, 1, 2, 3, 4, 20, 15, 10, 5, 0}, //FRONT
                        {4, 9, 14, 19, 24, 4, 9, 14, 19, 24,
                        4, 9, 14, 19, 24, 20, 15, 10, 5, 0}, //RIGHT
                        {0, 1, 2, 3, 4, 4, 9, 14, 19, 24,
                        24, 23, 22, 21, 20, 20, 15, 10, 5, 0}, //BEHIND
                        {24, 23, 22, 21, 20, 24, 23, 22, 21, 20,
                        24, 23, 22, 21, 20, 24, 23, 22, 21, 20}}; //DOWN
                        
int B_center5[6][4] = {{1, 2, 3, 4}, //UP
                    {0, 4, 5, 2}, //LEFT
                    {0, 1, 5, 3}, //FRONT
                    {0, 2, 5, 4}, //RIGHT
                    {0, 3, 5, 1}, //BEHIND
                    {1, 4, 3, 2}}; //DOWN

int S_locate5[6][20] = {{5, 6, 7, 8, 9, 5, 6, 7, 8, 9,
                        5, 6, 7, 8, 9, 5, 6, 7, 8, 9}, //UP
                        {21, 16, 11, 6, 1, 3, 8, 13, 18, 23,
                        21, 16, 11, 6, 1, 21, 16, 11, 6, 1}, //LEFT
                        {19, 18, 17, 16, 15, 3, 8, 13, 18, 23,
                        5, 6, 7, 8, 9, 21, 16, 11, 6, 1}, //FRONT
                        {3, 8, 13, 18, 23, 3, 8, 13, 18, 23,
                        3, 8, 13, 18, 23, 21, 16, 11, 6, 1}, //RIGHT
                        {5, 6, 7, 8, 9, 3, 8, 13, 18, 23,
                        19, 18, 17, 16, 15, 21, 16, 11, 6, 1}, //BEHIND
                        {19, 18, 17, 16, 15, 19, 18, 17, 16, 15,
                        19, 18, 17, 16, 15, 19, 18, 17, 16, 15}}; //DOWN


Cube5X5 Rotate_Small_Clockwise_5X5(Cube5X5 bcube, int element)
{
    int i, j;
    Cube5X5 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<25; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    for (i=0; i<15; i++)
    {
        result.color[B_center5[element][i/5]][S_locate5[element][i]] = bcube.color[B_center5[element][i/5+1]][S_locate5[element][i+5]];
    }
    for (i=15; i<20; i++)
    {
        result.color[B_center5[element][3]][S_locate5[element][i]] = bcube.color[B_center5[element][0]][S_locate5[element][i-15]];
    }
    return result;
}

Cube5X5 Rotate_Big_Clockwise_5X5(Cube5X5 bcube, int element)
{
    int i, j;
    Cube5X5 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<25; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    //Rotate the main face
    for (i=0; i<25; i++)
    {
        result.color[element][after_Face5[i]] = bcube.color[element][pre_Face5[i]];
    }
    //surrounding faces
    for (i=0; i<15; i++)
    {
        result.color[B_center5[element][i/5]][B_locate5[element][i]] = bcube.color[B_center5[element][i/5+1]][B_locate5[element][i+5]];
    }
    for (i=15; i<20; i++)
    {
        result.color[B_center5[element][3]][B_locate5[element][i]] = bcube.color[B_center5[element][0]][B_locate5[element][i-15]];
    }
    return result;
}  

Cube5X5 Rotate_Small_Anti_Clockwise_5X5(Cube5X5 bcube, int element)
{
    int i, j;
    Cube5X5 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<25; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    for (i=5; i<20; i++)
    {
        result.color[B_center5[element][i/5]][S_locate5[element][i]] = bcube.color[B_center5[element][i/5-1]][S_locate5[element][i-5]];
    }
    for (i=0; i<5; i++)
    {
        result.color[B_center5[element][0]][S_locate5[element][i]] = bcube.color[B_center5[element][3]][S_locate5[element][i+15]];
    }
    return result;
}

Cube5X5 Rotate_Big_Anti_Clockwise_5X5(Cube5X5 bcube, int element)
{
    int i, j;
    Cube5X5 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<25; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    //Rotate the main face
    for (i=0; i<25; i++)
    {
        result.color[element][pre_Face5[i]] = bcube.color[element][after_Face5[i]];
    }
    //surrounding faces
    for (i=5; i<20; i++)
    {
        result.color[B_center5[element][i/5]][B_locate5[element][i]] = bcube.color[B_center5[element][i/5-1]][B_locate5[element][i-5]];
    }
    for (i=0; i<5; i++)
    {
        result.color[B_center5[element][0]][B_locate5[element][i]] = bcube.color[B_center5[element][3]][B_locate5[element][i+15]];
    }
    return result;
}
