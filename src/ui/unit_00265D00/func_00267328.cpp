/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Type { const char *name; };
struct Str;
extern "C" {
extern Rep D_00659FA8;
extern char D_00699FF8[];
void *func_0025C298(void *) throw();
void *hModule__getName(void *);
Type *func_005C11A8();
void func_00326798(void *,int,int,const char *);
char *func_005C2560(Rep *);
int func_0057F260(const char *) throw();
Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
Str *func_005CE388(Str *,unsigned,unsigned,const Str *,unsigned,unsigned);
}
struct Str {
 char *p;
 Str() {
  Rep *r=&D_00659FA8;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); int n=r->ref+1; r->ref=n; }
  p=d;
 }
 Str(const Str &s) {
  Rep *r=(Rep *)(s.p-16);
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=s.p; int n=r->ref+1; r->ref=n; }
  p=d;
 }
 ~Str() {
  Rep *r=(Rep *)(p-16);
  if(--r->ref==0) {
   int size=r->cap+16;
   func_00326798(r,size,4,func_005C11A8()->name);
  }
 }
 Str &operator=(const Str &s) {
  if(&s!=this) {
   Rep *r=(Rep *)(p-16);
   if(--r->ref==0) {
    int size=r->cap+16;
    func_00326798(r,size,4,func_005C11A8()->name);
   }
   char *d=s.p;
   Rep *r2=(Rep *)(d-16);
   if(r2->sel) d=func_005C2560(r2);
   else { int n=r2->ref+1; r2->ref=n; }
   p=d;
  }
  return *this;
 }
 void append(const char *s) {
  func_005C2630(this,((Rep *)(p-16))->len,0,s,func_0057F260(s));
 }
 void append(const Str &s) {
  func_005CE388(this,((Rep *)(p-16))->len,0,&s,0,-1);
 }
};
static inline Str add(const Str &s,const char *text) {
 Str t(s);
 t.append(text);
 return t;
}
extern "C" Str func_002670F8(void *) throw();
extern "C" Str func_00267328(void *self, void *stop) {
 Str s;
 if(func_0025C298(self)!=stop) {
  s=add(func_00267328(func_0025C298(self),stop),D_00699FF8);
 }
 s.append(func_002670F8(hModule__getName(self)));
 return s;
}
