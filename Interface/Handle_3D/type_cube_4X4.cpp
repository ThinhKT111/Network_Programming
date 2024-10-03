#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"
#include "type_cube_4X4.h"
#include "../../Solve_Cube/cube_4x4_2D.h"

using namespace std;

GLfloat range_of_center_4X4 = 30.f;
GLfloat length_cube_4X4 = 14.f;

GLfloat center_location_4X4[64][3];

void init_center_location_4X4()
{
    int i, j;
    for (i=0; i<64; i++)
    {
        //Ox
        switch ((i%16)%4)
        {
            case 0: center_location_4X4[i][0] = 1.5f * -range_of_center_4X4; break;
            case 1: center_location_4X4[i][0] = 0.5f * -range_of_center_4X4; break;
            case 2: center_location_4X4[i][0] = 0.5f * range_of_center_4X4; break;
            case 3: center_location_4X4[i][0] = 1.5f * range_of_center_4X4; break;
            default: break;
        }     

        //Oz
        if ((i%16) >=0 && (i%16) < 4)
        {
            center_location_4X4[i][2] = 1.5f * -range_of_center_4X4;
        }
        else if ((i%16) >=4 && (i%16) < 8)
        {
            center_location_4X4[i][2] = 0.5f * -range_of_center_4X4;
        }
        else if ((i%16) >=8 && (i%16) < 12)
        {
            center_location_4X4[i][2] = 0.5f * range_of_center_4X4;
        }
        else
        {
            center_location_4X4[i][2] = 1.5f * range_of_center_4X4;
        }

        //Oy
        if (i < 16)
        {
            center_location_4X4[i][1] = 1.5f * range_of_center_4X4;
        }
        else if (i >= 16 && i < 32)
        {
            center_location_4X4[i][1] = 0.5f * range_of_center_4X4;
        }
        else if (i >= 32 && i < 48)
        {
            center_location_4X4[i][1] = -0.5f * range_of_center_4X4;
        }
        else
        {
            center_location_4X4[i][1] = -1.5f * range_of_center_4X4;
        }
    }
}

void init_cube4X4_location(GLfloat cube4X4_location[64][108])
{
    int i, j;

    init_center_location_4X4();

    for (i=0; i<64; i++)
    {
        for (j=0; j<108; j++)
        {
            cube4X4_location[i][j] = center_location_4X4[i][j%3] + (cube[j%3 + 7*(j/3)]*length_cube_4X4)/23;
        }
    }
}

void init_cube4X4_color(GLfloat cube4X4_color[64][144])
{
    int i, j;
    for (i=0; i<64; i++)
    {
        if (i<16)
        {
            for (j=0; j<24; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // yellow
        }
        else if (i>=48)
        {
            for (j=120; j<144; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // white
        }
        if (i%4 == 0)
        {
            for (j=24; j<48; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // blue
        }
        else if (i%4 == 3)
        {
            for (j=72; j<96; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // green
        }
        if (i == 0 || i == 1 || i == 2 || i == 3 ||
            i == 16 || i == 17 || i == 18 || i == 19 || 
            i == 32 || i == 33 || i == 34 || i == 35 ||
            i == 48 || i == 49 || i == 50 || i == 51)
        {
            for (j=96; j<120; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // orange
        }
        else if (i == 12 || i == 13 || i == 14 || i == 15 ||
                 i == 28 || i == 29 || i == 30 || i == 31 ||
                 i == 44 || i == 45 || i == 46 || i == 47 ||
                 i == 60 || i == 61 || i == 62 || i == 63)
        {
            for (j=48; j<72; j++)
                cube4X4_color[i][j] = cube[j%4 + 7*(j/4) + 3]; //red
        }
    }
}

void Spray_Cube_4X4(GLfloat cube4x4_color[64][144], Cube4X4 bcube)
{
    int i, j, k;
    
    GLfloat color3D[4];

    int ordinal_yellow_face[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int ordinal_blue_face[16] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60};
    int ordinal_red_face[16] = {12, 13, 14, 15, 28, 29, 30, 31, 44, 45, 46, 47, 60, 61, 62, 63};
    int ordinal_green_face[16] = {15, 11, 7, 3, 31, 27, 23, 19, 47, 43, 39, 35, 63, 59, 55, 51};
    int ordinal_orange_face[16] = {3, 2, 1, 0, 19, 18, 17, 16, 35, 34, 33, 32, 51, 50, 49, 48};
    int ordinal_white_face[16] = {60, 61, 62, 63, 56, 57, 58, 59, 52, 53, 54, 55, 48, 49, 50, 51};

    for (i=0; i<6; i++)
    {
        switch(i)
        {
            case 0: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=0; k<24; k++)
                        {
                            cube4x4_color[ordinal_yellow_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 1: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=24; k<48; k++)
                        {
                            cube4x4_color[ordinal_blue_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 2: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=48; k<72; k++)
                        {
                            cube4x4_color[ordinal_red_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 3: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=72; k<96; k++)
                        {
                            cube4x4_color[ordinal_green_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 4: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=96; k<120; k++)
                        {
                            cube4x4_color[ordinal_orange_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 5: for (j=0; j<16; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=120; k<144; k++)
                        {
                            cube4x4_color[ordinal_white_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            default: break;
        }
    }
}