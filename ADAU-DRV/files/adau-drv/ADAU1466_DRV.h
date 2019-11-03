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

struct backend_ops {
	int (*open)(int argc, char *argv[]);
	int (*read)(unsigned int addr, unsigned int len, uint8_t *data);
	int (*write)(unsigned int addr, unsigned int len, const uint8_t *data);
	int (*adi_dsp_write)(unsigned int dev_addr, unsigned int reg_addr, unsigned int len, const uint8_t *data);
	int (*adi_dsp_read)(unsigned int dev_addr, unsigned int reg_addr, unsigned int len, const uint8_t *data);
};

extern const struct backend_ops spi_backend_ops;
#endif
