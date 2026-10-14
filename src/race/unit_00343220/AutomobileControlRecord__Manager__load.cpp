struct S{int a,state;char data[4];};
extern "C" char*func_00346528(void*,char*),*func_00346CA0(S*,char*);
extern "C" void func_00346890(S*,int);
extern "C" char*AutomobileControlRecord__Manager__load(S*s,char*p,int all){int n=*(int*)p;p+=4;if(!n){s->state=0;return func_00346528(s->data,p);}if(all){int i=0;s->state=1;while(i<n){func_00346890(s,i++);p=func_00346CA0(s,p);}}else{s->state=2;func_00346890(s,0);p=func_00346CA0(s,p);}return p;}
