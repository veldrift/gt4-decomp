/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Key {
    int pad0;
    f32 t4;
    f32 t8;
    char padC[0x70];
};

struct Self {
    char pad0[0x14];
    f32 m14;
    char pad18[8];
    int count;
    Key *keys;
};

extern "C" f32 func_003DDF18(Self *, f32) throw();
extern "C" f32 func_003DDE78(Self *) throw();
extern "C" int func_003DDF88(Self *, f32) throw();

extern "C" int func_003DDFF0(Self *self, Key **out, int max, int mult, f32 base) {
    f32 t = func_003DDF18(self, base + (f32)mult * self->m14);
    f32 period = func_003DDE78(self);
    int idx = func_003DDF88(self, t);
    int n = 0;
    if (idx >= 0) {
        while (self->keys[idx].t4 <= t && n < max) {
            Key *k = (Key *)(idx * 0x7C + (int)self->keys);
            if (t < k->t8) {
                out[n++] = k;
            }
            idx++;
            if (idx >= self->count) {
                f32 prev = t;
                t -= period;
                idx -= self->count;
                if (!(t < prev))
                    return n;
            }
        }
    }
    return n;
}
