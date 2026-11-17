#include <stdio.h>
#include "stat.h"
#include "mkdir.h"
#include <sys/stat.h>
#include "version.h"



int main (void)
{
	mode_t old_mask = umask(S_IRWXG | S_IRWXO);
	
	mkdir("./secure_valt", 0777);

	umask(old_mask);

	printf("이전 마스크 : %04o\n", old_mask);
	

	lss_u32 ver = VERSION_MAKER(MAJOR_VERSION, MINOR_VERSION, PATCH_VERSION, CUSTOM_VERSION);
	
	printf("Major : %d\n", MAJOR_GET_VERSION(ver));
	printf("Minor : %d\n", MINOR_GET_VERSION(ver));
	printf("Patch : %d\n", PATCH_GET_VERSION(ver));
	printf("Custom : %d\n", CUSTOM_GET_VERSION(ver));

	printf("hello\n");
	stat_function("stat.c"); /// 파일 경로 전달
		/// 예제에 있는 코드가 동작하여 파일의 정보를 출력
	
	/// 권한 정보 없이 호출 => 기본 권한 (755)이 할당
	lss_mkdir("dir1", 0);
	/// 권한 정보를 주고 호출
	lss_mkdir("dir2", S_IRWXU |  S_IRWXG |  S_IRWXO);
	return 0;
}



