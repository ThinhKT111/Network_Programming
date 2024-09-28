// type_cube.h
#ifndef TYPE_CUBE_H
#define TYPE_CUBE_H

struct Cube {
    char color[6][8];
};

struct StandardCube {
    int concer[8];
    int edge[12];
};

struct Edge {
    int c1_color;
    int c1_location;
    int c2_color;
    int c2_location;
};

struct Concer {
    int c1_color;
    int c1_location;
    int c2_color;
    int c2_location;
    int c3_color;
    int c3_location;
};

struct Step {
   int position; //2: Double, 1: ClockWise, -1: Anti
   int status; 
   /*status =  {0: UP, 1: LEFT, 2: FRONT,
                3: RIGHT, 4: BEHIND, 5: DOWN}*/
};

int Color_To_Int(char ch);
int Power_Two(int element);
StandardCube Cube_To_Standard(Cube bcube);
Cube Rotate_Clockwise(Cube bcube, int element);
Cube Rotate_Anti_Clockwise(Cube bcube, int element);

#endif // TYPE_CUBE_H