/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short pad; int (*fn)(void *); };
struct Q {
    char p0[0x440];
    unsigned char f440;
    char p441[0x467 - 0x441];
    unsigned char f467;
    char p468[0x4A4 - 0x468];
    float f4A4;
    char p4A8[4];
    short f4AC;
};
struct Obj { char p0[4]; char *f4; char p8[0xFC]; Q q; };
extern "C" float DynamicsConductor__GetCourseLength(char *);

extern "C" int func_003F7880(Obj *o, int *out)
{
    Q *q = &o->q;
    if (q->f4AC > 0) return 0;
    if (q->f467 != 1) return 0;
    char *b = o->f4;
    char *t = b + 0xF818;
    unsigned char s = t[0x6E];
    if (s == 0) {
        VE *e = (VE *)(*(char **)(b + 0x10140) + 0x30);
        if (e->fn(b + e->delta) != 0) {
            s = t[0x4E];
        } else {
            s = *(unsigned char *)(q->f440 + (int)b + 0xF866);
        }
        if (s == 0) return 0;
    }
    if (out != 0) *out = s;
    float d = DynamicsConductor__GetCourseLength(o->f4) - q->f4A4;
    if ((float)(s * 3) * 0x1.1c71c6p-2f < d) return 1;
    if (out != 0) *out = 0;
    return 2;
}
