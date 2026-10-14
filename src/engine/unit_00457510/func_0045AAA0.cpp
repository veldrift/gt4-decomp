/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Obj { char pad[0x2DC]; int buf; };
extern "C" void *func_00459528(Vec *, const Vec *, const Vec *, float) throw();
extern "C" Vec *func_0045AAA0(Vec *out, Obj *obj, int i, float t) {
    Vec v;
    char *base = (char *)obj;
    int stride = 0x16c;
    int b = obj->buf;
    int other = 1 - b;
    int off = i * 0x34;
    char *p = b * stride + base;
    char *q = other * stride + base;
    p += off;
    p += 0x40;
    q += off;
    q += 0x40;
    func_00459528(&v, (Vec *)q, (Vec *)p, t);
    float x = *(float *)p;
    float speed = *(float *)(p + 0x28);
    v.x = x - speed * t;
    *out = v;
    return out;
}
