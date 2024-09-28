#include<iostream>
#include"type_cube.h"
#include"method.h"
#include"solve_edge.h"
#include<stdio.h>
#include"solve_concer.h"

using namespace std;

Cube original_Cube = {
    {
        {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
        {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
    }
};
Cube input_Cube, check_input_Cube;

StandardCube original_StandardCube = Cube_To_Standard(original_Cube);
StandardCube input_StandardCube;

Edge arr[12][13];
Concer arr1[8][9];
StepEdge pre_edge, after_edge;
StepConcer pre_concer, after_concer;
int num_step_edge, num_step_concer;
int type_method;

int main() {
    int i, j;
    int num_arr_row, num_arr_col;
    int num_arr1_row, num_arr1_col;
    freopen("test_case/testcase4.txt", "r", stdin);
    for (i=0; i<6; i++)
    {
        for (j=0; j<8; j++)
        {
            cin >> input_Cube.color[i][j];
            check_input_Cube.color[i][j] = input_Cube.color[i][j];
        }
    }
    input_StandardCube = Cube_To_Standard(input_Cube);
    

    num_arr_row = Find_Edge_Loop(arr, original_Cube, input_Cube);

    for (i=0; i<num_arr_row; i++)
    {
        num_arr_col = 0;
        while (arr[i][num_arr_col].c1_color != -1)
        {
            cout << input_Cube.color[arr[i][num_arr_col].c1_color][arr[i][num_arr_col].c1_location];
            cout << input_Cube.color[arr[i][num_arr_col].c2_color][arr[i][num_arr_col].c2_location] << ' ';
            num_arr_col++;
        }
        cout << '\n';
    }

    for (i=0; i<num_arr_row; i++)
    {
        num_arr_col = 0;
        while (arr[i][num_arr_col].c1_color != -1)
        {
            // cout << input_Cube.color[arr[i][num_arr_col].c1_color][arr[i][num_arr_col].c1_location];
            // cout << input_Cube.color[arr[i][num_arr_col].c2_color][arr[i][num_arr_col].c2_location] << '\n';
            // cout << arr[i][num_arr_col].c1_color << " " << arr[i][num_arr_col].c1_location << " ";
            // cout << arr[i][num_arr_col].c2_color << " " << arr[i][num_arr_col].c2_location << "\n";

            
            type_method = Apply_Case_Edge(arr[i][num_arr_col], pre_edge, after_edge, num_step_edge);
            // cout << type_method << "\n";
            for (j=0; j<num_step_edge; j++)
            {
                // cout << pre_edge.location[j] << pre_edge.type[j] << '\n';
                // cout << after_edge.location[j] << after_edge.type[j] << '\n';
                if (pre_edge.type[j] == 1)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, pre_edge.location[j]);
                }
                else if (pre_edge.type[j] == 2)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, pre_edge.location[j]);
                    input_Cube = Rotate_Clockwise(input_Cube, pre_edge.location[j]);
                }
                else
                {
                    input_Cube = Rotate_Anti_Clockwise(input_Cube, pre_edge.location[j]);
                }
            }
            switch (type_method)
            {
                case 0: break;
                case 1: input_Cube = Pll_Ja(input_Cube); break;
                case 2: input_Cube = Pll_Jb(input_Cube); break;
                case 3: input_Cube = Pll_T(input_Cube); break;
            }
            for (j=0; j<num_step_edge; j++)
            {
                // cout << pre_edge.location[j] << pre_edge.type[j] << '\n';
                // cout << after_edge.location[j] << after_edge.type[j] << '\n';
                if (after_edge.type[j] == 1)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, after_edge.location[j]);
                }
                else if (after_edge.type[j] == 2)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, after_edge.location[j]);
                    input_Cube = Rotate_Clockwise(input_Cube, after_edge.location[j]);
                }
                else
                {
                    input_Cube = Rotate_Anti_Clockwise(input_Cube, after_edge.location[j]);
                }
            }
            //cout << "hello world\n";
            num_arr_col++;
        }
        //cout << '\n';
    }



    //cout << "Hello world";


    cout << '\n';
    num_arr1_row = Find_Concer_Loop(arr1, original_Cube, input_Cube);

    for (i=0; i<num_arr1_row; i++)
    {
        num_arr1_col = 0;
        while (arr1[i][num_arr1_col].c1_color != -1)
        {
            cout << input_Cube.color[arr1[i][num_arr1_col].c1_color][arr1[i][num_arr1_col].c1_location];
            cout << input_Cube.color[arr1[i][num_arr1_col].c2_color][arr1[i][num_arr1_col].c2_location];
            cout << input_Cube.color[arr1[i][num_arr1_col].c3_color][arr1[i][num_arr1_col].c3_location] << ' ';
            num_arr1_col++;
        }
        cout << '\n';
    }
    for (i=0; i<num_arr1_row; i++)
    {
        num_arr1_col = 0;
        while (arr1[i][num_arr1_col].c1_color != -1)
        {
            // cout << input_Cube.color[arr1[i][num_arr1_col].c1_color][arr1[i][num_arr1_col].c1_location];
            // cout << input_Cube.color[arr1[i][num_arr1_col].c2_color][arr1[i][num_arr1_col].c2_location];
            // cout << input_Cube.color[arr1[i][num_arr1_col].c3_color][arr1[i][num_arr1_col].c3_location] << ' ';
            // cout << arr[i][num_arr_col].c1_color << " " << arr[i][num_arr_col].c1_location << " ";
            // cout << arr[i][num_arr_col].c2_color << " " << arr[i][num_arr_col].c2_location << "\n";
            
            
            type_method = Apply_Case_Concer(arr1[i][num_arr1_col], pre_concer, after_concer, num_step_concer);
            // cout << type_method << "\n";
            for (j=0; j<num_step_concer; j++)
            {
                // cout << pre_edge.location[j] << pre_edge.type[j] << '\n';
                // cout << after_edge.location[j] << after_edge.type[j] << '\n';
                if (pre_concer.type[j] == 1)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, pre_concer.location[j]);
                }
                else if (pre_concer.type[j] == 2)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, pre_concer.location[j]);
                    input_Cube = Rotate_Clockwise(input_Cube, pre_concer.location[j]);
                }
                else
                {
                    input_Cube = Rotate_Anti_Clockwise(input_Cube, pre_concer.location[j]);
                }
            }
            switch (type_method)
            {
                case 4: input_Cube = Pll_Y(input_Cube);
            }
            for (j=0; j<num_step_concer; j++)
            {
                // cout << pre_edge.location[j] << pre_edge.type[j] << '\n';
                // cout << after_edge.location[j] << after_edge.type[j] << '\n';
                if (after_concer.type[j] == 1)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, after_concer.location[j]);
                }
                else if (after_concer.type[j] == 2)
                {
                    input_Cube = Rotate_Clockwise(input_Cube, after_concer.location[j]);
                    input_Cube = Rotate_Clockwise(input_Cube, after_concer.location[j]);
                }
                else
                {
                    input_Cube = Rotate_Anti_Clockwise(input_Cube, after_concer.location[j]);
                }
            }
            //cout << "hello world\n";
            num_arr1_col++;
        }
        cout << '\n';
    }


    // cout << "Concer" << '\n';
    // for (i=0; i<8; i++)
    // {
    //     cout << original_StandardCube.concer[i] << '\n';
    // }
    // cout << "Edge" << '\n';
    // for (i=0; i<12; i++)
    // {
    //     cout << original_StandardCube.edge[i] << '\n';
    // }
}