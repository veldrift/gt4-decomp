typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Vec4 { f32 x, y, z, w; };
struct B { s32 f0; Vec4 v4; };

extern "C" void func_00203160(void *, void *);
extern "C" B *func_0021A7A8(void *) throw();
extern "C" void func_004A1638(s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A5BF8(s32, s32, void *);
extern "C" void func_004A5CC0(s32, void *);
extern "C" void func_004A7890(f32, f32, f32);
extern "C" void func_004AB040(s32);
extern "C" void *func_005A48D8(void *, int, u32);

extern "C" void MModel__virtual_01(void *self, s32 arg1) {
    Vec4 v;
    B *base = func_0021A7A8(self);
    if (base->f0 != 0) {
        s32 i = 0;
        func_005A48D8(&v, 0, 0x10);
        v.w = 1.0f;
        func_004A5CC0(0, &v);
        do {
            func_004AB040(i + 0x65);
            i++;
        } while (i < 4);
        return;
    }
    func_00203160(&base->v4, &v);
    f32 one = 1.0f;
    v.w = one;
    func_004A5CC0(0, &v);
    func_004A53F8();
    if (arg1 != 0) func_004A7890(one, -1.0f, one);
    s32 id = 0x65;
    char *flagp = (char *)base + 0x14;
    s32 off = 0;
    s32 cnt = 3;
    do {
        s32 flag = *(s32 *)flagp;
        flagp += 0x54;
        if (flag != 0) {
            char *e = (char *)base + off;
            func_004A1638(id);
            func_00203160(e + 0x28, &v);
            v.w = one;
            func_004A5BF8(id, 0, &v);
            func_00203160(e + 0x38, &v);
            v.w = one;
            func_004A5BF8(id, 1, &v);
            func_00203160(e + 0x48, &v);
            v.w = one;
            func_004A5BF8(id, 4, &v);
            func_004A5BF8(id, 0xD, e + 0x18);
        } else {
            func_004AB040(id);
        }
        cnt--;
        id++;
        off += 0x54;
    } while (cnt >= 0);
    func_004A5400();
}
