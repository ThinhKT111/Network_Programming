#include<iostream>
#include"type_cube.h"
#include"method.h"

using namespace std;

//Choose yellow and green is the main edge 

Cube Pll_Ja(Cube bcube) {
    Cube result = bcube;

    result.color[0][1] = bcube.color[0][3];
    result.color[0][3] = bcube.color[0][1];
    result.color[4][1] = bcube.color[3][1];
    result.color[3][1] = bcube.color[4][1];

    result.color[0][2] = bcube.color[0][4];
    result.color[0][4] = bcube.color[0][2];
    result.color[4][0] = bcube.color[3][0];
    result.color[3][0] = bcube.color[4][0];
    result.color[3][2] = bcube.color[2][2];
    result.color[2][2] = bcube.color[3][2];
    return result;
}

Cube Pll_Jb(Cube bcube) {
    Cube result = bcube;

    result.color[0][5] = bcube.color[0][3];
    result.color[0][3] = bcube.color[0][5];
    result.color[2][1] = bcube.color[3][1];
    result.color[3][1] = bcube.color[2][1];

    result.color[0][2] = bcube.color[0][4];
    result.color[0][4] = bcube.color[0][2];
    result.color[4][0] = bcube.color[3][0];
    result.color[3][0] = bcube.color[4][0];
    result.color[3][2] = bcube.color[2][2];
    result.color[2][2] = bcube.color[3][2];
    return result;
}

Cube Pll_T(Cube bcube) {
    Cube result = bcube;

    result.color[0][7] = bcube.color[0][3];
    result.color[0][3] = bcube.color[0][7];
    result.color[1][1] = bcube.color[3][1];
    result.color[3][1] = bcube.color[1][1];

    result.color[0][2] = bcube.color[0][4];
    result.color[0][4] = bcube.color[0][2];
    result.color[4][0] = bcube.color[3][0];
    result.color[3][0] = bcube.color[4][0];
    result.color[3][2] = bcube.color[2][2];
    result.color[2][2] = bcube.color[3][2];
    return result;
}

//Choose Yellow Blue Orange is the main concer

Cube Pll_Y(Cube bcube) {
    Cube result = bcube;

    result.color[0][1] = bcube.color[0][7];
    result.color[0][7] = bcube.color[0][1];
    result.color[4][1] = bcube.color[1][1];
    result.color[1][1] = bcube.color[4][1];

    result.color[0][0] = bcube.color[0][4];
    result.color[0][4] = bcube.color[0][0];
    result.color[1][0] = bcube.color[3][0];
    result.color[3][0] = bcube.color[1][0];
    result.color[4][2] = bcube.color[2][2];
    result.color[2][2] = bcube.color[4][2];
    return result;
}