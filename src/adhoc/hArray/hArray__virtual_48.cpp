typedef int s32;
typedef short s16;

struct RefCounter;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline s32 vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_002F0DB8(void *arg0, int arg1);
extern "C" void func_002F1410(void *arg0, void *arg1, void *arg2);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

extern "C" void hArray__virtual_48(void *a0, s32 *result, s32 a2, s32 a3, char **other) {
    s32 buf[4];
    s32 v = vcall(*other);
    func_002F1410(buf, (void *)a2, (void *)v);
    if (result != buf) {
        s32 newVal = buf[0];
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        s32 oldVal = *result;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *result = newVal;
    }
    func_002F0DB8(buf, 2);
}
