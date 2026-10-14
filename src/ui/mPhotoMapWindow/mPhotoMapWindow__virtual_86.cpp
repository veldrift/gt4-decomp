typedef int s32;
typedef short s16;

struct S {
    int m0;
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a);
};

extern "C" S *func_00206878(void *arg0);
extern "C" S *func_0025C2E8(S *arg0);
extern "C" void mSceneViewFace__virtual_86(void *arg0, s32 arg1);

extern "C" void mPhotoMapWindow__virtual_86(void *arg0, s32 arg1) {
    S *s = func_00206878(arg0);
    if (s != 0) {
        do {
            VEntry *e = (VEntry *)(s->vtbl + 0x2B8);
            e->fn((char *)s + e->delta, arg1);
            s = func_0025C2E8(s);
        } while (s != 0);
    }
    mSceneViewFace__virtual_86(arg0, arg1);
}
