/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec {
 float x,y,z,w;
 static inline void set(Vec *p, float a) { p->x=a; p->y=a; p->z=a; p->w=a; }
 Vec() { set(this,0.0f); }
};
struct Root { int a,b,c; virtual ~Root(); };
struct ResultArcade__structor_0 : Root {
 ResultArcade__structor_0() throw();
 virtual ~ResultArcade__structor_0();
 char pad[0x4F0];
};
struct ResultLicense__vtable : ResultArcade__structor_0 {
 char flag; char p501[0x3F]; int f540; char p544[0x20];
 int f564,f568,f56c,f570,f574,f578,f57c,f580;
 Vec a1[3],a2[3],a3[3],last;
 ResultLicense__vtable() __asm__("func_003E0768");
 virtual ~ResultLicense__vtable();
};
ResultLicense__vtable::ResultLicense__vtable() : f564(0),f56c(0),f570(0),f574(0),f578(0),f57c(0) {
 flag=0; f540=0;
}
