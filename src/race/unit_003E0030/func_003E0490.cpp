/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int PDISTD__UNIT_MANAGER[];
extern char D_006A37F8[];
extern "C" float func_00472940(int *);
extern "C" char *func_00472680(int *);
extern "C" double func_0057FB50(float);
extern "C" int func_0057DA20(char *, const char *, ...);
struct Obj { int first; char text[0xB0]; int flag; };
extern "C" void func_003E0490(Obj *self) {
 int *p=PDISTD__UNIT_MANAGER;
 char *buf=self->text;
 float x=func_00472940(p);
 char *s=func_00472680(p);
 const char *fmt=D_006A37F8;
 func_0057DA20(buf,fmt,func_0057FB50(x+0x1.47ae14p-8f),s);
 self->flag=1;
}
