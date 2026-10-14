/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Offsets { int v[3]; };
extern "C" Offsets D_006B9C00;
extern "C" int func_004C58A8(unsigned char *p) {
    Offsets offsets = D_006B9C00;
    for (int i = 0; i < 3; i++) {
        int off = offsets.v[i];
        if (*(unsigned char *)(off + (int)p - 1000) == 32) {
            int start = off - 999;
            int found = 0;
            for (int j = 0; j < 3; j++) {
                if (p[start + j] != 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) return -1;
        }
    }
    return 0;
}
