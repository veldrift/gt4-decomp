/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern s32 D_006582AC;
extern char D_008866C0[];

/* Caller sets both $a0 (buffer) and $a1 (count) before each call. */
extern "C" void func_005B97B0(char *p, s32 n);

extern "C" void func_005AF500(s32 arg0) {
    s32 n = D_006582AC;
    if (n >= 0x7E) {
        D_006582AC = 0;
        D_008866C0[0x7F] = 0;
        func_005B97B0(D_008866C0, n);
        n = D_006582AC;
    }
    if (arg0 == 0xA) {
        D_006582AC = 0;
        D_008866C0[n] = (char)arg0;
        D_008866C0[n + 1] = 0;
        func_005B97B0(D_008866C0, n);
        return;
    }
    D_006582AC = n + 1;
    D_008866C0[n] = (char)arg0;
}
