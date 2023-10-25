#ifndef _SYSCALLS_H
#define _SYSCALLS_H

    #define SYSTEM_READ_ID  0x03
    #define SYSTEM_WRITE_ID 0x04
    
    void sysWrite(unsigned int fd, const char * buffer);


#endif