/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004C94A0(unsigned *, const unsigned *, const unsigned *) throw();
extern "C" int func_004C9518(int *) throw();
extern int D_006B9B98[];
extern signed char D_006B9DC8[];
struct Entry { unsigned v[10]; };
extern Entry D_006B9E40[];
extern "C" int func_004C9658(short arg0, unsigned *arg1) {
    if (arg0 == -1) { func_004C9518((int *)arg1); return 0; }
    if (arg0 >= 400) {
        int packed = D_006B9B98[arg0];
        func_004C9518((int *)arg1);
        int count = 3;
        int id = packed & 255;
        do {
            if (id != 0 && id < 119) {
                int v = D_006B9DC8[id];
                if (v != -1) func_004C94A0(arg1, D_006B9E40[v].v, arg1);
            }
        } while (count-- > 0);
    } else {
        func_004C94A0(arg1, D_006B9E40[D_006B9DC8[arg0]].v, 0);
    }
    return 1;
}
