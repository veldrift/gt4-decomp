/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00578500(int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" int func_00578168(void *, int, int, void *, int);
struct S { int handle; char pad[0x3c]; int a, b, c; char pad2[8]; char name[1]; };
extern "C" int func_00550B88(S *self, int type, int a, int b, int c, const char *name) {
    int size = 128;
    char buffer[size];
    int *result = (int *)(((int)buffer + 63) & -64);
    func_00578500(self->handle);
    self->a = a;
    self->b = b;
    self->c = c;
    self->name[0] = 0;
    if (name) func_005A609C(self->name, name);
    func_00578168(self, type, 0, result, 64);
    return *result;
}
