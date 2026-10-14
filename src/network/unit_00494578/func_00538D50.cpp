struct R { int first; void *data; };
extern "C" int func_00538CC0(R *, int, unsigned short) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00538D50(R *p, int size, unsigned short mode) {
    if (p != 0) {
        if (size == 0) return 100;
        p->first = 0;
        p->data = 0;
        int r = func_00538CC0(p, size, mode);
        if (r != 0) return r;
        void *data = p->data;
        if (data != 0) {
            func_005A48D8(data, 0, size);
            return 0;
        }
    }
    return 100;
}
