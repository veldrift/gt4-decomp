typedef int s32;

struct Entry {
    short delta;
    short pad;
    void (*fn)(float *, void *);
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A79D8(float arg0);
extern "C" void func_004AA1D8(float arg0, float arg1, float arg2, float arg3);
extern "C" void func_0049FD50(s32 arg0, char *arg1, char *arg2, s32 arg3, s32 arg4, s32 arg5);

extern char D_00618380[];
extern char D_006183C0[];

extern "C" void func_00102D00(char *arg0) {
    float v[4];
    char *c;
    Entry *e;

    func_004A53F8();
    c = *(char **)(arg0 + 0x9C);
    e = (Entry *)((char *)*(void **)c + 0x30);
    e->fn(v, c + e->delta);
    func_004AA1D8(v[0], v[1], v[2], v[3]);
    func_004A79D8(-*(float *)(arg0 + 0xB0));
    func_0049FD50(4, D_00618380, D_006183C0, 0, 0, 0);
    func_004A5400();
}
