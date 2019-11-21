#ifndef I2CDRV_H
#define	I2CDRV_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
typedef struct 
{
    uint8_t devAddr;     /* device address*/
    uint32_t regAddr;
    uint16_t length;
    uint8_t* pMsg;
}tSPIMsg;

#define ADI_REG_TYPE static const uint8_t

#endif
