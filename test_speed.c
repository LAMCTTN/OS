#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#define DEVICE "/dev/usb_driver_dev"
#define BUFFER_LENGTH 80

int main() {
    clock_t begin = clock();
    int n;
for(n=0;n<1000;n++){
	int i, usb_test, bytes;
	char ch, write_buf[BUFFER_LENGTH], read_buf[BUFFER_LENGTH];	
	usb_test = open(DEVICE, O_RDWR);
	if (usb_test == -1) {
		printf("Loi khi mo %s\n", DEVICE);
		exit(-1);
	}
	strcpy(write_buf,"Hanoi University of Science and Technology");
	write(usb_test, write_buf, BUFFER_LENGTH);
	bytes = read(usb_test, read_buf, BUFFER_LENGTH);
	if (bytes > 0) {
		printf("%s\n",read_buf);
	}
	close(usb_test);
}
	clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf ("\nTime write and read 1000 time: %f ms\n",time_spent);
	return 0;
	
}
