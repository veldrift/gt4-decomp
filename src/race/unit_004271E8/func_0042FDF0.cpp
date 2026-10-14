/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char pad[0xA68]; int len; char buf[1]; };
extern "C" char *func_0042FDF0(O *self, int n) {
    int len = self->len;
    if (len > 0) {
    int i = len - 1;
    for (int j = 0; j < n + 1; j++) {
        i--;
        while (i >= 0 && self->buf[i] != 0) i--;
    }
    if (i < -1) return 0;
    return (char *)self + i + 0xA6D;
    }
    return 0;
}
