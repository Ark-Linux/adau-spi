/*
-------------------------------------------------------------------------------
TYMPHANY LTD
                  dsp adau1466 driver
                  -------------------------
@file        Adau1466_Drv.c
@brief       This file implements the drivers for adau1466
@author      Viking WANG
@date        2019-10-14
@copyright (c) Tymphany Ltd. All rights reserved.
-------------------------------------------------------------------------------
*/
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
#include <netinet/in.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <sys/ioctl.h>

#include "spi.c"

#include "ADAU1466_DRV.h"
#include "ADAU1462_IC_1.h"
#include "ADAU1462_IC_1_PARAM.h"

#define ADAUDSP_SPECIAL_I2C

#define BYTES_PER_PROGRAM_ADDR      5
#define BYTES_PER_PARAM_ADDR        4

#define ADAUDSP_MAX_WRITE_BYTES     200
#define ADAUDSP_PROGRAM_ADDR_STEP   (ADAUDSP_MAX_WRITE_BYTES / BYTES_PER_PROGRAM_ADDR)   // program data : 5 bytes per register address
#define ADAUDSP_PARAM_ADDR_STEP     (ADAUDSP_MAX_WRITE_BYTES / BYTES_PER_PARAM_ADDR)   // parameter data : 4 bytes per register address

int main(int argc, char *argv[])
{
	int i;
	char buf[8] = {0, 0, 0, 0, 1};
	printf("ADAU1466 init \n");
	if(0 != spi_open(argc, argv))
	{
		printf("ADAU166 Init failed!!!\n");
		return 0;
	}
	default_download_IC_1();

	spi_backend_ops.adi_dsp_read(1, 32, 4, buf);
	printf("init done and read address 0x20:\n");
        for(i = 0; i < 4; i++)
        printf(" %.2x",buf[i]);
        printf("\n");
	
	for(i = 0; i < 8; i++)
                buf[i] = 0;

	spi_backend_ops.adi_dsp_read(1, 33, 8, buf);
        printf("init done and read address 0x21:\n");
        for(i = 0; i < 8; i++)
        printf(" %.2x",buf[i]);
        printf("\n");

        for(i = 0; i < 8; i++)
                buf[i] = 0;
   printf("ADAU1466 Init finish\n");
   return 0;
}

