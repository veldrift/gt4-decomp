typedef int s32;

extern char D_006235A8[];
extern s32 PDISTD__LOCALE;
extern s32 D_00623800[];

/* This caller sets $a0 and $a1, so the callee is declared with both. */
void func_00443770(s32 a0, s32 a1);

void func_0044A5D0(void) {
    s32 i;
    s32 *p;
    func_00443770((s32)D_006235A8, PDISTD__LOCALE);
    p = D_00623800;
    p += 3;
    for (i = 3; i >= 0; i--) {
        *p = 0;
        p--;
    }
}
