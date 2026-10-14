/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int Automobile__GetExplicitCurrentLap(void *);
extern "C" void *func_0034C190(void *, int);
extern "C" int func_003FA360(char *self, int row, unsigned char col, short *out) {
 *out = Automobile__GetExplicitCurrentLap(func_0034C190(self, row));
 return *(int *)(self + ((row * 16 + col) * 4) + 0xd624);
}
