/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S;
struct Out { float x,y,z; };
struct In { int pad; S *self; };
extern "C" float func_00344AA8(S *, int);
extern "C" float func_00344B40(S *, int, float);
extern "C" float func_00344C08(S *, int, float);
extern "C" void *func_003D72A0(Out *out, In *in, int idx, float f) {
    int n = *((signed char *)in + idx + 12);
    float x = func_00344AA8(in->self,n);
    float y = func_00344B40(in->self,n,f);
    float z = func_00344C08(in->self,n,f);
    out->x=x;
    out->y=y;
    out->z=z;
    return out;
}
