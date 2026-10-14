/* compiler: ee-gcc2.96-no-strict-aliasing */
struct L { L *next; void *obj; };
struct P { void *a; int b; };
extern char D_0084B480[];
extern L D_0084B538;
extern P D_0084B540;
extern char D_0084B548[];
extern char D_0084B5A0[];
extern L *D_006318BC;
extern "C" void func_004AC490(void *);
extern "C" void func_004AC530(void *, int) throw();
extern "C" void func_00575188(void *, void *);
extern "C" void func_005751D0(void *, int);
static inline void link(L *const self, void *const obj) {
    self->next = D_006318BC;
    self->obj = obj;
    D_006318BC = self;
}
static inline void buffer(P *const self, void *data, int size) {
    self->a = data;
    self->b = size;
}
extern "C" void func_004AC808(int init, int prio) {
    if (prio == 0xFFFF && init == 1) func_004AC490(D_0084B480);
    if (prio == 0xFFFF && init == 1) link(&D_0084B538, D_0084B480);
    if (prio == 0xFFFF && init == 1) buffer(&D_0084B540, D_0084B5A0, 0x2000);
    if (prio == 0xFFFF && init == 1) func_00575188(D_0084B548, &D_0084B540);
    if (prio == 0xFFFF && init == 0) func_005751D0(D_0084B548, 2);
    if (prio == 0xFFFF && init == 0) func_004AC530(D_0084B480, 2);
}
