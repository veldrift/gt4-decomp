struct Node { int len; Node *next; };
struct Hdr { char c[0x18]; };
struct Obj { char pad0[8]; int f8; char padc[4]; int f10; int f14; };
struct IOV { char *p; int len; };
struct IOVec {
    IOV v[8]; int total; int count;
    IOVec() { count = 0; total = 0; }
};
extern "C" int func_0052D448(Obj *, int) throw();
extern "C" void func_0052D4E0(void *) throw();
extern "C" void func_0052D5A8(Obj *, void *, IOVec *) throw();
extern "C" void *func_0052DD98(Obj *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_0052DE00(Obj *arg0, void **arg1) {
    Hdr saved;
    if (arg0 == 0 || arg0->f10 == 0 || arg0->f14 == 0 || arg0->f8 == 0) return 2;
    saved = *(Hdr *)arg0;
    func_005A48D8(arg0, 0, 0x18);
    int r = func_0052D448(arg0, *(int *)(saved.c + 8));
    Node *n = *(Node **)(saved.c + 0x14);
    if (r != 0) {
        *(Hdr *)arg0 = saved;
        return r;
    }
    if (n != 0) {
        do {
            void *a1 = func_0052DD98(arg0);
            IOVec iov;
            int k = iov.count;
            iov.v[k].p = n ? (char *)n + 8 : 0;
            iov.v[k].len = n ? n->len : 0;
            int t = iov.total;
            if (n) t += n->len;
            iov.total = t;
            iov.count = iov.count + 1;
            func_0052D5A8(arg0, a1, &iov);
            if (arg1 != 0 && n == *arg1) *arg1 = func_0052DD98(arg0);
            n = n->next;
        } while (n != 0);
    }
    func_0052D4E0(&saved);
    return 0;
}
