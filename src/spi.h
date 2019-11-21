
struct backend_ops {
	int (*open)(int argc, char *argv[]);
	int (*read)(unsigned int addr, unsigned int len, uint8_t *data);
	int (*write)(unsigned int addr, unsigned int len, const uint8_t *data);
};

extern const struct backend_ops spi_backend_ops;

