struct T { char p0[0xC]; float f0C, f10; char p1[0xC]; float f20, f24; char p2[0xC]; float f34, f38; };
struct In { T *p; };
struct A { char p0[4]; float f4, f8; In in; };
struct B { char p0[0x6E14]; void *x; };
union U { float f; T *p; };
extern "C" U *func_004A5B70(int);
extern "C" void func_00473000(void *, int, U *, int, int);
extern "C" void func_0047EEE8(A *a, B *b) {
    U *v = func_004A5B70(2);
    In *in = &a->in;
    v[0].f = a->f4;
    v[1].f = a->f8;
    v[2].f = in->p->f0C;
    v[3].f = in->p->f10;
    v[4].f = in->p->f34;
    v[5].f = in->p->f38;
    v[6].f = in->p->f20;
    v[7].f = in->p->f24;
    func_00473000(b->x, 4, v, 0, 0);
}
