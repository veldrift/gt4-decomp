/* compiler: ee-gcc2.96-no-strict-aliasing */
struct A { char pad[0x940]; float entries[48]; };
struct B { char pad[0x7B0]; float entries[208]; };
extern "C" signed char func_00344E98(void *, char *) throw();
extern "C" void func_00344FC0(char *self, float *out, char *arg2, float f) {
    int i = func_00344E98(self, arg2);
    float t = f + *(float *)(self + 0x554);
    A *a = (A *)(self + 0x10);
    float u = 1.0f - t;
    B *b = (B *)(self + 8);
    out[0] = a->entries[i * 3] * t + b->entries[i * 13] * u;
    self += i * 0xEC;
    out[1] = a->entries[i * 3 + 1] * t + *(float *)(self + 0x1F0) * u;
    out[2] = a->entries[i * 3 + 2] * t + b->entries[i * 13 + 2] * u;
}
