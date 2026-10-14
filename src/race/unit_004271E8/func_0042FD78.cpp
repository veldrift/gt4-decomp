struct O { char pad[0xA68]; int len; char buf[1]; };
extern "C" char *func_0042FD78(O *self) {
    int n = self->len;
    if (n <= 0) return 0;
    int i = n - 2;
    while (i >= 0 && self->buf[i] != 0) i--;
    n = i + 1;
    self->len = n;
    return (char *)self + n + 0xA6C;
}
