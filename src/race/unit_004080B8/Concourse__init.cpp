typedef int s32;

struct Obj {
    char p0[8];
    s32 f8;
    char *fC;
};

extern "C" void func_00407D88(char *p);
extern "C" void *func_005C15B0(s32 size);

extern "C" void Concourse__init(Obj *arg0, s32 arg1) {
    if (arg0->fC == 0) {
        arg0->f8 = arg1;
        s32 cnt = arg1 - 1;
        char *base = (char *)func_005C15B0(arg1 * 0x178);
        char *s0 = base;
        if (arg1 != 0) {
            do {
                func_00407D88(s0);
                s0 += 0x178;
                cnt -= 1;
            } while (cnt != -1);
        }
        arg0->fC = base;
    }
}
