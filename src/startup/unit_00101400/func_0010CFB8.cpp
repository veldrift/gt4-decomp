typedef int s32;
typedef signed char s8;

void *memcpy(void *, const void *, unsigned int);

struct Obj {
    char p0[0x48];
    s32 f48;
    char p1[4];
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
};

extern "C" void func_004307D0(Obj *a, char *b);
extern "C" void func_00430888(Obj *arg0, s32 arg1);

extern "C" void func_0010CFB8(Obj *arg0, char *arg1) {
    s32 t[9];
    memcpy(t, arg1 + 0xBA, 0x24);
    func_004307D0(arg0, arg1 + 0x39);
    arg0->f48 = (s32)(s8)arg1[0x79];
    func_00430888(arg0, t[0] ^ 1);
    arg0->f50 = t[3];
    arg0->f54 = t[1];
    arg0->f58 = t[2];
    arg0->f5C = t[4];
    arg0->f60 = t[5];
}
