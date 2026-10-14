/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char data[100]; int a,b,c; short d,e,f,g,h; char pad[6]; };
extern char D_006C1350[];
extern "C" void func_00506408(S *,void *);
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern "C" int func_00506540(S *);
extern "C" int func_00506668();
extern "C" int func_004F71D0() {
    S s;
    func_00506408(&s,D_006C1350);
    func_005A6AB0(&s,D_006C1350,100);
    s.a=2; s.b=1; s.c=0x400;
    s.d=10; s.e=100; s.f=10; s.g=40; s.h=0;
    if(func_00506540(&s)!=0) return 0;
    return func_00506668()==0;
}
