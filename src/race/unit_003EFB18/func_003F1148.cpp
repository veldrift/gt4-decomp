/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct S {
    void *unk0;
    char pad[0xF8BC - 4];
    s32 result;
    char pad2[4];
    s32 buf[12];
    s32 idx;
};
extern "C" s32 func_003C0E30(void *);
extern "C" void func_003F1148(S *self) {
    s32 sum;
    s32 n;
    s32 v = func_003C0E30(self->unk0);
    sum = 0;
    s32 idx = self->idx;
    if (idx < 0) {
        n = idx + 12;
        self->buf[n] = v;
        for (s32 i = 0; i < n; i++)
            sum += self->buf[i + 1];
        self->idx = self->idx + 1;
    } else {
        n = 12;
        self->buf[idx] = v;
        for (s32 i = 0; i < 12; i++)
            sum += self->buf[i];
        self->idx = self->idx + 1;
        if (self->idx >= 12)
            self->idx = 0;
    }
    self->result = (u32)(sum * 3) / (u32)n + (n * 25 - 25);
}
