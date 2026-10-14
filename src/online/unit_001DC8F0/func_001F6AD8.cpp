struct S { char pad[0xCC4]; int value; };
extern "C" S D_00645570;
extern "C" int func_004F9E60(S *, int);
extern "C" void func_004F9EC0(S *, int);
extern "C" void func_001F6AD8() { func_004F9EC0(&D_00645570, func_004F9E60(&D_00645570, D_00645570.value)); }
