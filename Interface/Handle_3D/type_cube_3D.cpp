#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"

#include "../../Solve_Cube/type_cube.h"

using namespace std;

GLfloat range_of_center = 50.f;
GLfloat length_cube = 23.f;

GLfloat center_location[27][3] = {
    {-range_of_center, range_of_center, -range_of_center},
    {0, range_of_center, -range_of_center},
    {range_of_center, range_of_center, -range_of_center},
    {-range_of_center, range_of_center, 0},
    {0, range_of_center, 0},
    {range_of_center, range_of_center, 0},
    {-range_of_center, range_of_center, range_of_center},
    {0, range_of_center, range_of_center},
    {range_of_center, range_of_center, range_of_center},

    {-range_of_center, 0, -range_of_center},
    {0, 0, -range_of_center},
    {range_of_center, 0, -range_of_center},
    {-range_of_center, 0, 0},
    {0, 0, 0},
    {range_of_center, 0, 0},
    {-range_of_center, 0, range_of_center},
    {0, 0, range_of_center},
    {range_of_center, 0, range_of_center},

    {-range_of_center, -range_of_center, -range_of_center},
    {0, -range_of_center, -range_of_center},
    {range_of_center, -range_of_center, -range_of_center},
    {-range_of_center, -range_of_center, 0},
    {0, -range_of_center, 0},
    {range_of_center, -range_of_center, 0},
    {-range_of_center, -range_of_center, range_of_center},
    {0, -range_of_center, range_of_center},
    {range_of_center, -range_of_center, range_of_center}
};

// Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
GLfloat cube[] =
{
    // positions       // colors (r, g, b, a)
    -length_cube,  length_cube, -length_cube,  1, 1, 0, 1, // yellow
    length_cube,  length_cube, -length_cube,  1, 1, 0, 1, // yellow
    -length_cube,  length_cube,  length_cube,  1, 1, 0, 1, // yellow
    -length_cube,  length_cube,  length_cube,  1, 1, 0, 1, // yellow
    length_cube,  length_cube, -length_cube,  1, 1, 0, 1, // yellow
    length_cube,  length_cube,  length_cube,  1, 1, 0, 1, // yellow

    -length_cube, -length_cube, -length_cube,  0, 0, 1, 1, // blue
    -length_cube,  length_cube, -length_cube,  0, 0, 1, 1, // blue
    -length_cube, -length_cube,  length_cube,  0, 0, 1, 1, // blue
    -length_cube, -length_cube,  length_cube,  0, 0, 1, 1, // blue
    -length_cube,  length_cube, -length_cube,  0, 0, 1, 1, // blue
    -length_cube,  length_cube,  length_cube,  0, 0, 1, 1, // blue

    -length_cube, -length_cube,  length_cube,  1, 0, 0, 1, // red
    length_cube, -length_cube,  length_cube,  1, 0, 0, 1, // red
    -length_cube,  length_cube,  length_cube,  1, 0, 0, 1, // red
    -length_cube,  length_cube,  length_cube,  1, 0, 0, 1, // red
    length_cube, -length_cube,  length_cube,  1, 0, 0, 1, // red
    length_cube,  length_cube,  length_cube,  1, 0, 0, 1, // red

    length_cube, -length_cube, -length_cube,  0, 1, 0, 1, // green
    length_cube,  length_cube, -length_cube,  0, 1, 0, 1, // green
    length_cube, -length_cube,  length_cube,  0, 1, 0, 1, // green
    length_cube, -length_cube,  length_cube,  0, 1, 0, 1, // green
    length_cube,  length_cube, -length_cube,  0, 1, 0, 1, // green
    length_cube,  length_cube,  length_cube,  0, 1, 0, 1, // green

    -length_cube, -length_cube, -length_cube,  1, 0.45, 0, 1, // orange
    length_cube, -length_cube, -length_cube,  1, 0.45, 0, 1, // orange
    -length_cube,  length_cube, -length_cube,  1, 0.45, 0, 1, // orange
    -length_cube,  length_cube, -length_cube,  1, 0.45, 0, 1, // orange
    length_cube, -length_cube, -length_cube,  1, 0.45, 0, 1, // orange
    length_cube,  length_cube, -length_cube,  1, 0.45, 0, 1, // orange

    -length_cube, -length_cube, -length_cube,  1, 1, 1, 1, // white
    length_cube, -length_cube, -length_cube,  1, 1, 1, 1, // white
    -length_cube, -length_cube,  length_cube,  1, 1, 1, 1, // white
    -length_cube, -length_cube,  length_cube,  1, 1, 1, 1, // white
    length_cube, -length_cube, -length_cube,  1, 1, 1, 1, // white
    length_cube, -length_cube,  length_cube,  1, 1, 1, 1, // white
};

void init_cube3x3_location(GLfloat cube3X3_location[27][108])
{
    int i, j;
    for (i=0; i<27; i++)
    {
        for (j=0; j<108; j++)
        {
            cube3X3_location[i][j] = center_location[i][j%3] + cube[j%3 + 7*(j/3)];
        }
    }
}

void init_cube3x3_color(GLfloat cube3x3_color[27][144])
{
    int i, j;
    for (i=0; i<27; i++)
    {
        if (i<9)
        {
            for (j=0; j<24; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // yellow
        }
        else if (i>=18)
        {
            for (j=120; j<144; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // white
        }
        if (i%3 == 0)
        {
            for (j=24; j<48; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // blue
        }
        else if (i%3 == 2)
        {
            for (j=72; j<96; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // green
        }
        if (i == 0 || i == 1 || i == 2 || i == 9 || i == 10 || i == 11 || i == 18 || i == 19 || i == 20)
        {
            for (j=96; j<120; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; // orange
        }
        else if (i == 6 || i == 7 || i == 8 || i == 15 || i == 16 || i == 17 || i == 24 || i == 25 || i == 26)
        {
            for (j=48; j<72; j++)
                cube3x3_color[i][j] = cube[j%4 + 7*(j/4) + 3]; //red
        }
    }
}

void Transfer_3D_Color(char color, GLfloat color3D[4])
{
    color3D[3] = 1;
    switch (color)
    {
        case 'Y': color3D[0] = 1; color3D[1] = 1; color3D[2] = 0; break; // yellow
        case 'B': color3D[0] = 0; color3D[1] = 0; color3D[2] = 1; break; // blue
        case 'R': color3D[0] = 1; color3D[1] = 0; color3D[2] = 0; break; // red
        case 'G': color3D[0] = 0; color3D[1] = 1; color3D[2] = 0; break; // green
        case 'O': color3D[0] = 1; color3D[1] = 0.45; color3D[2] = 0; break; // orange
        case 'W': color3D[0] = 1; color3D[1] = 1; color3D[2] = 1; break; // white
        default: break;
    }
}

void Spray_Cube3D(GLfloat cube3x3_color[27][144], Cube bcube)
{
    int i, j, k;
    GLfloat color3D[4];
    int ordinal_yellow_face[8] = {0, 1, 2, 5, 8, 7, 6, 3};
    int ordinal_blue_face[8] = {0, 3, 6, 15, 24, 21, 18, 9};
    int ordinal_red_face[8] = {6, 7, 8, 17, 26, 25, 24, 15};
    int ordinal_green_face[8] = {8, 5, 2, 11, 20, 23, 26, 17};
    int ordinal_orange_face[8] = {2, 1, 0, 9, 18, 19, 20, 11};
    int ordinal_white_face[8] = {24, 25, 26, 23, 20, 19, 18, 21};
    for (i=0; i<6; i++)
    {
        switch(i)
        {
            case 0: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=0; k<24; k++)
                        {
                            cube3x3_color[ordinal_yellow_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 1: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=24; k<48; k++)
                        {
                            cube3x3_color[ordinal_blue_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 2: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=48; k<72; k++)
                        {
                            cube3x3_color[ordinal_red_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 3: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=72; k<96; k++)
                        {
                            cube3x3_color[ordinal_green_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 4: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=96; k<120; k++)
                        {
                            cube3x3_color[ordinal_orange_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
            case 5: for (j=0; j<8; j++)
                    {
                        Transfer_3D_Color(bcube.color[i][j], color3D);
                        for (k=120; k<144; k++)
                        {
                            cube3x3_color[ordinal_white_face[j]][k] = color3D[k%4];
                        }
                    }
                    break;
        }
    }
}