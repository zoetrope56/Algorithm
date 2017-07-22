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
	int dist = 999; // �Ÿ� ���� ����
	unsigned int idx; // Ž���� ����� �ε���
	unsigned int first_in; // ���� ó�� �鸥 ���� Ȯ�� �Ǵ�
	unsigned int final_in; // ���� ������ �鸥 ���� Ȯ�� �Ǵ�
	bool *check; // ���� ����ŭ �����Ҵ��ؼ� �鷶���� ���� �Ǵ�
	bool **path; // ������ ��� üũ ���� �Ǵ�
	unsigned int path_count = 0;
	int p, q;
	int *vect;
	int *dist_vect;
	int dist_vect_index = 0;
	int v_index = 0;
	int **travel;
	int travel_idx = 0;
	int travel_value;
	unsigned int total_distance = 0;
	int search_tmp = 999999;
	////////////////////////////////////////////////////////////


	FILE *fp;

	printf("filename = ftv170.atsp");
	//scanf("%s", strin);
	fp = fopen("ftv170.atsp", "r");
	printf("\n");
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
	// ���� ���Ա���� ���� �ʱ�ȭ
	//printf("matr %d\n=-----------------------------------------\n\n", matr); // for debug
	dist_vect = (int*)malloc(sizeof(int) *matr);
	vect = (int*)malloc(sizeof(int) *matr);
	check = (bool*)malloc(sizeof(bool) * matr);
	path = (bool**)malloc(sizeof(bool*) * matr);
	for (i = 0; i < matr; i++) {
		path[i] = (bool*)malloc(sizeof(bool) * matr);
	}
	travel = (int**)malloc(sizeof(int*) *(matr + 1));

	for (i = 0; i < matr; i++) {
		travel[i] = (int*)malloc(sizeof(int) * 3);
	}
	
#ifdef DEBUG_a
	/*
	for (i = 0; i < matr; i++) {
	check[i] = false;
	//printf("%d= %d\n", i, check[i]);
	}

	for (i = 0; i < matr; i++) {
	for (j = 0; j < matr; j++) {
	path[i][j] = false;
	}
	}
	*/
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

	for (dist_vect_index = 0; dist_vect_index < matr; dist_vect_index++)
	{
		for (i = 0; i < matr; i++) {
			check[i] = false;
			//printf("%d= %d\n", i, check[i]);
		}
		for (i = 0; i < matr; i++) {
			vect[i] = 0;
			//printf("%d= %d\n", i, check[i]);
		}
		for (i = 0; i < matr; i++) {
			for (j = 0; j < matr; j++) {
				path[i][j] = false;
			}
		}
		for (i = 0; i < matr; i++) {
			for (j = 0; j < 2; j++) {
				travel[i][j] = 0;
			}
		}
		total_distance = 0;
		travel_idx = 0;
		path_count = 0;
		dist = 999;

		// 1. ���� ����
		first_in = dist_vect_index;
		idx = first_in; // �������� Ȯ��
		for (i = 0; i < matr; i++)
		{
			for (j = 0; j < matr; j++)
			{
				if (mat[i][j] == 0)	path[i][j] = true;
			}
		}
		while (1)
		{
			for (i = 0; i < matr; i++) // Ư�� ������ ��ü ��� Ž��
			{
				if (path[idx][i] == true);

				else if (dist > mat[idx][i]) { // ���� ��κ��� ª�ų� ���� ��ΰ� ������ ������
					dist = mat[idx][i];
					vect[path_count] = i; // ���° �������� Ȯ���ϱ� ���� ���
					path_count++; // ���� �ε��� ����
				}
			}

			if (path_count == 0) {
				final_in = idx;
				//printf("final = %d \n", final_in);
				break;
			}
#ifdef DEBUG_a
//			for (i = 0; i < path_count; i++)
//			{
//				//printf("%d = %d\n", i, vect[i]);
//			}
//printf("[From >> %d]\t[To >> %d]\t[Distance >> %d]\n", idx, vect[path_count - 1], mat[idx][vect[path_count - 1]]);
#endif
			
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
		dist_vect[dist_vect_index] = total_distance;
	}
	for (i = 0; i < matr; i++)
	{
		if (search_tmp > dist_vect[i])
		{
			search_tmp = dist_vect[i];
		}
	}
	printf("������ ��δ� : [%4d] �Դϴ�.\n", search_tmp);

#ifdef DEBUG_b
	// ���� ó��
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
