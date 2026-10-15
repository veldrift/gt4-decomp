/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Buf { char pad[0x140]; Vec v[3]; char pad2[0x16C - 0x164]; };
struct Obj { Buf bufs[2]; int pad; int cur; };
static inline Vec *blend(Vec *out, const Vec *a, const Vec *c, float t) {
    float u = 1.0f - t;
    if (a->x < c->x) { *out = *c; return out; }
    float ox = c->x * t + a->x * u;
    float oy = c->y * t + a->y * u;
    float oz = c->z * t + a->z * u;
    out->x = ox;
    out->y = oy;
    out->z = oz;
    return out;
}
extern "C" Vec *func_0045ADF0(Vec *out, Obj *obj, int i, float t) {
    int b = obj->cur;
    Buf *bc = &obj->bufs[b];
    Buf *bo = &obj->bufs[1 - b];
    return blend(out, &bc->v[i], &bo->v[i], t);
}
