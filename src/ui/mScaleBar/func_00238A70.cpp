/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00238F58(void *);
extern "C" int func_00238A70(void *self, int key) {
    if (func_00238F58(self)) {
        switch (key) {
        case 0xFEE4:
        case 0xFEE6:
        case 0xFF51:
        case 0xFF96: return 1;
        default: return 0;
        }
    } else {
        switch (key) {
        case 0xFEE4:
        case 0xFEE5:
        case 0xFF52:
        case 0xFF97: return 1;
        default: return 0;
        }
    }
}
