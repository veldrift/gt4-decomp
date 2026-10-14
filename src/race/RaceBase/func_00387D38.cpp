/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *); };
struct Obj { char pad0[0x64]; char *vt; char pad68[0xc58]; int mode; int x; int signal; int last; };
static inline void set(int &last, Obj *p, const int &value) {
    if (value != last) {
        last = value;
        switch (p->mode) {
        case 0: case 1:
            switch(value) { case 0: p->signal = 0; break; case 1: p->signal = 1; break; }
            break;
        case 2: case 3:
            switch(value) { case 0: p->signal = 2; break; case 1: p->signal = 3; break; }
            break;
        }
        VEntry *e = (VEntry *)(p->vt + 0x98);
        e->fn((char *)p + e->delta);
    }
}
extern "C" void func_00387D38(Obj *p, int value) { set(p->last, p, value); }
