#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"
#include "type_cube_5X5.h"
#include "../../Solve_Cube/cube_5x5_2D.h"

using namespace std;

GLfloat range_of_center_5X5 = 25.f;
GLfloat length_cube_5X5 = 11.5f;

GLfloat center_location_5X5[125][3];

void init_center_location_5X5()
{
    int i, j;
    for (i=0; i<125; i++)
    {
        //Ox
        switch ((i%25)%5)
        {
            case 0: center_location_5X5[i][0] = 2.f * -range_of_center_5X5; break;
            case 1: center_location_5X5[i][0] = 1.f * -range_of_center_5X5; break;
            case 2: center_location_5X5[i][0] = 0.f * range_of_center_5X5; break;
            case 3: center_location_5X5[i][0] = 1.f * range_of_center_5X5; break;
            default: center_location_5X5[i][0] = 2.f * range_of_center_5X5; break;
        }     

        //Oz
        if ((i%25) >=0 && (i%25) < 5)
        {
            center_location_5X5[i][2] = 2.f * -range_of_center_5X5;
        }
        else if ((i%25) >=5 && (i%25) < 10)
        {
            center_location_5X5[i][2] = 1.f * -range_of_center_5X5;
        }
        else if ((i%25) >=10 && (i%25) < 15)
        {
            center_location_5X5[i][2] = 0.f * range_of_center_5X5;
        }
        else if ((i%25) >=15 && (i%25) < 20)
        {
            center_location_5X5[i][2] = 1.f * range_of_center_5X5;
        }
        else
        {
            center_location_5X5[i][2] = 2.f * range_of_center_5X5;
        }

        //Oy
        if (i < 25)
        {
            center_location_5X5[i][1] = 2.f * range_of_center_5X5;
        }
        else if (i >= 25 && i < 50)
        {
            center_location_5X5[i][1] = 1.f * range_of_center_5X5;
        }
        else if (i >= 50 && i < 75)
        {
            center_location_5X5[i][1] = 0.f * range_of_center_5X5;
        }
        else if (i >= 75 && i < 100)
        {
            center_location_5X5[i][1] = 1.f * -range_of_center_5X5;
        }
        else
        {
            center_location_5X5[i][1] = 2.f * -range_of_center_5X5;
        }
    }
}

void init_cube5X5_location(GLfloat cube5X5_location[125][108])
{
    int i, j;

    init_center_location_5X5();

    for (i=0; i<125; i++)
    {
        for (j=0; j<108; j++)
        {
            cube5X5_location[i][j] = center_location_5X5[i][j%3] + (cube[j%3 + 7*(j/3)]*length_cube_5X5)/23;
        }
    }
}

void init_cube5X5_color(GLfloat cube5X5_color[125][144])
{
    int i, j;
    for (i=0; i<125; i++)
    {
        if (i<25)
        {
            for (j=0; j<24; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // yellow
        }
        else if (i>=100)
        {
            for (j=120; j<144; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // white
        }
        if (i%5 == 0)
        {
            for (j=24; j<48; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // blue
        }
        else if (i%5 == 4)
        {
            for (j=72; j<96; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // green
        }
        if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 ||
            i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || 
            i == 50 || i == 51 || i == 52 || i == 53 || i == 54 ||
            i == 75 || i == 76 || i == 77 || i == 78 || i == 79 ||
            i == 100 || i == 101 || i == 102 || i == 103 || i == 104)
        {
            for (j=96; j<120; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // orange
        }
        else if (i == 20 || i == 21 || i == 22 || i == 23 || i == 24 ||
                 i == 45 || i == 46 || i == 47 || i == 48 || i == 49 ||
                 i == 70 || i == 71 || i == 72 || i == 73 || i == 74 ||
                 i == 95 || i == 96 || i == 97 || i == 98 || i == 99 ||
                 i == 120 || i == 121 || i == 122 || i == 123 || i == 124)
        {
            for (j=48; j<72; j++)
                cube5X5_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // red
        }
    }
}

void Spray_Cube_5X5(GLfloat cube5x5_color[125][144], Cube5X5 bcube)
{
    int i, j, k;
    
    GLfloat color3D[4];

    int ordinal_yellow_face[25] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    int ordinal_blue_face[25] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120};
    int ordinal_red_face[25] = {20, 21, 22, 23, 24, 45, 46, 47, 48, 49, 70, 71, 72, 73, 74, 95, 96, 97, 98, 99, 120, 121, 122, 123, 124};
    int ordinal_green_face[25] = {24, 19, 14, 9, 4, 49, 44, 39, 34, 29, 74, 69, 64, 59, 54, 99, 94, 89, 84, 79, 124, 119, 114, 109, 104};
    int ordinal_orange_face[25] = {4, 3, 2, 1, 0, 29, 28, 27, 26, 25, 54, 53, 52, 51, 50, 79, 78, 77, 76, 75, 104, 103, 102, 101, 100};
    int ordinal_white_face[25] = {120, 121, 122, 123, 124, 115, 116, 117, 118, 119, 110, 111, 112, 113, 114, 105, 106, 107, 108, 109, 100, 101, 102, 103, 104};

    for (i=0; i<6; i++)
    {
        switch(i)
        {
            case 0: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=0; k<24; k++)
                        {
                            cube5x5_color[ordinal_yellow_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 1: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=24; k<48; k++)
                        {
                            cube5x5_color[ordinal_blue_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 2: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=48; k<72; k++)
                        {
                            cube5x5_color[ordinal_red_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 3: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=72; k<96; k++)
                        {
                            cube5x5_color[ordinal_green_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 4: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=96; k<120; k++)
                        {
                            cube5x5_color[ordinal_orange_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 5: for (j=0; j<25; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=120; k<144; k++)
                        {
                            cube5x5_color[ordinal_white_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            default: break;
        }
    }
}