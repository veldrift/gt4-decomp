/* compiler: ee-gcc2.96-no-strict-aliasing */
struct List { unsigned char pad0, count; char pad2[0x12]; unsigned char ids[256]; };
struct Owner { char pad[0x234]; char state[0x90]; float values[256]; };
struct Entry { char pad[0x20]; float sign; char pad24[0x54]; float extra,a,b,result; char rest[0x64]; };
struct Obj { char pad[0x10]; Owner *owner; char pad14[0x150]; Entry entries[1]; };
extern "C" List *func_00359510(Owner *);
static inline int get(List *p, int i) { return i < p->count ? p->ids[i] : 0; }
extern "C" void func_0036D230(Obj *o) {
    Owner *own = o->owner;
    char *state = (char *)own + 0x234;
    List *p = func_00359510(own);
    for (int i = 0; i < p->count; ++i) {
        Entry *e = o->entries + i;
        int idx = get(p,i);
        float sign = e->sign;
        e->result = -*(float *)(state + idx * 4 + 0x90) * (e->a + e->b);
        if (sign != 0.0f) {
            if (sign > 0.0f) e->result -= e->extra;
            else e->result += e->extra;
        }
    }
}
