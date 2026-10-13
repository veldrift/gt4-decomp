typedef int s32;

extern "C" void func_003A4E00(char *arg0, float fparg0);
extern "C" s32 func_003A1E10(char *p, char *q);
extern "C" void func_003B0428(char *dst, const char *src, s32 size);

struct RaceMessageDisplayLayout {
    char pad0[0x28];
    s32 u28;
    s32 pad2c;
    s32 u30;
    char pad34[0x5C];
    char u90;
};

extern "C" void func_003A4CF0(char *self, char *s, float f) {
    struct RaceMessageDisplayLayout *r = (struct RaceMessageDisplayLayout *)self;

    if (f > 0.0f) {
        func_003A4E00(self, f);
    }
    if (s != 0) {
        if (*s == 0x40) {
            s32 v = func_003A1E10(s + 1, s);
            r->u90 = 0;
            r->u30 = v;
        } else {
            func_003B0428((char *)r + 0x90, s, 0xC0);
            r->u30 = 0;
        }
    } else {
        r->u90 = 0;
        r->u30 = 0;
    }
    r->u28 = 0;
}
