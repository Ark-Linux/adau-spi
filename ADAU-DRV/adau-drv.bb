DESCRIPTION = "Hello World and Zlib test"
DEPENDS = "zlib"
SECTION = "libs"
LICENSE = "MIT"
PV = "3"
PR = "r0"

SRC_URI = "file://adau-drv/"

LIC_FILES_CHKSUM =  "file://${COREBASE}/meta/files/common-licenses/${LICENSE};md5=0835ade698e0bcf8506ecda2f7b4f302"
S = "${WORKDIR}/adau-drv"

do_configure () {
}

do_compile () {
  ${CC} ADAU1462_DRV.c -o ADAU1462_DRV
}

do_install () {
	install -d ${D}${bindir}/
	install -m 0755 ${S}/ADAU1462_DRV ${D}${bindir}/
}

FILES_${PN} = "${bindir}/ADAU1462_DRV"


