/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { short a, b; };
struct W { char pad[0x2C]; Pair p; };
struct R { int ok; float v; };
struct Obj { char pad[0xC]; float f0C; char pad2[0xC]; float f1C; char pad3[0xC]; float f2C; };
struct Cs { char pad[0x14]; float f14; };
extern "C" float GT4Course__RunwayData__getVCoord(Cs *, void *, Pair *);
extern "C" void func_00457798(Obj *o, Cs *c, int flag)
{
    if (flag)
        o->f0C = 0.0f;
    else
        o->f0C = 1.0f;
    o->f1C = 0.0f;
    o->f2C = 0.0f;
    if (flag) {
        float z = o->f1C;
        W dead;
        R r[2];
        Pair q;
        dead.p.a = -1;
        dead.p.b = -1;
        int i = 0;
        for (; i < 2; i++) {
            Pair *pq = &q;
            void *e = (char *)o + 0x10 + i*0x10;
            pq->a = -1;
            q.b = -1;
            float v = GT4Course__RunwayData__getVCoord(c, e, pq);
            r[i].ok = v != z;
            r[i].v = v;
        }
        if (r[0].ok && r[1].ok) {
            float b = r[0].v;
            float a = r[1].v;
            if ((a < b && (b - a) < c->f14 * 0.5f) || (b < a && c->f14 * 0.5f < (a - b))) {
                float t = b;
                b = a;
                a = t;
            }
            o->f1C = b;
            o->f2C = a;
        }
    }
}
