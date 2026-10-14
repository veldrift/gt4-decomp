/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004307A0(void *, int);
extern "C" void func_00435268(void *, int);
extern "C" void func_004362E0(void *, int);
extern "C" void func_0043A1D0(void *, int) throw();
extern "C" void func_0043A408(void *, int);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, int);
extern "C" void func_005C1628(void *) throw();
extern "C" void func_00600A40(void *, int);
extern char D_006878C8[];
extern char D_00687908[];
extern char D_00687960[];
extern char D_006879A0[];
extern char D_006879E0[];
extern char D_00687A20[];
extern char D_00687A60[];
extern char D_00687AA0[];
extern char D_00687DD0[];
extern char D_00687E50[];
extern char D_00687E90[];
extern char D_00687F50[];
extern char D_00688280[];

static inline void base_dtor(char *p, char *vt) {
    *(void **)p = vt;
    func_0043A408(p, 0);
}
static inline void array_dtor(char *const owner) {
    *(void **)owner = D_00688280;
    if (owner != (char *)-8) {
        char *q = owner + 0x470;
        while (owner + 8 != q) {
            q -= 0x178;
            SPEC_DATABASE__CarEquipments__setVariationOrder(q, 2);
        }
    }
    func_0043A408(owner, 0);
}
static inline void small_array_dtor(char *const owner) {
    if (owner != (char *)-0xD8) {
        char *q = owner + 0x348;
        while (owner + 0xD8 != q) {
            q -= 0x68;
            func_004307A0(q, 2);
        }
    }
}
extern "C" void func_0043A5D8(char *arg0, int arg1) {
    char *temp_s0;
    char *temp_s1;
    char *temp_s1_2;
    char *temp_s3;
    char *temp_s3_2;
    char *temp_s4;
    char *temp_v0;
    char *temp_v0_2;
    char *var_s0;
    char *var_s0_2;
    char *var_s0_3;

    temp_s4 = arg0 + 0x3A368;
    temp_s3 = arg0 + 0x3A900;
    *(void **)(arg0 + 0) = D_00687E50;
    *(void **)temp_s4 = D_006879A0;
    array_dtor(temp_s3);
    temp_s1 = temp_s4 + 0xD8;
    array_dtor(temp_s1);
    char *part = arg0 + 0x568;
    temp_s3_2 = arg0 + 0x348;
    func_0043A408(temp_s4, 0);
    func_004362E0(arg0 + 0x38CB0, 2);
    *(void **)temp_s3_2 = D_00687E90;
    base_dtor(arg0 + 0x38C88, D_00687F50);
    base_dtor(arg0 + 0x38BF8, D_00687960);
    base_dtor(arg0 + 0x38B80, D_00687DD0);
    base_dtor(arg0 + 0x38A70, D_006879E0);
    base_dtor(arg0 + 0x38960, D_006879E0);
    base_dtor(arg0 + 0x36550, D_006878C8);
    base_dtor(arg0 + 0x26F30, D_00687A60);
    base_dtor(arg0 + 0x26640, D_00687AA0);
    base_dtor(arg0 + 0x14A30, D_00687AA0);
    base_dtor(arg0 + 0x13E28, D_00687A20);
    func_00435268(arg0 + 0xBC30, 2);
    *(void **)part = D_00687908;
    func_00600A40(arg0 + 0x570, 2);
    func_0043A408(part, 0);
    func_0043A408(temp_s3_2, 0);
    small_array_dtor(arg0);
    func_0043A1D0(arg0 + 4, 2);
    func_0043A408(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
