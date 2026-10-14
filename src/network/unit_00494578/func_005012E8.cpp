/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char data[0x4c]; };
struct Obj {
 char pad0[0x98];
 int f98,f9c,fa0,fa4;
 char pada8[8];
 int fb0,fb4;
 char padb8[0x1c4-0xb8];
 Node *nodes;
 int count;
 char list[12],l1[12],l2[12],l3[12];
 char pad1fc[4];
 int f200,f204,f208,f20c,f210,f214;
 char rest[1];
};
extern Node D_00649548[];
extern int D_006497A8;
extern "C" {
int func_00500F70(void *) throw();
int func_00501A28(void *);
void func_00574D78(void *);
void func_00576090();
void func_0057CB00(void *,void *);
void func_0060F168(void *);
void func_0060F198(void *);
void func_0060F238(void *);
int func_0060F2D8(void *);
}
extern "C" int func_005012E8(Obj *s) {
 char *p = (char *)s + 0x630;
 int i = 15;
 char *list = s->list;
 func_00576090();
 func_00574D78((char *)s+8);
 func_00574D78((char *)s+0x38);
 func_00574D78((char *)s+0x68);
 s->f98=0;
 s->f9c=0x80;
 s->fa0=0x804;
 s->fb0=0x272e;
 s->fb4=-1;
 s->fa4=0;
 func_00500F70((char *)s+0xb8);
 s->nodes=D_00649548;
 s->count=D_006497A8;
 func_0060F168(list);
 func_0060F168(s->l1);
 func_0060F168(s->l2);
 func_0060F168(s->l3);
 s->f200=0;
 s->f208=0;
 s->f204=1;
 s->f20c=0;
 s->f210=0;
 s->f214=0;
 func_0060F198((char *)s+0x218);
 char *arg=p;
 do {
  p+=0x418;
  i--;
  func_0060F198(arg);
  arg=p;
 } while(i!=-1);
 i=0;
 func_0060F238((char *)s+0x47b0);
 func_0060F238((char *)s+0x67d8);
 func_0060F2D8((char *)s+0x8800);
 if(s->count>0) {
  int off=0;
  do {
   i++;
   char *node=(char *)s->nodes+off;
   off+=0x4c;
   func_0057CB00(list,node);
  } while(i<s->count);
 }
 return func_00501A28(s);
}
