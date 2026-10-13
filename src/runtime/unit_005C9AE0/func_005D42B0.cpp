/* Element is 0x2C bytes with 4-byte alignment, so the struct copy goes through ldl/ldr pairs
   and a final lw/sw. The loop walks [arg0, arg1) with stride 0x2C, copying each element to a
   stack temporary whose address is passed as the second argument. */
struct Elem44 {
    char b[0x2C];
} __attribute__((aligned(4)));

extern "C" void func_005D47A0(char *arg0, char *arg1);

extern "C" void func_005D42B0(char *arg0, char *arg1)
{
    for (Elem44 *p = (Elem44 *)arg0; p != (Elem44 *)arg1; ++p) {
        Elem44 tmp = *p;
        func_005D47A0((char *)p, (char *)&tmp);
    }
}
