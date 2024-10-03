// type_cube_5x5.h
#ifndef TYPE_CUBE_5X5_H
#define TYPE_CUBE_5X5_H

struct Cube5X5 {
    char color[6][25];
};

Cube5X5 Rotate_Small_Clockwise_5X5(Cube5X5 bcube, int element);
Cube5X5 Rotate_Big_Clockwise_5X5(Cube5X5 bcube, int element);
Cube5X5 Rotate_Small_Anti_Clockwise_5X5(Cube5X5 bcube, int element);
Cube5X5 Rotate_Big_Anti_Clockwise_5X5(Cube5X5 bcube, int element);

#endif // TYPE_CUBE_5x5_H