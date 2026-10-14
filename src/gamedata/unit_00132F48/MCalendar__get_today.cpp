/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" {
void func_00132D60(void *, int) throw();
void func_00132DB8(void *, void *) throw();
void func_001375B0(void *, s32 *, s32 *, s32 *);
void func_002ED5C0(void *, int);
void *func_002EEEB0(void *, void *, void *);
void func_002EFBF0(void *);
void func_002FC870(void *, int);
void func_002FE278(void *, s32);
void func_00309378(void *, s32);
void func_003285A8(void *);
void func_003285F8(void *);

void MCalendar__get_today(void **arg0, void *arg1) {
    s32 v[3];
    void *h[4];
    void *tmp[4];
    void *a[4];
    void *b[4];
    void *c[4];
    void **ph = h;
    func_00132DB8(ph, arg1);
    func_001375B0(ph[0], &v[0], &v[1], &v[2]);
    func_00132D60(ph, 2);
    func_002EFBF0(ph);
    void *s2 = ph[0];
    void **pt = tmp;
    func_002FE278(a, v[0]);
    func_002EEEB0(pt, s2, a);
    func_00309378(pt, 2);
    func_002FC870(a, 2);
    s2 = ph[0];
    func_002FE278(b, v[1]);
    func_002EEEB0(pt, s2, b);
    func_00309378(pt, 2);
    func_002FC870(b, 2);
    s2 = ph[0];
    func_002FE278(c, v[2]);
    func_002EEEB0(pt, s2, c);
    func_00309378(pt, 2);
    func_002FC870(c, 2);
    if (arg0 != ph) {
        void *p = ph[0];
        if (p != 0) func_003285A8(p);
        if (*arg0 != 0) func_003285F8(*arg0);
        *arg0 = p;
    }
    func_002ED5C0(ph, 2);
}
}
