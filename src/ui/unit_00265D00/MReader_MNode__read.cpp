/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,int,const char *);
extern "C" u32 func_0057F260(const char *) throw();
struct Rep {
 u32 len,res,ref,selfish;
 char *data(){return (char *)(this+1);}
 char *grab();
 static void operator delete(void *p,u32 n){func_00326798(p,n,4,func_005C11A8()->name);}
 void release(){if(--ref==0) operator delete(this,sizeof(Rep)+res);}
};
extern "C" char *func_005C2560(Rep *);
extern Rep D_00659FA8;
inline char *Rep::grab(){if(selfish)return func_005C2560(this); ++ref;return data();}
struct String;
extern "C" String *func_005C2630(String *,u32,u32,const char *,u32);
extern "C" String *func_005CE388(String *,u32,u32,const String *,u32,u32);
extern "C" int func_005CD320(const String *,const char *,u32,u32);
extern char D_0069A100[],D_0069A140[],D_0069A148[],D_0069A168[],D_0069A170[],D_0069A180[],D_0069A188[],D_0069A198[],D_0069A1A0[];
struct String {
 char *dat;
 Rep *rep()const{return (Rep *)dat-1;}
 String():dat(D_00659FA8.grab()){}
 String(const String &s):dat(s.rep()->grab()){}
 String(const char *s):dat(D_00659FA8.grab()){func_005C2630(this,0,-1,s,func_0057F260(s));}
 ~String(){rep()->release();}
 u32 length()const{return rep()->len;}
 const char *c_str()const{if(length()==0)return D_0069A180; dat[length()]=0;return dat;}
 int compare(const char *s)const{return func_005CD320(this,s,0,func_0057F260(s));}
 void append(const char *s,u32 n){func_005C2630(this,length(),0,s,n);}
 void append(const char *s){append(s,func_0057F260(s));}
 void append(const String &s){func_005CE388(this,length(),0,&s,0,-1);}
 String &operator=(const String &s){if(&s!=this){rep()->release();dat=s.rep()->grab();}return *this;}
};
struct VEntry {short delta,pad; int (*fn)(void *,void *);};
struct Node {int x; VEntry *vt;};
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_002550B8(void *,int);
struct Handle {Node *p; Handle &operator=(const Handle &s){if(this!=&s){Node *q=s.p;if(q)func_003285A8(q);if(p)func_003285F8(p);p=q;}return *this;} ~Handle(){func_002550B8(this,2);} };
struct Obj {int x;Handle *p;};
struct Reader {String str;int a,b;String current;};
extern "C" int func_0020EEA0(void *,void *);
extern "C" void func_0020FC58(void *,int);
extern "C" void func_00211408(void *,int);
extern "C" void func_002117A0(void *);
extern "C" void func_00213090(void *,void *,const String *);
extern "C" int func_00265D98(void *);
extern "C" void func_00265F80(void *,int);
extern "C" int func_00267698(void *);
extern "C" void func_002676A8(void *,int);
extern "C" bool func_00269290(void *,void *) throw();
extern "C" void *func_0030C2C8(void *);
extern "C" void HOutput__printf(void *,const char *,...);
extern "C" String func_0030D608(const String &);
extern "C" String func_00326388(const char *,const char *,int,const char *,const String &);
struct Output {int a,b;char *dat;Output(){func_0030C2C8(this);} ~Output(){((Rep *)dat-1)->release();} };
struct Buffer {void *p;char pad[12]; void *get(){return p;} ~Buffer(){func_00211408(this,2);} };
extern "C" void MReader_MNode__read(Obj *self,Reader *reader,const String &type){
 if(type.compare(D_0069A140)==0){
  Output out;
  String msg=func_00326388(D_0069A168,D_0069A170,44,D_0069A100,String(D_0069A148));
  HOutput__printf(&out,msg.c_str());
 }else if(type.compare(D_0069A188)==0){
  String token;
  func_0020EEA0(reader,&token);
  if(func_0020EEA0(reader,&token)==0x102){
   String path=func_0030D608(String(reader->str));
   path.append(D_0069A198);path.append(token);path.append(D_0069A1A0);
   if(func_00269290(self,&path))func_00265F80(self->p->p,1);
   func_0020FC58(reader,1);
  }
 }else{
  String token;
  func_0020EEA0(reader,&token);
  Buffer buf;func_002117A0(&buf);
  {Handle *dest=self->p;Handle h;func_00213090(&h,buf.get(),&type);*dest=h;}
  func_002676A8(self->p->p,0);
  int t;
  while((t=func_0020EEA0(reader,&token))!=-1){
   reader->current=token;
   if(t==125)break;
   Node *n=self->p->p;VEntry *v=n->vt+62;
   if(!v->fn((char *)n+v->delta,reader))func_0020FC58(reader,0);
  }
  if(!func_00267698(self->p->p)){Node *n=self->p->p;func_002676A8(n,func_00265D98(n)?1:2);}
 }
}
