/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
inline void *operator new(unsigned int,void *p) {return p;}
struct Rep { u32 len,cap,ref,selfish; char *data(){return (char *)(this+1);} char *grab(); void release(); };
extern Rep D_00659E20;
struct Str;
extern "C" void free(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" void *func_00575E60(int,int);
inline char *Rep::grab(){if(selfish)return strobe__toUpper(this);++ref;return data();}
inline void Rep::release(){if(--ref==0)free(this);}
struct Str {
 char *dat;
 Rep *rep() const {return (Rep *)dat-1;}
 Str(const char *s):dat(D_00659E20.grab()){strobe__Any__setMember(this,0,-1,s,func_0057F260(s));}
 Str(const Str &s):dat(s.rep()->grab()){}
 ~Str(){rep()->release();}
 Str &operator=(const Str &s){if(&s!=this){rep()->release();dat=s.rep()->grab();}return *this;}
};
extern "C" Str func_004EBA48(const Str &);
template<class T,class U> struct Pair { T first; U second; Pair(T a,U b):first(a),second(b){} };
template<class T,class U> inline Pair<T,U> make_pair(T a,U b){return Pair<T,U>(a,b);}
typedef Pair<Str,Str> Value;
struct Node { Node *next,*prev; Value value; };
struct It { Node *n; It(Node *p):n(p){} It(const It &x):n(x.n){} };
struct List {
 int alloc; Node *head;
 It end(){return It(head);}
 Node *create(const Value &v){Node *p=(Node *)func_00575E60(16,sizeof(Node));Value *dst=&p->value; if(dst) new (dst) Value(v);return p;}
 It insert(It pos,const Value &v){Node *p=create(v);p->next=pos.n;p->prev=pos.n->prev;pos.n->prev->next=p;pos.n->prev=p;return It(p);}
 void push_back(const Value &v){insert(end(),v);}
};
struct Obj {char pad[0x30];int flag;char pad34[0x34];List list;};
extern "C" void func_004E7E50(Obj *o,const char *a,const char *b){
 Str x(a);Str y(b);
 if(o->flag){x=func_004EBA48(x);y=func_004EBA48(y);}
 o->list.push_back(Value(x,y));
}
