#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;
	// This structure holds the current time
	// tv.tv_sec contains the number of seconds since the Unix epoch (January 1, 1970)
	// tv.tv_usec contains the number of microseconds. * 1000 -> millisecond

    if (gettimeofday(&tv, NULL) == 0) {
        // Print the current time in seconds and microseconds
        printf("Current time: %ld seconds and %ld microseconds\n", tv.tv_sec, tv.tv_usec);
    } else {
        perror("gettimeofday");
    }

    return 0;
}
