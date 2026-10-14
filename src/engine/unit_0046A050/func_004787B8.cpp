extern char D_006AD758[],D_006AD5D8[];
struct S{int type;};
extern "C" char*strobe__Any__toString(S*);
extern "C" float func_00477460(S*);
extern "C" void func_00476B78(S*,float),func_00478930(S*);
extern "C" int func_005A5AD8(const char*,const char*,void*);
extern "C" void func_004787B8(S*s,int base){int n;float f;
 if((unsigned)(s->type-3)<2){char*p=strobe__Any__toString(s);if(p[0]=='0'&&(p[1]=='x'||p[1]=='X')){base=16;p+=2;}
 if(base==16){base=func_005A5AD8(p,D_006AD758,&n);func_00476B78(s,(float)n);}else{base=func_005A5AD8(p,D_006AD5D8,&f);func_00476B78(s,f);}
 if((unsigned)(base+1)<2)func_00478930(s);
 }else func_00476B78(s,func_00477460(s));
}
