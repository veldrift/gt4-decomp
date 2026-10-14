struct S { char pad[8]; char name[256]; char buf[256]; unsigned offset; int bad; };
extern char D_006C49C0[], D_006C4EF8[], D_006C4F08[], D_006C4F40[];
extern const char *D_0064C190, *D_0064C194, *D_0064C198;
extern "C" int func_0053F280(char *, unsigned *, const char *) throw();
extern "C" int func_00594470(const char *, const char *, unsigned);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005A6AB0(void *, const void *, int) throw();
extern "C" char *func_005A6DC8(const char *, const char *) throw();
extern "C" void func_00540818(char *name, char **args, S *s) {
 if (s->bad == 0) {
  if (func_0053F280(s->buf, &s->offset, name) == 0) s->bad = 1;
  char *p = name;
  while (*p != ':') p++;
  if (func_00594470(D_006C4EF8, p + 1, 256) == 0) {
   unsigned i = 0;
   if (*args != 0) {
   do {
    switch (i) {
     case 0:
      if (func_00594470(D_006C49C0, args[i], 5)) s->bad = 1;
      break;
     case 1:
      if (func_00594470(D_0064C190, args[1], 256)) s->bad = i;
      break;
     case 2: {
      char *q = args[2];
      while (*q != ':') q++;
      q++;
      if (func_00594470(D_006C4F08, q, 256)) s->bad = 1;
      break;
     }
     case 3:
      if (func_00594470(D_0064C194, args[3], 256)) s->bad = 1;
      break;
    }
    i++;
   } while (args[i] != 0);
   }
  } else if (func_005A6DC8(D_006C4F40, name)) {
   unsigned i = 0;
   func_005A6AB0(s->name, name, 256);
   if (*args != 0) {
   do {
    switch(i) {
     case 1:
      if (func_00594470(D_006C49C0, args[1], 5)) s->bad = i;
      break;
     case 2:
      if (func_00594470(D_0064C198, args[2], func_0057F260(D_0064C198))) s->bad = 1;
      break;
    }
    i++;
   } while (args[i] != 0);
   }
  }
 }
}
