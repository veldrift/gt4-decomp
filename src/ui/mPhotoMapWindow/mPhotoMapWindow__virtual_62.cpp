typedef int s32;
typedef short s16;

struct S {
    int m0;
    char *vtbl;
};

struct In {
    int m0;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(char *self, In *a);
};

extern "C" void mSceneViewFace__virtual_62(s32 arg0, In *arg1);
extern "C" s32 func_00206868(S *arg0);
extern "C" s32 func_0025C300(S *arg0);

extern "C" void mPhotoMapWindow__virtual_62(s32 arg0, In *arg1) {
    S *s;

    mSceneViewFace__virtual_62(arg0, arg1);
    s = (S *)func_00206868((S *)arg0);
    if (s != 0) {
        do {
            VEntry *e = (VEntry *)(s->vtbl + 0x1F8);
            e->fn((char *)s + e->delta, arg1);
            s = (S *)func_0025C300(s);
        } while (s != 0);
    }
}
