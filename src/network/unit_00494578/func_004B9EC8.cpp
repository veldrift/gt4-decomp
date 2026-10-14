/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00634F4C, D_00634F54, D_00634F5C, D_00634F64, D_00634F6C, D_00634F48;
extern "C" void free(int) throw();
extern "C" int func_004B9EC8(void) {
    if (D_00634F4C != 0) {
        free(D_00634F4C);
        D_00634F4C = 0;
    }
    if (D_00634F54 != 0) {
        free(D_00634F54);
        D_00634F54 = 0;
    }
    if (D_00634F5C != 0) {
        free(D_00634F5C);
        D_00634F5C = 0;
    }
    if (D_00634F64 != 0) {
        free(D_00634F64);
        D_00634F64 = 0;
    }
    if (D_00634F6C != 0) {
        free(D_00634F6C);
        D_00634F6C = 0;
    }
    D_00634F48 = 0;
    return 1;
}
