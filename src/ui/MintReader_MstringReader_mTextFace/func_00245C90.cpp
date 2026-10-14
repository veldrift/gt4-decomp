/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[0x104]; void *text; };
struct Face { char pad[0x14]; void *font; char pad18[12]; float scale; char pad28[8]; float x; char pad34[0x34]; int mode; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_00699158[];
extern Face *PDISTD__global_font_manager;
extern "C" void func_002B74B0(Str *, void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
extern "C" float func_00231420(void *);
extern "C" char *func_002314E8(void *);
extern "C" char *func_00245A28(char **, int *) throw();
extern "C" int func_00245B48(char **, char *, int, float *, float, float) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" unsigned char func_00491AC0(void *);
extern "C" float func_00490B38(Face *, const char *);
extern "C" void func_00490A08(Face *, const char *, const char *);
extern "C" int func_00490660(Face *, float);
extern "C" void func_00490760(Face *);
static inline Rep *rep(Str *s) { return (Rep *)s->p-1; }
static inline char *repdata(Rep *r) { return (char *)(r+1); }
static inline char *cstr(Str *s) {
 int n = ((Rep *)(s->p-16))->len;
 if (n == 0) return D_00699158;
 s->p[n] = 0;
 return repdata(rep(s));
}
static inline void release(Str *s) {
 Rep *r = (Rep *)(s->p-16);
 if (--r->ref == 0) {
  int size = r->cap + 16;
  func_00326798(r,size,4,func_005C11A8()->name);
 }
}
extern "C" void func_00245C90(Obj *o, void *ctx) {
 Str str, a, b;
 char *cursor;
 int newline;
 char *words[32];
 char buf[64];
 float partial;
 void **text = &o->text;
 func_002B74B0(&str,*text);
 char *check = cstr(&str);
 release(&str);
 if (!check) return;
 Str *pa = &a;
 Str *ps = &str;
 func_002B74B0(pa,*text);
 char *source = pa->p;
 Str *pb = &b;
 func_002B74B0(pb,*text);
 int length = ((Rep *)(pb->p-16))->len;
 char *data;
 if (D_00659FA8.sel) data=func_005C2560(&D_00659FA8);
 else { ++D_00659FA8.ref; data=(char *)(&D_00659FA8+1); }
 ps->p=data;
 func_005C2630(ps,0,-1,source,length);
 release(pb);
 release(pa);
 cursor=cstr(&str);
 float width=func_00231420(ctx);
 newline=0;
 char *carry=0;
 int end=0;
 float space=(float)func_00491AC0(PDISTD__global_font_manager->font)*PDISTD__global_font_manager->scale;
 do {
  float used=0.0f;
  char **word=words;
  int count;
  for(count=0;count<32;count++,word++) {
   if(carry) { words[count]=carry; carry=0; }
   else words[count]=func_00245A28(&cursor,&newline);
   if(func_0057F260(cursor)==0) end=1;
   PDISTD__global_font_manager->mode=0;
   float w;
   if(*words[count]) w=func_00490B38(PDISTD__global_font_manager,words[count]);
   else w=0.0f;
   int full=width<=used+w;
   if(newline || full || w==0.0f || end) {
    float extra=0.0f;
    PDISTD__global_font_manager->x=extra;
    if(count<=0) {
     PDISTD__global_font_manager->mode=0;
     func_00490A08(PDISTD__global_font_manager,words[0],func_002314E8(ctx));
    } else if(full) {
     int split=func_00245B48(word,buf,64,&partial,w,width-used);
     if(split) used+=partial;
     int gaps;
     if(split == 0) gaps=count-1; else gaps=count;
     if(count>=2) used=space+(width-used)/(float)gaps;
     else used=space+extra;
     float limit=space*2.5f;
     if(limit<used) used=limit;
     for(int i=0;i<count;i++) {
      PDISTD__global_font_manager->mode=0;
      func_00490A08(PDISTD__global_font_manager,words[i],func_002314E8(ctx));
      func_00490660(PDISTD__global_font_manager,used);
     }
     if(split) {
      PDISTD__global_font_manager->mode=0;
      func_00490A08(PDISTD__global_font_manager,buf,func_002314E8(ctx));
     }
     carry=words[count];
    } else {
     for(int i=0;i<=count;i++) {
      PDISTD__global_font_manager->mode=0;
      func_00490A08(PDISTD__global_font_manager,words[i],func_002314E8(ctx));
      func_00490660(PDISTD__global_font_manager,space);
     }
    }
    PDISTD__global_font_manager->mode=1;
    func_00490760(PDISTD__global_font_manager);
    break;
   }
   used+=w+space;
  }
  if(count>=32) for(int i=0;i<count;i++) { }
 } while(!end || carry);
 release(&str);
}
