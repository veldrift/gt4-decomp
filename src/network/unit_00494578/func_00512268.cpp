struct S{char pad[16];S*p;};extern int func_00538C68(void*);int f(S*s){if(s){if(s->p)func_00538C68(&s->p);func_00538C68(&s);}return 0;}
