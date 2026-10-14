/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Info { char pad0[0xCC]; void *limits; };
struct Owner { char pad0[4]; Info *info; };
struct Cam { Owner *owner; };

extern "C" f32 func_0036FE98(Cam *, int) throw();
extern "C" f32 func_0036FF98(Cam *, f32, int) throw();
extern "C" f32 func_00370048(Cam *, int, f32) throw();
extern "C" void func_003702E8(void *, int, f32 *, f32 *) throw();

extern "C" f32 func_00370318(Cam *c, int idx, f32 r, f32 b, f32 k) {
    f32 lim[2];
    void *limits = c->owner->info->limits;
    f32 w = func_0036FE98(c, idx);
    f32 w2 = w * k;
    f32 d = func_00370048(c, idx, b) - w * 0.5f;
    f32 ad = __builtin_fabsf(d);
    if (w2 < ad) {
        if (ad - w2 < 0x1.999998p-1f) {
            if (!(d > 0.0f))
                r = b + func_0036FF98(c, w2, idx);
            else
                r = b - func_0036FF98(c, w2, idx);
        } else {
            f32 v;
            if (d > 0.0f)
                v = d - w2;
            else
                v = d + w2;
            r += func_0036FF98(c, v, idx) * 0x1.333332p-2f;
        }
    }
    f32 h = func_0036FF98(c, w, idx) * 0.5f;
    func_003702E8(limits, idx, &lim[0], &lim[1]);
    if (lim[1] < r + h)
        r = lim[1] - h;
    if (r - h < lim[0]) {
        r = lim[0] + h;
        if (lim[1] < r + h)
            r = (lim[1] + lim[0]) * 0.5f;
    }
    func_0036FF98(c, w, idx);
    return r;
}
