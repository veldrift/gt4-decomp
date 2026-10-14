/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,selfish; char *data(){return (char *)(this+1);} char *grab(); void release(); };
extern Rep D_00659E20;
extern char D_006C01F8[];
struct Str;
extern "C" void free(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
extern "C" u32 func_0060E690(const Str *,char,u32);
inline char *Rep::grab(){if(selfish)return strobe__toUpper(this);++ref;return data();}
inline void Rep::release(){if(--ref==0)free(this);}
struct Str {
 char *dat;
 Rep *rep() const {return (Rep *)dat-1;}
 u32 length() const {return rep()->len;}
 Str():dat(D_00659E20.grab()){}
 Str(const Str &s):dat(s.rep()->grab()){}
 Str(const Str &s,u32 pos,u32 n):dat(D_00659E20.grab()){func_0060DC18(this,0,-1,&s,pos,n);}
 ~Str(){rep()->release();}
 Str &operator=(const Str &s){if(&s!=this){rep()->release();dat=s.rep()->grab();}return *this;}
 int operator[](u32 i) const {return i<length()?dat[i]:0;}
 Str substr(u32 pos,u32 n)const{return Str(*this,pos,n);}
 Str &append(const char *s){u32 n=func_0057F260(s);strobe__Any__setMember(this,length(),0,s,n);return *this;}
 Str &append(const Str &s){func_0060DC18(this,length(),0,&s,0,-1);return *this;}
};
static inline Str operator+(const Str &a,const char *b){Str t(a); t.append(b);return t;}
static inline Str operator+(const Str &a,const Str &b){Str t(a); t.append(b);return t;}
struct Obj {char pad[0x14];Str path;};
extern "C" void func_004EBC68(Obj *o,const Str *s){
 if((*s)[0]=='/') o->path=*s;
 else {
  Str dir;
  u32 pos=func_0060E690(&o->path,'/',-1);
  if(pos!=(u32)-1) dir=o->path.substr(0,pos);
  o->path=dir+D_006C01F8+*s;
 }
}
