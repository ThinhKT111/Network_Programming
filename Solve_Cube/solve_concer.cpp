#include<iostream>
#include"type_cube.h"
#include"method.h"
#include"solve_concer.h"

using namespace std;

int Find_Concer_Loop(Concer (&input_arr)[8][9], Cube original_Cube, Cube input_Cube)
{
    int i, j, k, local, start, total, row, col;
    char lcolor, check1, check2, other_lcolor, other_lcolor1;
    StandardCube original_StandardCube = Cube_To_Standard(original_Cube);
    StandardCube input_StandardCube = Cube_To_Standard(input_Cube);
    StandardCube check_StandardCube;
    Concer arr_Transfer_Concer[8] = {
        {0, 0, 1, 0, 4, 2},
        {0, 2, 4, 0, 3, 2},
        {0, 4, 2, 2, 3, 0},
        {0, 6, 1, 2, 2, 0},
        {5, 4, 4, 6, 3, 4},
        {5, 2, 2, 4, 3, 6},
        {5, 0, 2, 6, 1, 4},
        {5, 6, 4, 4, 1, 6}
    };

    //Initalixe the concer for check
    for (i=0; i<8; i++)
    {
        check_StandardCube.concer[i] = 0;
    }
    //Initalize the edge for check
    for (i=0; i<12; i++)
    {
        check_StandardCube.edge[i] = 0;
    }

    local = 0;
    start = input_StandardCube.concer[0];
    check_StandardCube.concer[0] = 0;
    lcolor = input_Cube.color[0][0];
    other_lcolor = input_Cube.color[1][0];
    other_lcolor1 = input_Cube.color[4][2];
    total = 1;
    row = 0; col = 0;
    while(total != 0)
    {
        if (check_StandardCube.concer[local] == 2)
        {
            for (i=0; i<8; i++)
            {
                if (check_StandardCube.concer[i] == 0)
                {
                    local = i; start = input_StandardCube.concer[local];
                    check_StandardCube.concer[local] = 0;
                    lcolor = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                    other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                    other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                    break;
                }
            }
            //cout << "helloworld\n";
        }
        col = 0;
        while(1)
        {
            //cout << lcolor << other_lcolor << other_lcolor1 << ' ';
            //cout << input_StandardCube.concer[local] << ' ';
            if (lcolor == input_Cube.color[arr_Transfer_Concer[local].c1_color][arr_Transfer_Concer[local].c1_location])
            {  
                input_arr[row][col].c1_color = arr_Transfer_Concer[local].c1_color;
                input_arr[row][col].c1_location = arr_Transfer_Concer[local].c1_location;
                if (other_lcolor == input_Cube.color[arr_Transfer_Concer[local].c2_color][arr_Transfer_Concer[local].c2_location])
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c2_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c2_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c3_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c3_location;
                }
                else 
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c3_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c3_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c2_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c2_location;
                }
            }
            else if (lcolor == input_Cube.color[arr_Transfer_Concer[local].c2_color][arr_Transfer_Concer[local].c2_location])
            {
                input_arr[row][col].c1_color = arr_Transfer_Concer[local].c2_color;
                input_arr[row][col].c1_location = arr_Transfer_Concer[local].c2_location;
                if (other_lcolor == input_Cube.color[arr_Transfer_Concer[local].c1_color][arr_Transfer_Concer[local].c1_location])
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c1_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c1_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c3_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c3_location;
                }
                else 
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c3_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c3_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c1_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c1_location;
                }
            }
            else if (lcolor == input_Cube.color[arr_Transfer_Concer[local].c3_color][arr_Transfer_Concer[local].c3_location])
            {
                input_arr[row][col].c1_color = arr_Transfer_Concer[local].c3_color;
                input_arr[row][col].c1_location = arr_Transfer_Concer[local].c3_location;
                if (other_lcolor == input_Cube.color[arr_Transfer_Concer[local].c1_color][arr_Transfer_Concer[local].c1_location])
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c1_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c1_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c2_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c2_location;
                }
                else 
                {
                    input_arr[row][col].c2_color = arr_Transfer_Concer[local].c2_color;
                    input_arr[row][col].c2_location = arr_Transfer_Concer[local].c2_location;
                    input_arr[row][col].c3_color = arr_Transfer_Concer[local].c1_color;
                    input_arr[row][col].c3_location = arr_Transfer_Concer[local].c1_location;
                }
            }
            // cout << input_arr[row][col].c1_color << input_arr[row][col].c1_location;
            // cout << input_arr[row][col].c2_color << input_arr[row][col].c2_location;
            // cout << input_arr[row][col].c3_color << input_arr[row][col].c3_location << ' ';
            col++;
            

            for (i=0; i<12; i++)
            {
                if (check_StandardCube.concer[i] < 2 && input_StandardCube.concer[local] == original_StandardCube.concer[i])
                {
                    // cout << lcolor << other_lcolor << other_lcolor1;
                    // cout << original_StandardCube.concer[i];
                    
                    
                    check1 = original_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                    check2 = original_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];

                    //cout << check1 << check2 << original_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location] << ' ';
                    if (check1 == lcolor)
                    {
                        lcolor = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                        if (check2 == other_lcolor)
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                        }
                        else
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                        }
                    }
                    else if (lcolor == check2)
                    {
                        lcolor = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                        if (check1 == other_lcolor)
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                        }
                        else
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                        }
                    }
                    else
                    {
                        lcolor = input_Cube.color[arr_Transfer_Concer[i].c3_color][arr_Transfer_Concer[i].c3_location];
                        if (check1 == other_lcolor)
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                        }
                        else
                        {
                            other_lcolor = input_Cube.color[arr_Transfer_Concer[i].c2_color][arr_Transfer_Concer[i].c2_location];
                            other_lcolor1 = input_Cube.color[arr_Transfer_Concer[i].c1_color][arr_Transfer_Concer[i].c1_location];
                        }
                    }
                    check_StandardCube.concer[i]++;
                    local = i;
                    break;
                }
            }
            if (check_StandardCube.concer[local] == 2)
            {
                break;
            }
        }
        //cout << '\n';
        input_arr[row][col].c1_color = -1;
        input_arr[row][col].c2_color = -1;
        input_arr[row][col].c3_color = -1;
        input_arr[row][col].c1_location = -1;
        input_arr[row][col].c2_location = -1;
        input_arr[row][col].c3_location = -1;
        row++;

        for (i=0; i<8; i++)
        {
            if (check_StandardCube.concer[i] == 0)
            {
                total = 1; break;
            }
            total = 0;
        }
    }
    return row;
}

int Apply_Case_Concer(Concer input_case, StepConcer (&pre), StepConcer (&after), int (&num))
{
    int input[6];
    input[0] = input_case.c1_color;
    input[1] = input_case.c1_location;
    input[2] = input_case.c2_color;
    input[3] = input_case.c2_location;
    input[4] = input_case.c3_color;
    input[5] = input_case.c3_location;
    int compare[48][6] = {
        {0, 0, 1, 0, 4, 2}, {0, 0, 4, 2, 1, 0},
        {1, 0, 0, 0, 4, 2}, {1, 0, 4, 2, 0, 0},
        {4, 2, 0, 0, 1, 0}, {4, 2, 1, 0, 0, 0}, //YBO

        {0, 2, 4, 0, 3, 2}, {0, 2, 3, 2, 4, 0},
        {4, 0, 0, 2, 3, 2}, {4, 0, 3, 2, 0, 2},
        {3, 2, 0, 2, 4, 0}, {3, 2, 4, 0, 0, 2}, //YOG

        {0, 4, 2, 2, 3, 0}, {0, 4, 3, 0, 2, 2},
        {2, 2, 0, 4, 3, 0}, {2, 2, 3, 0, 0, 4},
        {3, 0, 2, 2, 0, 4}, {3, 0, 0, 4, 2, 2}, //YRG

        {0, 6, 1, 2, 2, 0}, {0, 6, 2, 0, 1, 2},
        {1, 2, 0, 6, 2, 0}, {1, 2, 2, 0, 0, 6},
        {2, 0, 0, 6, 1, 2}, {2, 0, 1, 2, 0, 6}, //YBR

        {5, 4, 4, 6, 3, 4}, {5, 4, 3, 4, 4, 6}, 
        {4, 6, 5, 4, 3, 4}, {4, 6, 3, 4, 5, 4},
        {3, 4, 5, 4, 4, 6}, {3, 4, 4, 6, 5, 4}, //WOG

        {5, 2, 2, 4, 3, 6}, {5, 2, 3, 6, 2, 4},
        {2, 4, 5, 2, 3, 6}, {2, 4, 3, 6, 5, 2},
        {3, 6, 5, 2, 2, 4}, {3, 6, 2, 4, 5, 2}, //WRG

        {5, 0, 2, 6, 1, 4}, {5, 0, 1, 4, 2, 6},
        {2, 6, 5, 0, 1, 4}, {2, 6, 1, 4, 5, 0},
        {1, 4, 5, 0, 2, 6}, {1, 4, 2, 6, 5, 0}, //WRB

        {5, 6, 4, 4, 1, 6}, {5, 6, 1, 6, 4, 4},
        {4, 4, 5, 6, 1, 6}, {4, 4, 1, 6, 5, 6},
        {1, 6, 5, 6, 4, 4}, {1, 6, 4, 4, 5, 6} //WOB
    };

    int status, i;
    for (i=0; i<48; i++)
    {
        if (input[0] == compare[i][0] && input[1] == compare[i][1]
             && input[2] == compare[i][2] && input[3] == compare[i][3]
             && input[4] == compare[i][4] && input[5] == compare[i][5])
        {
            status = i; break;
        }
    }
    for (i=0; i<3; i++)
    {
        pre.location[i] = -1;
        pre.type[i] = -1;
        after.location[i] = -1;
        after.type[i] = -1;
        num = 0;
    }
    switch(status)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5: break;
        case 6:

        case 7: num = 3;    pre.location[0] = 3; pre.type[0] = 2;
                            pre.location[1] = 5; pre.type[1] = 1;
                            pre.location[2] = 3; pre.type[2] = 2;
                            after.location[0] = 3; after.type[0] = 2;
                            after.location[1] = 5; after.type[1] = -1;
                            after.location[2] = 3; after.type[2] = 2; return 4;
        case 8: 
        case 9: num = 1;    pre.location[0] = 3; pre.type[0] = -1;
                            after.location[0] = 3; after.type[0] = 1; return 4;
        case 10: 
        case 11: num = 2;   pre.location[0] = 3; pre.type[0] = 2;
                            pre.location[1] = 2; pre.type[1] = -1;
                            after.location[0] = 2; after.type[0] = 1;
                            after.location[1] = 3; after.type[1] = 2; return 4;

        case 12: 
        case 13: num = 0; return 4;
        case 14:
        case 15: num = 2;   pre.location[0] = 2; pre.type[0] = 1;
                            pre.location[1] = 3; pre.type[1] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 2; after.type[1] = -1; return 4;
        case 16:
        case 17: num = 2;   pre.location[0] = 3; pre.type[0] = -1;
                            pre.location[1] = 2; pre.type[1] = -1;
                            after.location[0] = 2; after.type[0] = 1;
                            after.location[1] = 3; after.type[1] = 1; return 4;

        case 18:
        case 19: num = 3;   pre.location[0] = 2; pre.type[0] = -1;
                            pre.location[1] = 5; pre.type[1] = 1;
                            pre.location[2] = 3; pre.type[2] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 5; after.type[1] = -1;
                            after.location[2] = 2; after.type[2] = 1; return 4;
        case 20:
        case 21: num = 1;   pre.location[0] = 2; pre.type[0] = 1;
                            after.location[0] = 2; after.type[0] = -1; return 4;
        case 22:
        case 23: num = 2;   pre.location[0] = 2; pre.type[0] = 2;
                            pre.location[1] = 3; pre.type[1] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 2; after.type[1] = 2; return 4;

        case 24:
        case 25: num = 1;   pre.location[0] = 3; pre.type[0] = 2;
                            after.location[0] = 3; after.type[0] = 2; return 4;
        case 26: 
        case 27: num = 2;   pre.location[0] = 5; pre.type[0] = -1;
                            pre.location[1] = 2; pre.type[1] = -1;
                            after.location[0] = 2; after.type[0] = 1;
                            after.location[1] = 5; after.type[1] = 1; return 4;
        case 28:
        case 29: num = 2;   pre.location[0] = 5; pre.type[0] = -1;
                            pre.location[1] = 3; pre.type[1] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 5; after.type[1] = 1; return 4;

        case 30:
        case 31: num = 2;   pre.location[0] = 5; pre.type[0] = 1;
                            pre.location[1] = 3; pre.type[1] = 2;
                            after.location[0] = 3; after.type[0] = 2;
                            after.location[1] = 5; after.type[1] = -1; return 4;
        case 32:
        case 33: num = 1;   pre.location[0] = 3; pre.type[0] = 1;
                            after.location[0] = 3; after.type[0] = -1; return 4;
        case 34:
        case 35: num = 1;   pre.location[0] = 2; pre.type[0] = -1;
                            after.location[0] = 2; after.type[0] = 1; return 4;

        case 36:
        case 37: num = 1;   pre.location[0] = 2; pre.type[0] = 2;
                            after.location[0] = 2; after.type[0] = 2; return 4;
        case 38:
        case 39: num = 2;   pre.location[0] = 5; pre.type[0] = 1;
                            pre.location[1] = 2; pre.type[1] = -1;
                            after.location[0] = 2; after.type[0] = 1;
                            after.location[1] = 5; after.type[1] = -1; return 4;
        case 40:
        case 41: num = 2;   pre.location[0] = 5; pre.type[0] = 1;
                            pre.location[1] = 3; pre.type[1] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 5; after.type[1] = -1; return 4;

        case 42: 
        case 43: num = 2;   pre.location[0] = 5; pre.type[0] = -1;
                            pre.location[1] = 3; pre.type[1] = 2;
                            after.location[0] = 3; after.type[0] = 2;
                            after.location[1] = 5; after.type[1] = 1; return 4;
        case 44:
        case 45: num = 2;   pre.location[0] = 5; pre.type[0] = 2;
                            pre.location[1] = 3; pre.type[1] = 1;
                            after.location[0] = 3; after.type[0] = -1;
                            after.location[1] = 5; after.type[1] = 2; return 4;
        case 46:
        case 47: num = 2;   pre.location[0] = 5; pre.type[0] = 2;
                            pre.location[1] = 2; pre.type[1] = -1;
                            after.location[0] = 2; after.type[0] = 1;
                            after.location[1] = 5; after.type[1] = 2; return 4;
        
    }
    return 0;
}