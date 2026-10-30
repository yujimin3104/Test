//비전대학교 컴퓨터학과
//1학년 a반 202618020 유지민
//시스템프로그래밍 중간고사 1번

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
	int fd;
	struct stat statbuf;

	stat("linux.txt", &statbuf);

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1) {
		perror("open:inux.txt");
		exit(1);
	}
	fstat(fd, &statbuf);

	if (mkdir("yjm", 0777) == -1) {
		perror("yjm");
		exit(1);
	}

	printf("현재 작업 디렉터리 : {*pwd} \n");
	printf("디렉터리 생성 및 linux.txt 파일 복사 완료\n");

	printf("---linux.txt 파일 상세 정보 (fatat 결과)--\n");
	printf("Inode 번호 = %d \n", (int)statbuf.st_ino);
	printf("파일 크기 = %d 바이트\n", (int)statbuf.st_size);

	printf("Mode = %o\n", (unsigned int)statbuf.st_mode);
        printf("Blksize = %d\n", (int)statbuf.st_blksize);
        printf("Blocks = %d\n", (int)statbuf.st_blocks);

	close(fd);
}
