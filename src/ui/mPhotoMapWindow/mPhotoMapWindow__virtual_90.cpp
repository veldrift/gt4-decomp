typedef int s32;
typedef short s16;

struct S_00206878 {
    int m0;
    char *vtbl;
};

struct Obj {
    int m0;
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a);
};

extern "C" s32 func_00206878(S_00206878 *arg0);
extern "C" s32 func_0025C2E8(Obj *arg0);
extern "C" void mSceneViewFace__virtual_90(Obj *arg0, s32 arg1);

extern "C" void mPhotoMapWindow__virtual_90(void *arg0, s32 arg1) {
    Obj *s;

    s = (Obj *)func_00206878((S_00206878 *)arg0);
    if (s != 0) {
        do {
            VEntry *e = (VEntry *)(s->vtbl + 0x2D8);
            e->fn((char *)s + e->delta, arg1);
            s = (Obj *)func_0025C2E8(s);
        } while (s != 0);
    }
    mSceneViewFace__virtual_90((Obj *)arg0, arg1);
}
