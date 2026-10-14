/* compiler: ee-gcc2.96-nsa-nosched1 */
typedef int s32;
typedef short s16;

static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct E { char pad[0x3C]; };
struct T { E e[2]; s32 cur; };
extern T D_0061850C;

extern "C" void func_00105670(void *);
extern "C" void func_001056A0(void *, void *);
extern "C" void func_003425E0(void *, s32, float);
extern "C" void func_00342B28(void *, void *);
extern "C" void func_003B72F8(void *, void *);
extern "C" void func_003B76F0(void *, s32, const char *, s32);
extern "C" float func_003C0FB0(void *);
extern "C" void func_004A2980(s32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A3998(s32, float);

typedef char *(*GetFn)(char *, s32);
typedef s32 (*TestFn)(char *, char *);

extern "C" void RacePS2Base__render_other(char *arg0, void *arg1) {
    char *p = *(char **)(arg0 + 0x6C);
    if (*(s32 *)(*(char **)(*(char **)(p + 0x80) + 4) + 8) == 0)
        func_003B76F0(p + 0xF4, 0x1B, "VisionList is invalid or empty", 0);
    if (*(s32 *)(arg0 + 0xCD8) == 0) {
        func_00342B28(arg0, arg1);
        if (*(s32 *)(arg0 + 0xCC8) == 0) {
            VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
            char *o = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
            VEntry *e2 = (VEntry *)(*(char **)o + 0x108);
            if (((TestFn)e2->fn)(o + e2->delta, o) == 0 && *(float *)(arg0 + 0xCF38) > 0.0f) {
                func_00105670(arg1);
                func_001056A0(&D_0061850C.e[1 - D_0061850C.cur], &D_0061850C);
                func_004A2980(0xFFFFFF);
                func_004A29A8(0);
                func_004A3998(6, minf(*(float *)(arg0 + 0xCF38), 0.65f));
                func_004A2980(-1);
                func_004A29A8(1);
            }
        }
    } else {
        *(s32 *)(arg0 + 0xCF3C) = 0;
    }
    func_003B72F8(arg0 + 0xCF68, arg1);
    float r = func_003C0FB0(*(void **)(arg0 + 0x6C));
    float k = *(float *)(arg0 + 0xCF48);
    float one = 1.0f;
    float t = r * k;
    if (t < one)
        func_003425E0(arg1, *(s32 *)(arg0 + 0xCF60), one - (one - t * t * t));
}
