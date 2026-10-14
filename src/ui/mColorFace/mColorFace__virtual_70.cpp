/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

extern "C" void mWidget__virtual_70(void *arg0, void *arg1, s32 arg2);
extern "C" void func_002854F8(void *arg0, void *arg1) throw();
extern "C" void func_002857C0(void *arg0, void *arg1) throw();

struct Element { float x[4]; };
struct Vec { int pad; Element *begin; Element *end; };
static inline int size(Vec *v) { return v->end - v->begin; }

struct VEntry285BE0A {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct VEntry285BE0B {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

extern "C" void mColorFace__virtual_70(char *arg0, char *arg1, s32 arg2) {
    VEntry285BE0A *e1;
    VEntry285BE0B *e2;
    VEntry285BE0A *e3;
    s32 n;

    mWidget__virtual_70(arg0, arg1, 0);
    if (arg2 != 0) {
        e1 = (VEntry285BE0A *)(*(char **)(arg1 + 4) + 0x1D8);
        e1->fn(arg1 + e1->delta);
        e2 = (VEntry285BE0B *)(*(char **)(arg1 + 4) + 0x1C0);
        e2->fn(arg1 + e2->delta, *(void **)(arg0 + 0xB4));
        
        if (*(f32 *)(arg0 + 0xB0) == 0.0f || size(((Vec *)(arg0 + 0xA0))) != 1) {
            func_002854F8(arg0, arg1);
        } else {
            func_002857C0(arg0, arg1);
        }

        e3 = (VEntry285BE0A *)(*(char **)(arg1 + 4) + 0x1C8);
        e3->fn(arg1 + e3->delta);
    }
}
