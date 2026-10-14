/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V4 { char pad[0x10]; };
struct H { void *p; char pad[0xC]; };
extern "C" {
void func_0013BD68(void *, int) throw();
void func_0013BDC0(void *) throw();
s32 func_00145C08(void *);
void func_00145C30(void *, V4 *, s32);
void func_002030A0(V4 *);
void func_00203118(V4 *, int);
void func_00203620(void *, int);
void func_00204558(void *, V4 *);
void func_002ED5C0(void *, int);
void *func_002EEEB0(void *, void *, void *);
void func_002EFBF0(void *);
void func_00309378(void *, s32);
void func_003285A8(void *);
void func_003285F8(void *);

void MCarGarage__getAllColors(void **arg0) {
    void *obj;
    V4 arr[64];
    H h;
    H tmp;
    V4 v;
    int i;
    func_0013BDC0(&obj);
    s32 n = func_00145C08(obj);
    V4 *pp = arr;
    for (i = 63; i != -1; i--) { func_002030A0(pp); pp++; }
    func_00145C30(obj, arr, 0x40);
    H *ph = &h;
    func_002EFBF0(ph);
    H *p_tmp;
    if (n > 0) {
        p_tmp = &tmp;
        V4 *q = arr;
        i = n;
        do {
            void *hp = ph->p;
            i--;
            func_00204558(&v, q);
            func_002EEEB0(p_tmp, hp, &v);
            q++;
            func_00309378(p_tmp, 2);
            func_00203620(&v, 2);
        } while (i != 0);
    }
    if (arg0 != &ph->p) {
        void *p = ph->p;
        if (p != 0) func_003285A8(p);
        if (*arg0 != 0) func_003285F8(*arg0);
        *arg0 = p;
    }
    func_002ED5C0(ph, 2);
    V4 *c = (V4 *)ph;
    if (arr != c) {
        do {
            c--;
            func_00203118(c, 2);
        } while (arr != c);
    }
    func_0013BD68(&obj, 2);
}
}
