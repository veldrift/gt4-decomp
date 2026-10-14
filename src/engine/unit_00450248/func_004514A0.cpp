/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot {
    float x, y, z;
    char pad[0x14];
    float lim;
    char pad2[0x14];
};
struct Cfg {
    char pad[8];
    float v;
};
struct Inner {
    char pad[0x10];
    char *p;
};
struct Obj {
    Inner *in;
    char pad[0x90];
    Slot s[4];
};

extern "C" void func_004514A0(Obj *o, unsigned int i, float x, float y, float z) {
    if (i < 4) {
        Slot *s = &o->s[i];
        Inner *in = o->in;
        if (in) {
            int off = ((int)i < 2) ? 0x50 : 0x54;
            float v = ((Cfg *)(in->p + off))->v;
            if (v != 0.0f) {
                float d = v - s->lim;
                if (d < y)
                    y = d;
            }
        }
        s->x = x;
        s->y = y;
        s->z = z;
    }
}
