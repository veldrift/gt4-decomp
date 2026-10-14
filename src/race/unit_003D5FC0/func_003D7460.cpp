/* compiler: ee-gcc2.96-no-strict-aliasing */
struct R { int n; char pad[0x30]; };
struct Data { char pad[0x7c4]; R r[4]; };
struct S { int pad; Data *data; };
struct Out { int n; float a,b; };
extern "C" float func_00344F40(Data *, int, float);
extern "C" float func_00344EC8(Data *, int, float);
extern "C" void *func_003D7460(Out *out, S *s) {
    float b=0.0f;
    int n=-1;
    float a=0.0f;
    int off=0;
    for(int i=0;i<4;i++,off+=0x34) {
        a += func_00344F40(s->data,i,0.0f);
        b += func_00344EC8(s->data,i,0.0f);
        if(n<0) n=*(int *)((char *)s->data+off+0x7c4);
    }
    out->n=n;
    out->a=a*0.25f;
    out->b=b*0.25f;
    return out;
}
