/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int data[65]; };
extern char D_00645570[];
extern "C" void func_004F6E28(Blob *src, char *dst) {
 if (dst == 0) dst = D_00645570;
 *(Blob *)(dst + 0xBAC) = *src;
}
