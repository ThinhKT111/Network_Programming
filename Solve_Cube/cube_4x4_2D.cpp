#include<iostream>
#include"cube_4x4_2D.h"

using namespace std;

int pre_Face[16] = {0, 3, 15, 12, 1, 2, 7, 11,
                    14, 13, 8, 4, 5, 6, 10, 9};
int after_Face[16] = {3, 15, 12, 0, 7, 11, 14, 13,
                      8, 4, 1, 2, 6, 10, 9, 5};

int B_locate[6][16] = {{0, 1, 2, 3, 0, 1, 2, 3,
                        0, 1, 2, 3, 0, 1, 2, 3}, //UP
                        {12, 8, 4, 0, 3, 7, 11, 15,
                        12, 8, 4, 0, 12, 8, 4, 0}, //LEFT
                        {15, 14, 13, 12, 3, 7, 11, 15,
                        0, 1, 2, 3, 12, 8, 4, 0}, //FRONT
                        {3, 7, 11, 15, 3, 7, 11, 15,
                        3, 7, 11, 15, 12, 8, 4, 0}, //RIGHT
                        {0, 1, 2, 3, 3, 7, 11, 15,
                        15, 14, 13, 12, 12, 8, 4, 0}, //BEHIND
                        {15, 14, 13, 12, 15, 14, 13, 12,
                        15, 14, 13, 12, 15, 14, 13, 12}}; //DOWN
                        
int B_center[6][4] = {{1, 2, 3, 4}, //UP
                    {0, 4, 5, 2}, //LEFT
                    {0, 1, 5, 3}, //FRONT
                    {0, 2, 5, 4}, //RIGHT
                    {0, 3, 5, 1}, //BEHIND
                    {1, 4, 3, 2}}; //DOWN

int S_locate[6][16] = {{4, 5, 6, 7, 4, 5, 6, 7,
                        4, 5, 6, 7, 4, 5, 6, 7}, //UP
                        {13, 9, 5, 1, 2, 6, 10, 14,
                        13, 9, 5, 1, 13, 9, 5, 1}, //LEFT
                        {11, 10, 9, 8, 2, 6, 10, 14,
                        4, 5, 6, 7, 13, 9, 5, 1}, //FRONT
                        {2, 6, 10, 14, 2, 6, 10, 14,
                        2, 6, 10, 14, 13, 9, 5, 1}, //RIGHT
                        {4, 5, 6, 7, 2, 6, 10, 14,
                        11, 10, 9, 8, 13, 9, 5, 1}, //BEHIND
                        {11, 10, 9, 8, 11, 10, 9, 8,
                        11, 10, 9, 8, 11, 10, 9, 8}}; //DOWN


Cube4X4 Rotate_Small_Clockwise_4X4(Cube4X4 bcube, int element)
{
    int i, j;
    Cube4X4 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<16; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    for (i=0; i<12; i++)
    {
        result.color[B_center[element][i/4]][S_locate[element][i]] = bcube.color[B_center[element][i/4+1]][S_locate[element][i+4]];
    }
    for (i=12; i<16; i++)
    {
        result.color[B_center[element][3]][S_locate[element][i]] = bcube.color[B_center[element][0]][S_locate[element][i-12]];
    }
    return result;
}

Cube4X4 Rotate_Big_Clockwise_4X4(Cube4X4 bcube, int element)
{
    int i, j;
    Cube4X4 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<16; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    //Rotate the main face
    for (i=0; i<16; i++)
    {
        result.color[element][after_Face[i]] = bcube.color[element][pre_Face[i]];
    }
    //surrounding faces
    for (i=0; i<12; i++)
    {
        result.color[B_center[element][i/4]][B_locate[element][i]] = bcube.color[B_center[element][i/4+1]][B_locate[element][i+4]];
    }
    for (i=12; i<16; i++)
    {
        result.color[B_center[element][3]][B_locate[element][i]] = bcube.color[B_center[element][0]][B_locate[element][i-12]];
    }
    return result;
}  

Cube4X4 Rotate_Small_Anti_Clockwise_4X4(Cube4X4 bcube, int element)
{
    int i, j;
    Cube4X4 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<16; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    for (i=4; i<16; i++)
    {
        result.color[B_center[element][i/4]][S_locate[element][i]] = bcube.color[B_center[element][i/4-1]][S_locate[element][i-4]];
    }
    for (i=0; i<4; i++)
    {
        result.color[B_center[element][0]][S_locate[element][i]] = bcube.color[B_center[element][3]][S_locate[element][i+12]];
    }
    return result;
}

Cube4X4 Rotate_Big_Anti_Clockwise_4X4(Cube4X4 bcube, int element)
{
    int i, j;
    Cube4X4 result;
    for (i=0; i<6; i++)
    {
        for (j=0; j<16; j++)
        {
            result.color[i][j] = bcube.color[i][j];
        }
    }
    //Rotate the main face
    for (i=0; i<16; i++)
    {
        result.color[element][after_Face[i]] = bcube.color[element][pre_Face[i]];
    }
    //surrounding faces
    for (i=4; i<16; i++)
    {
        result.color[B_center[element][i/4]][B_locate[element][i]] = bcube.color[B_center[element][i/4-1]][B_locate[element][i-4]];
    }
    for (i=0; i<4; i++)
    {
        result.color[B_center[element][0]][B_locate[element][i]] = bcube.color[B_center[element][3]][B_locate[element][i+12]];
    }
    return result;
}
