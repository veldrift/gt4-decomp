typedef int s32;

struct VEntry0 {
    short delta;
    short pad;
    s32 (*fn)(void *arg0, s32 arg1);
};

struct VEntry1 {
    short delta;
    short pad;
    float (*fn)(void *arg0, float arg1);
};

struct Obj1 {
    VEntry1 *vtbl;
};

struct Obj0 {
    VEntry0 *vtbl;
    char pad4[0x9B8];
    s32 unk9BC;
};

extern "C" float DevelopCamera__virtual_29(struct Obj0 *arg0, s32 arg1) {
    VEntry0 *e0 = arg0->vtbl + 27;
    Obj1 *o = (Obj1 *)(e0->fn((char *)arg0 + e0->delta, arg0->unk9BC));
    float result = 0.0f;
    if (o != 0) {
        VEntry1 *e1 = o->vtbl + 6;
        result = e1->fn((char *)o + e1->delta, (float)arg1);
    }
    return result;
}
