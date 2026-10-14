struct E{short d,p;void*(*f)(char*,int);};struct S{char p[100];E*v;};extern S*D_00618710;void* f(int n){int a=!n?256:1;S*s=D_00618710;E*e=s->v+72;return e->f((char*)s+e->d,a);}
