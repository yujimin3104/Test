//비전대학교 컴퓨터학과
//1학년 a반 202618020 유지민
//시스템프로그래밍 중간고사 3번

#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	struct utsname uts;

	if (uname(&uts) == -1) {
		perror("uname");
		exit(1);
	}

	printf("OSname : %s\n", uts.sysname);
        printf("Nodename : %s\n", uts.nodename);
        printf("Release : %s\n", uts.release);
        printf("Version : %s\n", uts.version);
        printf("Machin : %s\n", uts.machine);
}
