struct StepConcer {
    int type[3];
    int location[3];
};

int Find_Concer_Loop(Concer (&input_arr)[8][9], Cube original_Cube, Cube input_Cube);
int Apply_Case_Concer(Concer input_case, StepConcer (&pre), StepConcer (&after), int (&num));