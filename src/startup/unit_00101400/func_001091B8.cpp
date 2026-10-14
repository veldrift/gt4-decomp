/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long u64;

struct Elem { char pad[0x20]; u64 bits; };
struct Q { char pad[0x18]; Elem *elems; };
struct Self { char pad[0x70]; s32 idx; f32 scale; };

extern Q *D_006186FC;

extern "C" void func_001056A0(void *);
extern "C" s32 func_00499728(void *);
extern "C" void func_0049CC48(void *);
extern "C" void func_004A3078(s32);
extern "C" void func_004A3230(s32);
extern "C" void func_004A6498(s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_004AB040(s32);
extern "C" s32 func_004AB2E8(f32, f32, f32);

extern "C" void func_001091B8(Self *self, void *arg1) {
    func_001056A0(arg1);
    func_00499728(D_006186FC);
    func_004AB040(5);
    func_004AB040(4);
    func_004AB040(6);
    func_004A3078(0);
    func_004A3230(1);
    Elem *e = D_006186FC->elems + self->idx;
    func_0049CC48(e);
    u64 b = e->bits;
    f32 s = self->scale;
    s32 w = (s32)(((b >> 14) & 0x3FF) + 1);
    s32 h = (s32)(((b >> 34) & 0x3FF) + 1);
    s32 x = (0x280 - w) >> 1;
    s32 y = (0x1C0 - h) >> 1;
    func_004AB2E8(s, s, s);
    func_004A6498(x, y, x + w, y + h, 0, 0, w, h);
}
