typedef int s32;

struct S2C6110 {
    char p0[8];
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
};

extern "C" void func_0022F178(void *arg0, void *arg1);
extern "C" s32 func_002319C0(char *arg0);
extern "C" void *func_00235C00(char *arg0);

extern "C" void func_002C6110(void *arg0) {
    struct S2C6110 *s = (struct S2C6110 *)arg0;
    s32 t;
    if (s->w8 != 0) {
        t = func_002319C0((char *)s->w8);
        if (s->wC != 0) {
            func_0022F178((void *)s->w8, func_00235C00((char *)t));
        }
        s->w1C = 0;
        s->w14 = 0;
        s->w18 = 0;
        s->w10 = 0;
        s->wC = 0;
        s->w8 = 0;
    }
}
