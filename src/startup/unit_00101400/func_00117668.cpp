typedef int s32;

struct V { short delta; short index; void *fn; };

struct Inner { char pad[0xDC]; s32 flag; };
struct S {
    char pad0[0x64];
    char *tbl;
    s32 unk68;
    Inner *inner;
    char pad1[0xD48 - 0x70];
    s32 d48;
    char pad2[0xF050 - 0xD4C];
    s32 f050;
};

extern "C" char D_0068D7D0[];
extern "C" void func_0012BFC0(void *arg0);
extern "C" void func_0012BFD0(int arg0);
extern "C" void func_0010FE40(char *arg0);
extern "C" void func_00387EF0(void *arg0, int arg1, int arg2);

extern "C" void func_00117668(S *arg0) {
    s32 saved = arg0->f050;
    arg0->f050 = 0;
    arg0->inner->flag = 1;
    arg0->d48 = 1;
    func_00387EF0(arg0, 4, 1);
    func_0012BFC0(arg0);
    func_0012BFD0(1);
    func_0010FE40(D_0068D7D0);
    func_0012BFC0(0);
    V *e = (V *)(arg0->tbl + 0x2C0);
    ((void (*)(void *))e->fn)((char *)arg0 + e->delta);
    arg0->d48 = 0;
    arg0->inner->flag = 0;
    arg0->f050 = saved;
}
