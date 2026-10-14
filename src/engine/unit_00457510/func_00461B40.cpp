/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { int index; void *p; int a, b, c; void *dev; };
extern State D_008468D0;
extern char D_008468E8[];
extern "C" void func_00574D78(void *);
extern "C" void func_00574DA8(void *, int);
extern "C" void func_00461B40(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        State *s = &D_008468D0;
        s->index = -1;
        s->a = 0;
        s->b = 0;
        s->c = 0;
        s->dev = 0;
        s->p = 0;
    }
    if (prio == 0xFFFF && init == 1) func_00574D78(D_008468E8);
    if (prio == 0xFFFF && init == 0) func_00574DA8(D_008468E8, 2);
}
