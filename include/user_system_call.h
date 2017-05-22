#ifndef _user_system_call_H_
#define _user_system_call_H_


#include"thread.h"

int user_syscall(int,void*);
int sys_init(void);

long open(const char *name,                  /* File name                 */
     long  mode,                             /* Open mode                 */
     long  flg);

#endif