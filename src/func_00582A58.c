/* compiler: ee-gcc2.9-991111 */
extern int D_00655EE8;
extern void *D_00655EF8;
int func_005ADCE0(int sema);
int func_005ADCC0(int sema);

void *func_00582A58(void *handler)
{
    void *old;

    func_005ADCE0(D_00655EE8);
    old = D_00655EF8;
    D_00655EF8 = handler;
    do { func_005ADCC0(D_00655EE8); } while (0);
    return old;
}
