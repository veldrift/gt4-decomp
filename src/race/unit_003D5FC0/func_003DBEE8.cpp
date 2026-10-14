extern "C" char PDISTD__UNIT_MANAGER[];
extern "C" char D_006A3398[];

extern "C" void func_003B0370(char *out, int unused, int value);
extern "C" float func_00472C90(int *p, float x);
extern "C" void func_0057DA20(int arg0, int arg1, ...);

extern "C" void func_003DBEE8(char *arg0, int arg1, float fparg0, float fparg1) {
    int value;
    float q;

    if (fparg0 <= 0.0f) {
        *arg0 = 0;
        return;
    }
    if (fparg1 != 0.0f && fparg1 <= fparg0) {
        q = fparg0 / fparg1;
        func_003B0370(arg0, arg1, (int)q);
        return;
    }
    value = (int)(func_00472C90((int *)PDISTD__UNIT_MANAGER, fparg0) + 0.5f);
    func_0057DA20((int)arg0, (int)D_006A3398, value);
}
