typedef int s32;

struct Sub002D2E40 {
    char pad0[0x14];
    float y;
};

struct Self002D2E40 {
    char pad0[0xC0];
    void *c;
};

extern "C" void func_002D2318(struct Sub002D2E40 *arg0, float fparg0);
extern "C" void func_0025B340(void *c, float y);

extern "C" s32 func_002D2E40(char *arg0) {
    struct Self002D2E40 *self = (struct Self002D2E40 *)arg0;
    if (self->c == 0)
        return 0;
    struct Sub002D2E40 *s = (struct Sub002D2E40 *)(arg0 + 0xFC);
    func_002D2318(s, -8.0f);
    func_0025B340(self->c, -s->y);
    return 1;
}
