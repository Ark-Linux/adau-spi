/*
-------------------------------------------------------------------------------
TYMPHANY LTD
                  dsp adau1462 driver
                  -------------------------
@file        Adau1462_Drv.c
@brief       This file implements the drivers for adau1462
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

#include "spi.h"

#include "adau1462.h"
#include "ADAU1462_IC_1.h"
#include "ADAU1462_IC_1_PARAM.h"

#define ADAUDSP_SPECIAL_I2C

#define BYTES_PER_PROGRAM_ADDR      5
#define BYTES_PER_PARAM_ADDR        4

#define ADAUDSP_MAX_WRITE_BYTES     200
#define ADAUDSP_PROGRAM_ADDR_STEP   (ADAUDSP_MAX_WRITE_BYTES / BYTES_PER_PROGRAM_ADDR)   // program data : 5 bytes per register address
#define ADAUDSP_PARAM_ADDR_STEP     (ADAUDSP_MAX_WRITE_BYTES / BYTES_PER_PARAM_ADDR)   // parameter data : 4 bytes per register address
#define DSP_VOLUME_CONTROL_1 	(713)
#define DSP_VOLUME_CONTROL_2 	(714)
int main(int argc, char *argv[])
{
	int i;
	char buf[8] = {0, 0, 0, 0, 1};
	printf("ADAU1462 init \n");
	if(0 != spi_backend_ops.open(argc, argv))
	{
		printf("ADAU166 Init failed!!!\n");
		return 0;
	}
	default_download_IC_1();

	spi_backend_ops.read(DSP_VOLUME_CONTROL_1, 4, buf);
	printf("init done and read address %x:\n",DSP_VOLUME_CONTROL_1);
        for(i = 0; i < 4; i++)
        printf(" %.2x",buf[i]);
        printf("\n");
	
	for(i = 0; i < 8; i++)
                buf[i] = 0;

	spi_backend_ops.read(DSP_VOLUME_CONTROL_2, 8, buf);
        printf("init done and read address %x:\n",DSP_VOLUME_CONTROL_2);
        for(i = 0; i < 8; i++)
        printf(" %.2x",buf[i]);
        printf("\n");

        for(i = 0; i < 8; i++)
                buf[i] = 0;
   printf("ADAU1462 Init finish\n");
   return 0;
}

