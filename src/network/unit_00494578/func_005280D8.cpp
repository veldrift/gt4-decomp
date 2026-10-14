typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj { char p[0x98]; void *f98; u16 f9C; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" s32 func_00527F00(Obj *, s32);
extern "C" s32 func_005280D8(Obj *o, u32 n) {
    u32 i = 0;
    func_005A48D8(o->f98, -1, o->f9C * 3);
    if (n != 0) {
        do {
            s32 r = func_00527F00(o, (signed char)i);
            i++;
            if (r != 0) return r;
        } while (i < n);
    }
    return 0;
}
