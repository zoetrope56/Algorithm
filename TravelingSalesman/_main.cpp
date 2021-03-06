#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define SSIZE 1024

int main() {

	char strin[20];
	char *input;
	char **toks;
	char tokstr[3] = { ' ','\n','\0' };
	char *tmp;
	int tokr, tokc, fsize;
	int i = 1, j = 0;
	int **mat, matr;

	//custom
	int dist = 999; // 거리 정보 저장
	unsigned int idx; // 탐색시 사용할 인덱스
	unsigned int first_in; // 가장 처음 들른 도시 확인 판단
	unsigned int final_in; // 가장 마지막 들른 도시 확인 판단
	bool *check; // 도시 수만큼 동적할당해서 들렀는지 여부 판단
	bool **path; // 도시의 경로 체크 여부 판단
	unsigned int path_count = 0;
	int p, q;
	int *vect;
	int v_index = 0;
	int **travel;
	int travel_idx = 0;
	int travel_value;
	int total_dist_tmp;
	unsigned int total_distance = 0;
	int chk_idx = 0;
	////////////////////////////////////////////////////////////
	FILE *fp;

	printf("filename = ");
	//scanf("%s", strin);
	//fp = fopen(strin, "r");
	fp = fopen("ftv170.atsp", "r");
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	input = (char *)malloc(sizeof(char) * fsize);
	printf("fsize = %d\n", fsize);
	fseek(fp, 0, SEEK_SET);
	while ((fread(input, fsize, 1, fp)) > 0) {

	}
	tmp = strtok(input, tokstr);
	//printf("first word = %s\n", tmp);

	while (tmp = strtok(NULL, tokstr)) {
		i++;
		//printf("[%i] word = %s\n", i, tmp);

		if (strcmp("DIMENSION:", tmp) == 0) {
			tmp = strtok(NULL, tokstr);
			matr = atoi(tmp);
		}
		if (strcmp("EDGE_WEIGHT_SECTION", tmp) == 0) {
			break;
		}
	}

	mat = (int **)malloc(sizeof(int) * matr);
	for (i = 0; i < matr; i++) {
		mat[i] = (int *)malloc(sizeof(int) * matr);
	}

	i = 0;
	while (tmp = strtok(NULL, tokstr)) {

		//printf("[%d][%d] word = %s\n", i, j, tmp);
		mat[i][j] = atoi(tmp);
		j++;
		if ((j %= matr) == 0)
			i++;
		if (i == matr)
			break;
	}
	//
	//custom
	// 도시 출입기록을 위한 초기화
	//printf("matr %d\n=-----------------------------------------\n\n", matr); // for debug

	vect = (int*)malloc(sizeof(int) *matr);
	check = (bool*)malloc(sizeof(bool) * matr);

	for (i = 0; i < matr; i++) {
		check[i] = false;
		//printf("%d= %d\n", i, check[i]);
	}

	path = (bool**)malloc(sizeof(bool*) * matr);
	for (i = 0; i < matr; i++) {
		path[i] = (bool*)malloc(sizeof(bool) * matr);
	}
	for (i = 0; i < matr; i++) {
		for (j = 0; j < matr; j++) {
			path[i][j] = false;
		}
	}

	travel = (int**)malloc(sizeof(int*) *(matr + 1));
	for (i = 0; i < matr; i++) {
		travel[i] = (int*)malloc(sizeof(int) * 3);
	}
#ifdef DEBUG_a
	for (i = 0; i < matr; i++) {
		for (j = 0; j < matr; j++) {
			if (i == j)
				path[i][j] = true;
			printf("%d\t", path[i][j]);
		}
		printf("\n");
	}

	//debug

	for (i = 0; i < matr; i++) {
		for (j = 0; j < matr; j++) {
			if (path[i][j] == 1)
				printf("[x]\t");
		}
	}
#endif

	// 1. 도시 선택
	printf("먼저 들를 도시를 선택하세요 : ");
	scanf("%d", &first_in);
	
	idx = first_in; // 도시정보 확인

	for (i = 0; i < matr; i++)
	{
		for (j = 0; j < matr; j++)
		{
			if(mat[i][j] == 0)	path[i][j] = true;
		}
	}

	while (1)
	{
		
		for (i = 0; i < matr; i++) // 특정 도시의 전체 경로 탐색
		{
			if (path[idx][i] == true);

			else if (dist > mat[idx][i]) { // 최적 경로보다 짧거나 같은 경로가 있으면 가져옴
				dist = mat[idx][i];
				vect[path_count] = i; // 몇번째 도시인지 확인하기 위한 기록
				path_count++; // 벡터 인덱스 증가
			}
		}

		if (path_count == 0) {
			final_in = idx;
			//printf("final = %d \n", final_in);
			break;
		}

		for (i = 0; i < path_count; i++)
		{
			//printf("%d = %d\n", i, vect[i]);
		}

		printf("[%3d][From >> %3d][To >> %3d][Distance >> %3d]\n", chk_idx , idx, vect[path_count - 1], mat[idx][vect[path_count - 1]]);
		chk_idx++;
		travel[travel_idx][0] = idx;
		travel[travel_idx][1] = vect[path_count - 1];
		travel[travel_idx][2] = mat[idx][vect[path_count - 1]];

		total_distance += travel[travel_idx][2];

		for (i = 0; i < matr; i++)
		{
			path[i][idx] = true;
			path[i][vect[path_count - 1]] = true;
		}
#ifdef DEBUG_a
		printf("==================================================================================================\n");
		for (i = 0; i < matr; i++) {
			for (j = 0; j < matr; j++) {
				if (i == j)
					path[i][j] = true;
				printf("%d\t", path[i][j]);
			}
			printf("\n");
		}
		printf("==================================================================================================\n");
#endif
		idx = travel[travel_idx][1];
		travel_idx++;

		for (i = 0; i < path_count; i++)
		{
			vect[i] = 0;
		}
		path_count = 0;
		dist = 999;

	}
	total_dist_tmp = mat[final_in][first_in];
	printf("[%3d][From >> %3d][To >> %3d][Distance >> %3d]\n\n", chk_idx , final_in, first_in, total_dist_tmp);
	printf("how long played? >> [%4d]\n", total_distance);



#ifdef DEBUG_b
	// 종료 처리
	for (i = 0; i < matr; i++) {
		for (j = 0; j < matr; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
		free(mat[i]);
	}
	free(input);
	free(mat);
	fclose(fp);
#endif

}
