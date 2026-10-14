/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; s32 (*fn)(void *, s32); };
struct VObj { char pad[4]; char *vt; };
struct H { VObj *p; char pad[0xC]; };
struct W { s32 v; char pad[0xC]; };
extern "C" void func_0022ACC8(void *, int);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_002C72B8(void *, int) throw();
extern "C" void func_002C7310(void *, s32) throw();
extern "C" void func_002C9B68(s32, s32, s32 *, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" s32 hArray__size(void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, s32);
extern "C" int func_002FE250(s32);
extern "C" void free(void *) throw();
extern "C" s32 *malloc(s32) throw();
extern "C" void MOptionMenu__setInsensitive(void *arg0, s32 arg1, s32 n, char *list) {
    if (n < 2) return;
    s32 sp0[4];
    H arr;
    W w;
    func_0022AD20(sp0, list);
    H *pa = &arr;
    s32 i = 0;
    func_002ED618(pa, list + 4);
    s32 cnt = hArray__size(pa->p);
    s32 *buf = malloc(cnt * 4);
    W *pw;
    if (cnt > 0) {
        pw = &w;
        s32 *q = buf;
        do {
            W *lw = &w;
            VObj *o = pa->p;
            E *e = (E *)(o->vt + 0x70);
            s32 idx = i;
            i++;
            func_002FC8C8(lw, e->fn((char *)o + e->d, idx));
            *q = func_002FE250(lw->v) != 0;
            q++;
            func_002FC870(lw, 2);
        } while (i < cnt);
    } else {
        pw = &w;
    }
    func_002C7310(pw, arg1);
    func_002C9B68(pw->v, sp0[0], buf, cnt);
    func_002C72B8(pw, 2);
    free(buf);
    func_002ED5C0(pa, 2);
    func_0022ACC8(sp0, 2);
}
