struct S{unsigned char*p;};extern signed char D_006B0C80[];extern void func_004B95D0(S*,int,int);void func_00493438(S*s,int*out){int n=D_006B0C80[s->p[0]];*out=n;return func_004B95D0(s,1,n);}
