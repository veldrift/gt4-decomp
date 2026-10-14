extern unsigned int D_0064AE10;
extern void **D_0064AE14;
extern "C" int func_0051DC58(void *) throw();
extern "C" int func_0051DCF8(unsigned int index) {
 void **table = D_0064AE14;
 if (!table) return 0;
 if (index >= D_0064AE10) return 0;
 return func_0051DC58(table[index]);
}
