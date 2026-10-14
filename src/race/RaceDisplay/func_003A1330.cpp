typedef int s32;
typedef float f32;

struct Holder {
    char p00[0x34];
    s32 f34;
};

extern "C" void func_003A5268(void *a0, const char *a1, s32 a2);
extern "C" void RaceEventDisplay__addEvent(char *self, s32 a1, f32 delta, f32 value, f32 a, f32 b);

extern char D_006A0718[];
extern struct Holder *DisplayRText__rtext_ptrs_;

extern "C" void func_003A1330(void *arg0) {
    char *s0;

    s0 = (char *)arg0 + 0x17BC;
    *(s32 *)(s0 + 0x20) = (s32)0x80C8C8C8;
    func_003A5268(s0, D_006A0718, 1);
    RaceEventDisplay__addEvent(s0, DisplayRText__rtext_ptrs_->f34, 3.0f, 0.0f, 0.1499999910593033f, 0.1499999910593033f);
}
