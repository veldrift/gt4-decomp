typedef int s32;
typedef unsigned int u32;

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};

extern "C" void *func_00606DD8(void *arg0, char *arg1, int arg2);
extern "C" s32 func_0057D9C0(const char *fmt, ...);
extern char D_006ADC80[];
extern char D_006ADCD0[];
extern char D_00624800[];

struct Callee {
    s32 pad0;
    s32 pad1;
    void (*fn)(s32 *, s32);
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006ADC80;
    s.terminate();
    return s.data();
}

extern "C" s32 *func_0047CA38(s32 *arg0, s32 *arg1, String *arg2) {
    void *r = func_00606DD8((void *)c_str(*arg2), D_00624800, 1);
    if (r) {
        Callee *c = (Callee *)r;
        c->fn(arg0, *arg1);
        return arg0;
    }
    func_0057D9C0(D_006ADCD0, c_str(*arg2));
    *arg0 = 1;
    return arg0;
}
