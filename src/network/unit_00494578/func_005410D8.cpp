extern "C" int func_005413B8(int, int, int);
extern "C" int func_00541EF0(int);
extern "C" int func_005410D8(int arg0, int arg1, int arg2, int arg3) {
    int r = 0;
    if (arg0 == 0) return 2;
    if (arg1 != 0 && arg2 != 0) r = func_005413B8(arg0, arg1, arg2);
    if (arg3 != 0) r = func_00541EF0(arg0);
    return r;
}
