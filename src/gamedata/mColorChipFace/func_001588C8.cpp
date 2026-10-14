/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct Obj {
    char pad0[0xB0];
    s16 unkB0;
    char padB2[2];
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    u32 unkC0[4];
    char padD0[4];
    char unkD4[8];
};
extern "C" void func_00158A88(void *arg0);
extern "C" s32 func_00202CE8(s32 arg0);
extern "C" void func_00203620(void *arg0, int arg1);
extern "C" void func_00203678(void *arg0, void *arg1);
extern "C" void *func_002EFCB0(void *arg0, int arg1);
extern "C" void func_005A48D8(void *dst, int v, int n);

extern "C" void func_001588C8(Obj *self, void *arg1) {
    s32 col[4];
    s32 tmp[4];
    s32 n;
    int i;
    s32 *p;
    func_005A48D8(self->unkD4, 0, 8);
    void *c0 = func_002EFCB0(arg1, 0);
    p = tmp;
    func_00203678(p, c0);
    col[0] = func_00202CE8(p[0] + 0x10);
    func_00203620(p, 2);
    func_00203678(p, func_002EFCB0(arg1, 1));
    col[1] = func_00202CE8(p[0] + 0x10);
    func_00203620(p, 2);
    func_00203678(p, func_002EFCB0(arg1, 2));
    col[2] = func_00202CE8(p[0] + 0x10);
    func_00203620(p, 2);
    func_00203678(p, func_002EFCB0(arg1, 3));
    col[3] = func_00202CE8(p[0] + 0x10);
    func_00203620(p, 2);
    n = 0;
    for (i = 0; i < 4; i++) {
        if (col[i] & 0x01000000) n++;
    }
    if (n > 0) {
        self->unkB0 = n;
        int j;
        for (j = 0; j < 4; j++) {
            self->unkC0[j] = (col[j] & 0xFFFFFF) | 0xFF000000;
        }
        self->unkB8 = (col[0] >> 25) & 1;
        self->unkB4 = (col[0] >> 26) & 1;
        self->unkBC = (col[0] >> 27) & 1;
        func_00158A88(self);
    }
}
