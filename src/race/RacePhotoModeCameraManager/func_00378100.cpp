typedef int s32;
typedef short s16;

extern "C" void func_003FB4C0(void *, s32);

static inline s32 vcall378100(void *o) {
    char *ent = *(char **)o + 0x1E8;
    void *fn = *(void **)(ent + 4);
    return ((s32 (*)(void *))fn)((char *)o + *(s16 *)ent);
}

static inline void vcallB378100(void *o, void *x) {
    char *ent = *(char **)o + 0x68;
    void *fn = *(void **)(ent + 4);
    ((void (*)(void *, void *))fn)((char *)o + *(s16 *)ent, x);
}

extern "C" void func_00378100(void *arg0) {
    char *ent;
    void *fn;
    void *obj;
    if (vcall378100(arg0) == 0) {
        return func_003FB4C0((char *)arg0 + 0x9C0, 0);
    }
    ent = *(char **)arg0 + 0x1E8;
    fn = *(void **)(ent + 4);
    obj = ((void *(*)(void *, s32))fn)((char *)arg0 + *(s16 *)ent, 0);
    vcallB378100(obj, (char *)arg0 + 0x9C0);
}
