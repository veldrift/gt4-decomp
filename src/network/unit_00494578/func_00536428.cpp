struct Obj20 {
    char pad0[0x20];
    int flag;
};

extern "C" int func_00535C88(int *arg0, unsigned int arg1);

extern "C" int func_00536428(int arg0, unsigned int arg1, int *arg2) {
    if (arg0 == 0) {
        return 0x17;
    }
    if (arg1 >= 0x40U) {
        return 0x17;
    }
    if (arg2 == 0) {
        return 0x17;
    }
    *arg2 = 0xFFFFFF;
    int temp = func_00535C88((int *)arg0, arg1);
    if (temp == 0) {
        return 0x17;
    }
    if (((Obj20 *)temp)->flag != 0) {
        *arg2 = 1;
    } else {
        *arg2 = 0;
    }
    return 0x1E;
}
