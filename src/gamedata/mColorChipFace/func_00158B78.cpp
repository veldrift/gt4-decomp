/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;
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
extern "C" void func_00158A88(void *arg0) throw();
extern "C" void *func_00441248(void *arg0);
extern "C" s32 func_00445808(void *arg0);
extern "C" s8 SPEC_DATABASE__CarEquipments__getVariationOrder(void *arg0);
extern "C" s32 func_00445B28(void *self, s32 key, s32 *out);
extern "C" void func_005A48D8(void *dst, int v, int n);
extern "C" void *func_00147D80(void *);

extern "C" void func_00158B78(Obj *self, void *arg1, s32 idx) {
    s32 col[4];
    s32 n;
    s32 m;
    int i;
    void *h;
    func_005A48D8(self->unkD4, 0, 8);
    h = func_00147D80(arg1);
    if (idx < 0) idx = SPEC_DATABASE__CarEquipments__getVariationOrder(func_00441248(h));
    m = func_00445808(func_00441248(h));
    if (idx >= m) idx = m - 1;
    if (func_00445B28(func_00441248(h), idx, col) != 0) {
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
}
