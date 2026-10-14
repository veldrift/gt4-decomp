/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0x648]; float pos[3]; };
struct Quat { float x, y, z, w; };
struct Out { float v[3]; float v2[3]; Quat q; };
struct Vec3 { float x, y, z; };
inline void set(Vec3 *d, float x,float y,float z) { d->x=x;d->y=y;d->z=z; }
inline void conv(Vec3 *d, const float *p) { d->x=p[0];d->y=p[2];d->z=-p[1]; }
extern "C" float func_00344798(Obj *, float);
extern "C" float func_003447F8(Obj *, float);
extern "C" float func_00344828(Obj *, float);
extern "C" float func_00344858(Obj *, float);
extern "C" float func_00344888(Obj *, float);
extern "C" float func_003448B8(Obj *, float);
extern "C" void func_0048A3B8(Quat *, void *, void *);
extern "C" void func_0048BE88(Quat *, float, float, float);

extern "C" int func_0040D618(Out *out, Obj *a, Obj *b) {
    Quat q;
    Vec3 d;
    Vec3 p;
    float r[3];
    Vec3 t;
    Quat *oq = &out->q;
    float qx = func_00344858(a, 0.0f);
    float qy = func_003448B8(a, 0.0f);
    func_0048BE88(&q, qx, qy, -func_00344888(a, 0.0f));
    conv(&d, b->pos);
    conv(&p, a->pos);
    d.x -= p.x;
    d.y -= p.y;
    d.z -= p.z;
    r[0] = func_00344798(b, 0.0f) - func_00344798(a, 0.0f);
    r[1] = func_003447F8(b, 0.0f) - func_003447F8(a, 0.0f);
    r[2] = func_00344828(b, 0.0f) - func_00344828(a, 0.0f);
    oq->w = q.w;
    oq->x = -q.x;
    oq->y = -q.y;
    oq->z = -q.z;
    set(&t,d.x,d.y,d.z);
    func_0048A3B8(oq, out->v2, &t);
    set(&t,r[0],r[1],r[2]);
    func_0048A3B8(oq, out, &t);
    return 1;
}
