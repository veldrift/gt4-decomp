typedef int s32;

struct Obj {
    char p0[0xD4];
    s32 fD4;
};

extern char D_00697110[];

extern "C" int func_002208E8(char *dst, unsigned capacity, const char *name, const char *suffix);
extern "C" void func_004AE230(s32 *self, char *path, s32 mode);
extern "C" void free(s32 arg0);

extern "C" void func_001FD528(Obj *arg0, const char *arg1) {
    char buf[0x80];
    s32 rec[8];
    s32 *out;
    s32 old = arg0->fD4;
    if (old != 0) {
        arg0->fD4 = 0;
        free(old);
    }
    func_002208E8(buf, 0x80, arg1, D_00697110);
    out = rec;
    func_004AE230(out, buf, 1);
    if (out[0] == 0) {
        arg0->fD4 = out[4];
    }
}
