extern "C" unsigned char *func_00515EC8(int) throw();
extern "C" int func_0051A4E8(unsigned int count) {
    if (count >= 512) return -1;
    for (int i=0; i<(int)(512-count); i++) {
        unsigned char *p=func_00515EC8(i);
        if (p && !*p) {
            int good=1;
            for (int j=i+1; j<(int)(i+count); j++) {
                if (*func_00515EC8(j)) { good=0; break; }
            }
            if (good) return i;
        }
    }
    return -1;
}
