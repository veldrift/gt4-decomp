typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct S {
    int pad0;
    VEntry *vt;
};

extern "C" void hModule__cleanup(void *arg0);
extern "C" int func_00206868(S *arg0);
extern "C" void func_00206D18(s32 arg0);
extern "C" s32 func_0025C300(S *arg0);

extern "C" void mPhotoMapWindow__virtual_01(S *self) {
    hModule__cleanup(self);
    S *p = (S *)func_00206868(self);
    if (p != 0) {
        do {
            VEntry *e = &p->vt[2];
            e->fn((char *)p + e->delta);
            p = (S *)func_0025C300(p);
        } while (p != 0);
    }
    func_00206D18((s32)self);
}
