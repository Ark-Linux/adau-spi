#ifndef __SIGMASTUDIOFW_H__
#define __SIGMASTUDIOFW_H__

#define SIGMA_WRITE_DELAY(...) usleep(20*1000)
#define SIGMA_WRITE_REGISTER_BLOCK(device_add, reg_add, bytes, data) \ 
    spi_backend_ops.adi_dsp_write(device_add, reg_add, bytes, data)


#endif

