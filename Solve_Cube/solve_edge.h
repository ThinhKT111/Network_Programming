struct StepEdge {
    int type[4];
    int location[4];
};

int Find_Edge_Loop(Edge (&input_arr)[12][13], Cube original_Cube, Cube input_Cube);
int Apply_Case_Edge(Edge input_case, StepEdge (&pre), StepEdge (&after), int (&num));