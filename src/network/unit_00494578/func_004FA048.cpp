struct Obj {
    char pad[0x223C];
    int count;
};

extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_004FA048(Obj *arg0, char *arg1) {
    if (arg1 != 0) {
        int t = ((int)(arg1 - (char *)arg0) - 0x2288) >> 2;
        int idx = t * (int)0xB823EE09;
        if ((unsigned int)idx < 0x10u) {
            func_00576100(arg0);
            arg0->count = arg0->count - 1;
            int off = idx * 4 + 0x2240;
            int *e = (int *)((char *)arg0 + off);
            *e = *e - 1;
            return func_00576140(arg0);
        }
    }
}
