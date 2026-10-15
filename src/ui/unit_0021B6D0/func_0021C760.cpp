/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vec4 { f32 x, y, z, w; };

struct Src {
    f32 f[6];
    f32 g;
    f32 scale[4];
};

struct Out {
    s32 one;
    f32 g;
    char pad8[8];
    f32 f[6];
};

struct Mat { Vec4 m[5]; };

struct Elem {
    s32 flag;
    Vec4 v[5];
};

struct Dst {
    char pad[0x14];
    Elem e[2];
};

static inline void copy(Vec4 *d, const Vec4 *s) {
    d->x=s->x; d->y=s->y; d->z=s->z; d->w=s->w;
}
static inline void set(Vec4 *d, float x, float y, float z, float w) {
    d->x=x; d->y=y; d->z=z; d->w=w;
}
static inline void scale(Vec4 *d, const Vec4 *s, float k) {
    set(d, s->x*k, s->y*k, s->z*k, s->w);
}
static inline void scale_w(Vec4 *d, const Vec4 *s, float k) {
    set(d, s->x, s->y, s->z, s->w*k);
}
static inline float product(float x, float k) { return x*k; }
extern "C" void func_0021C760(Src *a, Out *o, Mat *src, Dst *dst) {
    o->one = 1;
    o->g = a->g;
    o->f[0] = a->f[0];
    o->f[1] = a->f[1];
    o->f[2] = a->f[2];
    o->f[3] = a->f[3];
    o->f[4] = a->f[4];
    o->f[5] = a->f[5];
    f32 *sc = a->scale;
    Mat *s = src;
    for (int i = 0; i < 2; i++) {
        dst->e[i].flag = 1;
        copy(&dst->e[i].v[0], &s->m[0]);
        { float k = *sc; set(&dst->e[i].v[1], s->m[3].x*k, s->m[3].y*k, s->m[3].z*k, s->m[3].w); }
        { float k = *sc; set(&dst->e[i].v[2], s->m[2].x*k, s->m[2].y*k, s->m[2].z*k, s->m[2].w); }
        { float k = *sc; set(&dst->e[i].v[3], s->m[4].x*k, s->m[4].y*k, s->m[4].z*k, s->m[4].w); }
        { float w = product(s->m[1].w, *sc++); set(&dst->e[i].v[4], s->m[1].x, s->m[1].y, s->m[1].z, w); }
        s++;
    }
}
