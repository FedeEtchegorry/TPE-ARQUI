#ifndef _SYSCALLS_H
#define _SYSCALLS_H

    #define SYSTEM_WRITE_ID 0x04
    
    void sysWrite(unsigned int fd, const char * buffer);


#endif