#/usr/src/linux-headers-5.10.0-25-cloud-amd64
kbuild:
	make -C /usr/src/linux-headers-$(shell uname -r) M=$(PWD) modules

clean:
	make -C /lib/modules/ $(shell uname -r) M=$(PWD) clean

