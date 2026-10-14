/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; s32 (*fn)(void *); };
struct VObj { char pad[4]; char *vt; };
struct H { VObj *p; char pad[0xC]; };
struct Ev { char pad[0x20]; s32 key; };
struct M { char pad[0xFC]; s32 fc; };
extern "C" s32 func_002319C0(char *);
extern "C" void *func_00235C00(char *);
extern "C" s32 mWidget__onKeyPress(void *, void *, void *);
extern "C" void func_00277438(void *, int);
extern "C" void func_00277850(void *, void *, void *);
extern "C" void func_00282968(void *, int);
extern "C" void func_00282D80(void *, void *, void *);
extern "C" void func_002C8DD0(void *, void *) throw();
extern "C" s32 func_002C98F0(void *, int);
extern "C" s32 mOptionMenu__virtual_71(M *self, char *arg1, Ev *ev) {
    s32 key = ev->key;
    if (self->fc != 0) {
        s32 r = 0;
        if (key == 0xFF52 || key == 0xFF97)
            r = func_002C98F0(self, -1);
        else if (key == 0xFF54 || key == 0xFF99)
            r = func_002C98F0(self, 1);
        if (r != 0)
            func_002C8DD0(self, arg1);
        s32 w = func_002319C0(arg1);
        if (w != 0) {
            if (key == 0xFF0D) {
                H h;
                func_00277850(&h, arg1, func_00235C00((char *)w));
                E *e = (E *)(h.p->vt + 0x190);
                e->fn((char *)h.p + e->d);
                func_00277438(&h, 2);
            } else if (key == 0xFF1B) {
                H h;
                func_00282D80(&h, arg1, func_00235C00((char *)w));
                E *e = (E *)(h.p->vt + 0x190);
                e->fn((char *)h.p + e->d);
                func_00282968(&h, 2);
            }
        }
        return 2;
    }
    return mWidget__onKeyPress(self, arg1, ev);
}
