#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE "/dev/usb_driver_dev"
#define BUFFER_LENGTH 80

int main() {
	int i, usb_test, bytes;
	char ch, write_buf[BUFFER_LENGTH], read_buf[BUFFER_LENGTH];
	
	usb_test = open(DEVICE, O_RDWR);
	if (usb_test == -1) {
		printf("Loi khi mo %s\n", DEVICE);
		exit(-1);
	}
	
	printf("r = doc du lieu cua thiet bi\nw = ghi du lieu vao thiet bi\nLua chon: ");
	scanf("%c", &ch);
	
	switch (ch) {
		case 'w':
			printf("Nhap du lieu: ");
			scanf(" %[^\n]", write_buf);
			write(usb_test, write_buf, BUFFER_LENGTH);
			break;
		case 'r':
			bytes = read(usb_test, read_buf, BUFFER_LENGTH);
			if (bytes > 0) {
				for (int i = 0; i < bytes; ++i) {
					printf("%c", read_buf[i]);
				}
			}
			printf("\n");
			break;
		default:
			printf("vui long lua chon r hoac w.\n");
			break;
	}
	close(usb_test);
	
	return 0;
	
}
