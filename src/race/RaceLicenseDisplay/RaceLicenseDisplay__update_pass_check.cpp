typedef int s32;
typedef float f32;

struct Self {
    char pad[0x4384];
    s32 m4384;
};

struct Src {
    char pad[0x88];
    s32 m88;
};

extern "C" void AutomaticFader__fadeout(void *self, f32 t);

extern "C" void RaceLicenseDisplay__update_pass_check(struct Self *self, struct Src *arg1) {
    s32 t;

    if (self->m4384 <= 0) {
        t = arg1->m88;
        if (t > 0) {
            self->m4384 = t;
            AutomaticFader__fadeout((char *)self + 0xBC, 0x1.0p-2f);
        }
    }
}
