/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { float v[4]; };
struct Self { char p[0x9140]; Row rows[1]; };
extern "C" float func_00344C88(void *, int);
extern "C" float func_003CC980(float) throw() __attribute__((const));
extern "C" int func_003CD900(Self *, int, int) throw();

extern "C" void func_003CE178(Self *self, int idx, void *owner)
{
    self->rows[idx].v[0] = func_003CC980(func_00344C88(owner, func_003CD900(self, idx, 0)));
    self->rows[idx].v[1] = func_003CC980(func_00344C88(owner, func_003CD900(self, idx, 1)));
    self->rows[idx].v[2] = func_003CC980(func_00344C88(owner, func_003CD900(self, idx, 2)));
    self->rows[idx].v[3] = func_003CC980(func_00344C88(owner, func_003CD900(self, idx, 3)));
}
