/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Tex { char pad0[0x18]; s32 width; char pad1c[0xC]; s32 mode; };
struct Rect { char pad0[0x10]; s32 x; s32 y; s32 w; s32 h; };

extern "C" void func_001054A0(Tex *, s32) throw();
extern "C" void func_001056A0(Tex *) throw();
extern "C" void func_00105728(Rect *) throw();
extern "C" s32 func_00105918(Tex *) throw();
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, f32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004A2B10(f32, f32);
extern "C" void func_004A2B58(f32, f32, f32, f32);
extern "C" void func_004A4500(s32);
extern "C" void func_004A4550(s32, s32);
extern "C" void pglPushAttrib(s32);
extern "C" void func_004A5688(void);
extern "C" void func_004A5FE0(s32);
extern "C" void func_004A6788(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" s32 func_004A7C60(void);
extern "C" void func_004AA1D8(f32, f32, f32, f32);
extern "C" void func_004AB040(s32);

extern "C" void func_00105C48(Tex *tex, Rect *r, s32 interlace, s32 useOwn, f32 a, f32 cr, f32 cg, f32 cb) {
    f32 ofs = 0.5f;
    s32 saved = tex->mode;
    func_001054A0(tex, 0);
    f32 blend = 0.0f;
    f32 w = (f32)tex->width;
    f32 h = (f32)func_00105918(tex);
    f32 u0 = (f32)r->x;
    f32 v0 = (f32)r->y;
    f32 u1 = (f32)(r->x + r->w);
    f32 v1 = (f32)(r->y + r->h);
    pglPushAttrib(0x887);
    a *= 0.5f;
    func_00105728(r);
    func_001056A0(tex);
    func_004A5FE0(0);
    func_004AB040(3);
    func_004AB040(4);
    func_004AB040(8);
    func_004A29A8(0);
    f32 org = 0.0f;
    func_004AA1D8(cr, cg, cb, 1.0f);
    blend = 0.5f - a;
    func_004A4550(3, 1);
    func_004A4550(2, 1);
    func_004A4500(0);
    if (interlace != 0) {
        s32 field;
        if (useOwn != 0) {
            field = tex->mode;
        } else {
            field = func_004A7C60();
        }
        ofs = 0.375f;
        if (field != 3) ofs = 0.625f;
    }
    func_004A2B58(0.0f, 0.0f, 1.0f, 1.0f);
    func_004A2B10(0.5f, ofs);
    func_004AB040(6);
    func_004A6788(org, org, w, h, u0, v0, u1, v1);
    if (0.0f < blend) {
        func_004A1638(6);
        func_004A2808(100, blend);
        func_004A6788(org, org, w, h, u0, v0 + 1.0f, u1, v1 + 1.0f);
        func_004AB040(6);
    }
    func_004A5688();
    func_001054A0(tex, saved);
}
