/* compiler: ee-gcc2.96-nogcse */
extern char *D_0062399C;
extern int D_006239A0;
extern "C" void func_0045FD48(char *) throw();
extern "C" int func_00547C00(void);
extern "C" char *func_004601A8(void) {
    char **p = &D_0062399C;
    if (*p != 0) {
        int *ready = &D_006239A0;
        if (*ready == 0) {
            int result = func_00547C00();
            if (result == 0) return (char *)result;
            func_0045FD48(*p);
            *ready = 1;
        }
        return *p;
    }
    return 0;
}
