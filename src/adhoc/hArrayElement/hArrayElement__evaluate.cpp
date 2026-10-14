/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; s32 *(*fn)(void *, s32); };
struct VObj { char pad[4]; VEntry *vtbl; };
struct ArrayElement { char pad[0x10]; VObj *object; s32 index; };
static inline s32 *vcall(char *o, s32 index) {
    VEntry *e = (VEntry *)((char *)((VObj *)o)->vtbl + 0x68);
    return e->fn(o + e->delta, index);
}
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void hArrayElement__evaluate(ArrayElement *arg0, s32 *arg1) {
    s32 *value = vcall((char *)arg0->object, arg0->index);
    if (arg1 != value) {
        s32 newVal = *value;
        if (newVal != 0) func_003285A8(newVal);
        s32 oldVal = *arg1;
        if (oldVal != 0) func_003285F8(oldVal);
        *arg1 = newVal;
    }
}
