#include "../lss_types.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>


lss_i32 main ( lss_i32 argc, lss_str* argv ) 
{
	DIR *dp = opendir(argv[1]);
	DIR *dir_ptr;
	struct dirent *file;
	struct dirent *dirp;
	struct stat buf;
	lss_i8 *ptr;

	while ((dirp = readdir(dp)) != lss_null)
	{
		lstat(dirp -> d_name, &buf);

		if (S_ISREG(buf.st_mode)) ptr = "Regolar";
		else if (S_ISDIR(buf.st_mode)) ptr = "Directory";
		else ptr = "Other";


		printf("%s: %s\n", dirp -> d_name, ptr);
	}
	
	closedir(dp);



	/*1. 디렉터리 열기*/
	if ( (dir_ptr = opendir(getenv("HOME"))) == NULL) return -1;
	
	/// 2. 항목이 없을 때 까지
	while((file = readdir(dir_ptr)) != NULL)
	{
		printf("%s\n", file->d_name);
	}
	
	/// 3. 디렉터리 닫기
	closedir(dir_ptr);
	

	


	return 0;
}


