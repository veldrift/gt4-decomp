struct B { int w[11]; };
extern B D_00622E90;
extern B D_00622EC0;
extern B D_00622EF0;
extern B D_00622F20;
extern B D_006A6188, D_006A61B8;
static inline void ctor(B *const self, const B *const s) { *self = *s; }
extern "C" void func_00439B30(int init, int prio) {
    if (prio == 0xFFFF && init == 1) ctor(&D_00622E90, &D_006A6188);
    if (prio == 0xFFFF && init == 1) ctor(&D_00622EC0, &D_006A61B8);
    if (prio == 0xFFFF && init == 1) ctor(&D_00622EF0, &D_006A6188);
    if (prio == 0xFFFF && init == 1) ctor(&D_00622F20, &D_006A61B8);
}
