#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

#include "../lss_types.h"

#define _GNU_SOURCE

lss_i32 main( lss_i32 argc, lss_str* argv )
{

	/// uanme 사용을 위한 구조체 선언
	struct utsname uts;
	/// 커널 버전 정보 획득을 위한 변수 선언
	lss_i32 major, minor, patch;
	
	/// 과제
	struct sysinfo info;
	sysinfo(&info);

	// men_unit을 곱하여 바이트 단위로 변환 후 메가바이트(MB)fh rPtks
	long total_ram_mb = (info.totalram*info.mem_unit) / (1024 * 1024);
	long free_ram_mb = (info.freeram * info.mem_unit) / (1024 *1024);

	lss_cstr genv = getenv( argv[1] );

	if( lss_null == genv )
	{
		printf( "getenv에서 얻을 수 없는 환경 설정 정보 : %s\n", argv[1] );
	}
	else 
	{
		printf( "getenv ( %s ) :%s\n", argv[1], genv );	
	}

	
	

	uname( &uts );
	/// sscanf() 는 첫번째 인수를 사용자의 입력으로 생각
	/// 첫번째 인순는 문자열인 경우가 대부분
	/// 이후의 "~); 일반적인 scanf()와 동일하게 사용
	sscanf( uts.release, "%d.%d.%d", &major, &minor, &patch );

	printf( "Kernel : %d.%d.%d\n", major, minor, patch);
	printf( "sysname : %s\n", uts.sysname );
	printf( "nodename : %s\n", uts.nodename );
	printf( "release :%s\n", uts.release );
	printf( "version :%s\n", uts.version );
	printf( "machine :%s\n", uts.machine );
	printf( "domain : %s\n", uts.__domainname );
	
	printf("Total Ram : %ld MB\n", total_ram_mb);
	printf("Free Ram : %ld MB\n", free_ram_mb);

	return 0;
}





