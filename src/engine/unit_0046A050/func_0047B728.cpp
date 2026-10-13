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

extern "C" void *func_006066C8(void *arg0, char *arg1, int arg2);
extern char D_00624570[];
extern char D_006AD838[];

struct Callee {
    s32 pad0;
    s32 pad1;
    void (*fn)(s32 *, s32);
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return D_006AD838;
    s.terminate();
    return s.data();
}

extern "C" s32 *func_0047B728(s32 *arg0, s32 arg1, String *arg2) {
    void *r = func_006066C8((void *)c_str(*arg2), D_00624570, 0xF);
    if (r) {
        Callee *c = (Callee *)r;
        c->fn(arg0, arg1);
        return arg0;
    }
    *arg0 = 1;
    return arg0;
}
