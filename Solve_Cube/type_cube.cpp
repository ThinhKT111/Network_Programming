#include<iostream>
#include"type_cube.h"

using namespace std;


int Color_To_Int(char ch) {
    switch(ch)
    {
        case 'Y': return 0;
        case 'B': return 1;
        case 'R': return 2;
        case 'G': return 3;
        case 'O': return 4;
        case 'W': return 5;
        default: return -1;
    }
}

int Power_Two(int element){
    int i;
    int result = 1;
    for (i = 0; i<element; i++)
        result = result*2;
    return result;
}

StandardCube Cube_To_Standard(Cube bcube) {
    StandardCube result;
    int loconcer[6][4] = {
                            {1, 2, 3, 4},
                            {1, 4, 7, 8},
                            {4, 3, 6, 7},
                            {3, 2, 5, 6},
                            {2, 1, 8, 5},
                            {7, 6, 5, 8},
                        };
    int loedge[6][4] = {
                            {1, 2, 3, 4},
                            {4, 5, 12, 8}, 
                            {3, 6, 9, 5},
                            {2, 7, 10, 6},
                            {1, 8, 11, 7},
                            {9, 10, 11, 12},
                        };
    int i, j;
    for (i=0; i<8; i++)
    {
        result.concer[i] = 0;
    }
    for (j=0; j<12; j++)
    {
        result.edge[j] = 0;
    }
    for (i=0; i<6; i++)
    {
        for (j=0 ; j<8; j++)
        {
            if (j%2 == 0)
            {
                result.concer[loconcer[i][j/2]-1] += Power_Two(Color_To_Int(bcube.color[i][j]));
            }
            if (j%2 == 1)
            {
                result.edge[loedge[i][j/2]-1] += Power_Two(Color_To_Int(bcube.color[i][j]));
            }
        }
    }
    return result;
}

Cube Rotate_Clockwise(Cube bcube, int element) {
    Cube result = bcube;
    int arr[4][4]; 
    int i, j;
    for (i=0; i<6; i++)
    {
        result.color[element][i+2] = bcube.color[element][i];
    }
    result.color[element][0] = bcube.color[element][6];
    result.color[element][1] = bcube.color[element][7];
    switch(element)
    {
        case 0 :    arr[0][0] = 1; arr[1][0] = 4; arr[2][0] = 3; arr[3][0] = 2;
                    arr[0][1] = 2; arr[0][2] = 1; arr[0][3] = 0;
                    arr[1][1] = 2; arr[1][2] = 1; arr[1][3] = 0;
                    arr[2][1] = 2; arr[2][2] = 1; arr[2][3] = 0;
                    arr[3][1] = 2; arr[3][2] = 1; arr[3][3] = 0; break;
        case 1:     arr[0][0] = 0; arr[1][0] = 2; arr[2][0] = 5; arr[3][0] = 4;
                    arr[0][1] = 0; arr[0][2] = 7; arr[0][3] = 6;
                    arr[1][1] = 0; arr[1][2] = 7; arr[1][3] = 6;
                    arr[2][1] = 0; arr[2][2] = 7; arr[2][3] = 6;
                    arr[3][1] = 4; arr[3][2] = 3; arr[3][3] = 2; break;
        case 2 :    arr[0][0] = 0; arr[1][0] = 3; arr[2][0] = 5; arr[3][0] = 1;
                    arr[0][1] = 6; arr[0][2] = 5; arr[0][3] = 4;
                    arr[1][1] = 0; arr[1][2] = 7; arr[1][3] = 6;
                    arr[2][1] = 2; arr[2][2] = 1; arr[2][3] = 0;
                    arr[3][1] = 4; arr[3][2] = 3; arr[3][3] = 2; break;
        case 3:     arr[0][0] = 0; arr[1][0] = 4; arr[2][0] = 5; arr[3][0] = 2;
                    arr[0][1] = 4; arr[0][2] = 3; arr[0][3] = 2;
                    arr[1][1] = 0; arr[1][2] = 7; arr[1][3] = 6;
                    arr[2][1] = 4; arr[2][2] = 3; arr[2][3] = 2;
                    arr[3][1] = 4; arr[3][2] = 3; arr[3][3] = 2; break;
        case 4 :    arr[0][0] = 0; arr[1][0] = 1; arr[2][0] = 5; arr[3][0] = 3;
                    arr[0][1] = 2; arr[0][2] = 1; arr[0][3] = 0;
                    arr[1][1] = 0; arr[1][2] = 7; arr[1][3] = 6;
                    arr[2][1] = 6; arr[2][2] = 5; arr[2][3] = 4;
                    arr[3][1] = 4; arr[3][2] = 3; arr[3][3] = 2; break;
        case 5:     arr[0][0] = 1; arr[1][0] = 2; arr[2][0] = 3; arr[3][0] = 4;
                    arr[0][1] = 6; arr[0][2] = 5; arr[0][3] = 4;
                    arr[1][1] = 6; arr[1][2] = 5; arr[1][3] = 4;
                    arr[2][1] = 6; arr[2][2] = 5; arr[2][3] = 4;
                    arr[3][1] = 6; arr[3][2] = 5; arr[3][3] = 4; break;
    }
    for (i=1; i<4; i++)
    {
        result.color[arr[0][0]][arr[0][i]] = bcube.color[arr[3][0]][arr[3][i]];
        result.color[arr[1][0]][arr[1][i]] = bcube.color[arr[0][0]][arr[0][i]];
        result.color[arr[2][0]][arr[2][i]] = bcube.color[arr[1][0]][arr[1][i]];
        result.color[arr[3][0]][arr[3][i]] = bcube.color[arr[2][0]][arr[2][i]];
    }
    return result;
}

Cube Rotate_Anti_Clockwise(Cube bcube, int element) {
    Cube result = bcube;
    int arr[4][4]; 
    int i, j;
    for (i=0; i<6; i++)
    {
        result.color[element][i] = bcube.color[element][i+2];
    }
    result.color[element][6] = bcube.color[element][0];
    result.color[element][7] = bcube.color[element][1];
    switch(element)
    {
        case 0 :    arr[0][0] = 1; arr[1][0] = 2; arr[2][0] = 3; arr[3][0] = 4;
                    arr[0][1] = 0; arr[0][2] = 1; arr[0][3] = 2;
                    arr[1][1] = 0; arr[1][2] = 1; arr[1][3] = 2;
                    arr[2][1] = 0; arr[2][2] = 1; arr[2][3] = 2;
                    arr[3][1] = 0; arr[3][2] = 1; arr[3][3] = 2; break;
        case 1:     arr[0][0] = 0; arr[1][0] = 4; arr[2][0] = 5; arr[3][0] = 2;
                    arr[0][1] = 6; arr[0][2] = 7; arr[0][3] = 0;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 6; arr[2][2] = 7; arr[2][3] = 0;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 2 :    arr[0][0] = 0; arr[1][0] = 1; arr[2][0] = 5; arr[3][0] = 3;
                    arr[0][1] = 4; arr[0][2] = 5; arr[0][3] = 6;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 0; arr[2][2] = 1; arr[2][3] = 2;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 3:     arr[0][0] = 0; arr[1][0] = 2; arr[2][0] = 5; arr[3][0] = 4;
                    arr[0][1] = 2; arr[0][2] = 3; arr[0][3] = 4;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 2; arr[2][2] = 3; arr[2][3] = 4;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 4 :    arr[0][0] = 0; arr[1][0] = 3; arr[2][0] = 5; arr[3][0] = 1;
                    arr[0][1] = 0; arr[0][2] = 1; arr[0][3] = 2;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 4; arr[2][2] = 5; arr[2][3] = 6;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 5:     arr[0][0] = 1; arr[1][0] = 4; arr[2][0] = 3; arr[3][0] = 2;
                    arr[0][1] = 4; arr[0][2] = 5; arr[0][3] = 6;
                    arr[1][1] = 4; arr[1][2] = 5; arr[1][3] = 6;
                    arr[2][1] = 4; arr[2][2] = 5; arr[2][3] = 6;
                    arr[3][1] = 4; arr[3][2] = 5; arr[3][3] = 6; break;
    }
    for (i=1; i<4; i++)
    {
        result.color[arr[1][0]][arr[1][i]] = bcube.color[arr[0][0]][arr[0][i]];
        result.color[arr[2][0]][arr[2][i]] = bcube.color[arr[1][0]][arr[1][i]];
        result.color[arr[3][0]][arr[3][i]] = bcube.color[arr[2][0]][arr[2][i]];
        result.color[arr[0][0]][arr[0][i]] = bcube.color[arr[3][0]][arr[3][i]];
    }
    return result;
}



