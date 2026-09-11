#include "parser.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#ifndef PATH_VALID_TEST_SCENE
 #define PATH_VALID_TEST_SCENE "../../../scene/test/valid/"
#endif
#ifndef PATH_ERROR_TEST_SCENE
 #define PATH_ERROR_TEST_SCENE "../../../scene/test/error/"
#endif

static int	test_scene(const char *dir, const char *file, int expected)
{
	char	path[PATH_MAX];
	int		ret;

	if (snprintf(path, sizeof(path), "%s/%s", dir, file)
		>= (int)sizeof(path))
	{
		printf("  [FAIL] %s: path too long\n", file);
		return (1);
	}
	ret = parser(path);
	if ((ret == 0) != (expected == 0))
	{
		printf("  [FAIL] %-40s expected=%d got=%d\n",
			file, expected, ret);
		return (1);
	}
	printf("  [PASS] %s\n", file);
	return (0);
}

static int	run_tests(const char *dir, int expected)
{
	DIR				*folder;
	struct dirent	*entry;
	int				total;
	int				failed;

	folder = opendir(dir);
	if (!folder)
	{
		perror(dir);
		return (-1);
	}
	total = 0;
	failed = 0;
	while ((entry = readdir(folder)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue ;
		total++;
		failed += test_scene(dir, entry->d_name, expected);
	}
	closedir(folder);
	printf("\n%d tests, %d passed, %d failed\n",
		total, total - failed, failed);
	return (failed);
}

int	main(void)
{
	int	valid_failed;
	int	error_failed;

	printf("\n");
	printf("========================================\n");
	printf("             miniRT PARSER              \n");
	printf("========================================\n\n");

	printf("[VALID SCENES]\n");
	valid_failed = run_tests(PATH_VALID_TEST_SCENE, 0);

	printf("\n[ERROR SCENES]\n");
	error_failed = run_tests(PATH_ERROR_TEST_SCENE, 1);
	printf("\n========================================\n");
	if (valid_failed == 0 && error_failed == 0)
		printf("ALL TESTS PASSED\n");
	else
		printf("TESTS FAILED\n");
	printf("========================================\n\n");
	return (valid_failed != 0 || error_failed != 0);
}