/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { unsigned char pad0[3]; unsigned char type; int color; float size, life, scale; char pad14[0x2c]; };
struct Config { char pad0[0x10]; int flags; char pad14[0x4c8]; float data[1]; };
struct Self { Rec *recs; char pad4[0x34]; Config *cfg; float mult; char pad40[0x1c]; float base, factor, distance; };
struct Arg { char pad0[8]; float depth; int idx; };
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" int func_003E8BA8(Self *s, Arg *arg) {
    Rec *r = s->recs + arg->idx;
    float z = -arg->depth;
    Config *c = s->cfg;
    float prod = r->life * r->scale;
    float ratio = s->distance / z;
    float alpha = prod * *(float *)((char *)c + r->type * 0x44 + 0x4dc);
    if (c->flags & 0x40000) {
        ratio = minf(ratio, 1.0f);
        ratio *= s->factor;
        ratio += s->base;
        alpha *= ratio;
    } else alpha *= 255.0f;
    int val = (int)(alpha * s->mult);
    if (val > 128) val = 128;
    return r->color | (val << 24);
}
