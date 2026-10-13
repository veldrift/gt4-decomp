struct Blk {
    int f0;
    int f4;
    int f8;
};

extern "C" int func_00538E10(int arg0, int arg1);
extern "C" int func_00538E28(int arg0);

extern "C" int func_00531768(struct Blk *arg0) {
    if (arg0 == 0) {
        return 0x17;
    }
    if (func_00538E10(arg0->f0, arg0->f8) != 0) {
        return 0x16;
    }
    return (func_00538E28(arg0->f4) == 0) ? 0 : 0x16;
}
