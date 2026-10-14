struct B { long long a[0x2D7]; };
struct O { char pad[0x38CB0]; int first; };
extern "C" void func_0043A970(O *self, B *src) {
    B *dst = (B *)&self->first;
    if (src != dst) {
        volatile int sv = self->first;
        *dst = *src;
        self->first = sv;
    }
}
