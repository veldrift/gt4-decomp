struct Buf{unsigned char*data;unsigned size;inline Buf(unsigned char*p,unsigned n):data(p),size(n){}};
extern "C" Buf*func_0044BFE8(Buf*),*func_0044C040(Buf*),*func_0044C0F0(Buf*,const Buf*),*func_0044C098(Buf*,const Buf*);
extern "C" int func_0044C160(const Buf*,const Buf*);
extern "C" void*func_005A48D8(void*,int,unsigned),*func_005A4724(void*,const void*,unsigned);
extern "C" Buf*func_0044C2F0(Buf*out,const Buf*numerator,const Buf*divisor,Buf*remainder){
 unsigned n=out->size;
 Buf a((unsigned char*)__builtin_alloca(n+1),n+1);func_005A48D8(a.data,0,a.size);func_005A4724(a.data,divisor->data,n);
 Buf coefficient((unsigned char*)__builtin_alloca(n+1),n+1);func_005A48D8(coefficient.data,0,coefficient.size);coefficient.data[0]=1;
 Buf b((unsigned char*)__builtin_alloca(n+1),n+1);func_005A48D8(b.data,0,b.size);func_005A4724(b.data,numerator->data,n);
 Buf quotient((unsigned char*)__builtin_alloca(n+1),n+1);func_005A48D8(quotient.data,0,quotient.size);
 while(func_0044C160(&a,&b)<0){func_0044BFE8(&a);func_0044BFE8(&coefficient);}
 while(func_0044C160(divisor,&b)<=0){
 while(func_0044C160(&b,&a)<0){func_0044C040(&a);func_0044C040(&coefficient);}
 func_0044C0F0(&b,&a);func_0044C098(&quotient,&coefficient);
 }
 func_005A4724(out->data,quotient.data,out->size);
 func_005A4724(remainder->data,b.data,remainder->size);
 return out;
}
