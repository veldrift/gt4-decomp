struct S {
    int type;
    int flag;
};

extern "C" void func_00476BC0(S *arg0, int arg1);
extern "C" float func_00477460(S *arg0);

extern "C" void func_00478400(S *arg0) {
    if (arg0->type == 5) {
        arg0->flag = arg0->flag != 1;
    } else {
        if (func_00477460(arg0) == 0.0f) {
            func_00476BC0(arg0, 1);
        } else {
            return func_00476BC0(arg0, 0);
        }
    }
}
