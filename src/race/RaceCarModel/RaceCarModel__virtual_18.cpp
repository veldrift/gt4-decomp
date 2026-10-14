/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Result { s32 words[5]; };
struct Blk { s32 a,b; };
struct Pair { Blk block; s32 padding[6]; };
static inline void set(Blk *b, s32 a, s32 c) { b->a = a; b->b = c; }
extern "C" char *func_00450B90(void *);
extern "C" int func_00594470(const char *, const char *, unsigned int);
extern "C" void *GT4Model__CarModel__getWheelFileName(void *, void *, int);
extern "C" Result func_004AE6B0(void *);
extern "C" s32 func_00458780(void *, s32);
extern "C" s32 func_00450B78(void *, s32);
extern "C" void func_0038F8E0(void *, s32);
extern "C" void func_0044CC18(void *, Blk *, Blk *, s32);
extern "C" void RaceCarModel__virtual_18(char *o, char *name, s32 mode) {
    char *car = o + 0x18;
    char buf[64];
    if (func_00594470(name, func_00450B90(car), 8)) {
        GT4Model__CarModel__getWheelFileName(name, buf, *(void **)(o + 0x14) ? 1 : mode);
        Result info = func_004AE6B0(buf);
        Pair pair;
        Blk cb;
        s32 size = (info.words[2] + 0x3f) & ~0x3f;
        void *p = *(void **)(o + 0x14);
        s32 data;
        if (p) data = func_00458780(p, size);
        else data = func_00450B78(car, size);
        *(s32 *)(car + 0x88) = 0;
        set(&pair.block, data, 0);
        set(&cb, (s32)func_0038F8E0, (s32)o);
        func_0044CC18(buf, &pair.block, &cb, 1);
    }
}
