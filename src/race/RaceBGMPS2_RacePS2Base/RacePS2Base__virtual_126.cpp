/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

extern "C" void func_00397288(void *, char *, void *);
extern "C" void func_00398830(void *, char *);
extern "C" void **VisionList__getVoronoi(void *, float, float, float);

typedef char *(*GetFn)(char *, s32);
typedef float (*FFn)(char *, float);

extern "C" void RacePS2Base__virtual_126(char *arg0) {
    char *s3 = arg0 + 0xDA0;
    float z = 0.0f;
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *s2 = *(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4);
    char *s1 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    func_00398830(*(void **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80), s3);
    s32 s0 = *(s32 *)(s2 + 8);
    VEntry *e2 = (VEntry *)(*(char **)s1 + 0x20);
    float f22 = ((FFn)e2->fn)(s1 + e2->delta, z);
    VEntry *e3 = (VEntry *)(*(char **)s1 + 0x28);
    float f21 = ((FFn)e3->fn)(s1 + e3->delta, z);
    VEntry *e4 = (VEntry *)(*(char **)s1 + 0x30);
    float f14 = ((FFn)e4->fn)(s1 + e4->delta, z);
    void *a2 = 0;
    if (s0 != 0) a2 = *VisionList__getVoronoi((void *)s0, f22, f21, f14);
    func_00397288(s2, s3, a2);
}
