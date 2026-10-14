/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
struct Payload { char d[0xE8]; };
struct Ent { int w0,w4; u32 id; Payload data; };
struct Ctx { char pad0[0xC]; u32 *id; char pad10[0x18]; u16 *input; int *status; char pad30[4]; Payload *data; int *state; char pad3C[4]; Ent *table; };
struct Out { char p[0x11]; char flag; char p12[6]; int w18; };
extern Ctx *D_006452D4;
extern "C" int func_004C93F8(void *);
extern "C" void func_004BC728(u16 *, void *);
extern "C" void func_004C8FD8(u16 *, u16 *);
extern "C" int func_004C4DE8(u16 *);
extern "C" void func_004BC6E8(Ctx *);
extern "C" void *func_004C3E98(void *, int, u32);
extern "C" int func_004C8ED0(u16 *);
extern "C" int func_004C2758(int,int,int,Out *);
extern "C" void func_004C4070(void *,const void *,u32) throw();
extern "C" void func_004C8F08(u16 *,u16 *);
extern "C" int func_004BFDA0(Ctx *,Out *,u16 *,int *,int);
static inline int valid(int n) { return n < 0x40; }
extern "C" int func_004BC428(void *arg0,int mode) {
 Out out;
 u16 buf[48];
 u16 tmp[48];
 Payload data;
 if (*D_006452D4->status == 0x65) return 0x80000279;
 if (mode != 0) { if (mode != 1) return 0x80000479; }
 if (!arg0) return 0x80001779;
 Payload *pd = &data;
 int n = func_004C93F8(arg0);
 if (n == 0 || n >= 0x2B || !valid(n)) return 0x80001179;
 func_004BC728(tmp,arg0);
 u16 *input = buf;
 func_004C8FD8(input,tmp);
 if (func_004C4DE8(input)) return 0x80001179;
 Ctx **gp = &D_006452D4;
 func_004BC6E8(*gp);
 func_004C3E98(&out,0,0x1C);
 func_004C2758(mode,func_004C8ED0(input),0,&out);
 out.flag = func_004C8ED0(input);
 out.w18 = 0;
 func_004C4070(pd,(*gp)->data,0xE8);
 u32 *idp = (*gp)->id;
 u32 id = *idp;
 if (id > 0x0FFFFFFE) *idp = 0; else *idp = id+1;
 Ctx **gp2 = &D_006452D4;
 func_004C8F08((*gp2)->input,input);
 int result = func_004BFDA0(*gp2,&out,(*gp2)->input,(*gp2)->state,1);
 if (result == 0) {
  Ent *t = (*gp2)->table;
  if (t->w4 <= 0) { t->w4++; }
  t = (*gp2)->table;
  int off = t->w0 * 0xEC;
  func_004C4070((char *)t+off+0xC,pd,0xE8);
  ((Ent *)((char *)(*gp2)->table+off))->id = id;
  t = (*gp2)->table;
  if (++t->w0 > 0) (*gp2)->table->w0 = 0;
 }
 return result;
}
