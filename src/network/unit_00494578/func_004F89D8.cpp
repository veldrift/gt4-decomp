/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef int s32;
struct E { char b[16]; };
struct Arr { E e[32]; s32 n; };
extern "C" s32 *func_004F8A68(Arr *, s32);
extern "C" void func_004F89D8(Arr *a, s32 k) {
    E *q = (E *)func_004F8A68(a, k);
    if (q) {
        E *end = &a->e[a->n];
        q++;
        if (q != end) {
            do {
                q[-1] = *q;
                q++;
            } while (q != end);
        }
        a->n = a->n - 1;
    }
}
