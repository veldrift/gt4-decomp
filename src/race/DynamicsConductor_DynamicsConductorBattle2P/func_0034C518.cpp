/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0046BB48(void *, unsigned);
extern "C" int func_0046B480(void *, int, int, float *, float *, float *, int *, int *, float);
extern "C" int func_0046B7B8(void *, int, int, float, float *, float *, float *, int *, int *);
extern "C" int func_0034C518(char *self, unsigned n, int start, float *out, float t) {
    void *p = self + 0xDA50;
    int k = func_0046BB48(p, n);
    if (k == -1) return k;
    {
        if (k != 4) func_0046B480(p, k, start, out, out+2, out+1, 0, 0, t);
        else func_0046B7B8(p, 4, start, t, out, out+2, out+1, 0, 0);
        out[2] = -out[2];
    }
}
