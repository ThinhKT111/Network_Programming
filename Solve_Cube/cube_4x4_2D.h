// type_cube.h
#ifndef TYPE_CUBE_4X4_H
#define TYPE_CUBE_4X4_H

struct Cube4X4 {
    char color[6][16];
};

Cube4X4 Rotate_Small_Clockwise_4X4(Cube4X4 bcube, int element);
Cube4X4 Rotate_Big_Clockwise_4X4(Cube4X4 bcube, int element);
Cube4X4 Rotate_Small_Anti_Clockwise_4X4(Cube4X4 bcube, int element);
Cube4X4 Rotate_Big_Anti_Clockwise_4X4(Cube4X4 bcube, int element);

#endif // TYPE_CUBE_H