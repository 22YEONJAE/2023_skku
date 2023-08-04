#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N 500

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int user_ids[N], users[N][N];
int item_ids[N], items[N][N];
int k, c1 = 0, c2 = 0;
int v[N];
int T[N][N];
int temp[N];


void add_user(int id) {
	user_ids[id] = c1;
	users[c1][0] = id;

	for(int i = 1 ; i <= k; i++) {
		users[c1][i] = v[i-1];
	}
	c1++;
}

void add_item(int id) {
	item_ids[id] = c2;
	items[c2][0] = id;

	for(int i = 1 ; i <= k; i++) {
		items[c2][i] = v[i-1];
	}
	c2++;
}

void del_user(int id) {
	int ind = user_ids[id];
	user_ids[id] = -1;
	for(int i = 0 ; i < N; i++) {
		if(user_ids[i] > ind) user_ids[i]--;
	}
	for(int i = ind; i < c1 - 1; i ++) {
		for(int j = 0; j  < k +1 ; j++) {
			users[i][j] = users[i+1][j];
		}		
	}
	c1--;
}

void del_item(int id) {
	int ind = item_ids[id];
	item_ids[id] = -1;
	for(int i = 0 ; i < N; i++) {
		if(item_ids[i] > ind) item_ids[i]--;
	}
	for(int i = ind; i < c2 - 1; i ++) {
		for(int j = 0; j  < k +1 ; j++) {
			items[i][j] = items[i+1][j];
		}		
	}
	c2--;
}

long long dotProduct (int id_u, int id_i)
{
	long long sum = 0;
	for(int i = 1 ; i <= k ; i ++) {
		sum += users[user_ids[id_u]][i] * items[id_i][i];	
	}
	return sum;
}

long long Distance (int id_u, int id_i)
{
	long long sum = 0;
	for(int i = 1 ; i <= k ; i ++) {
		int a = users[user_ids[id_u]][i] - items[item_ids[id_i]][i];
		sum += a*a;
	}
	return sum;
}

void Transform(int c)
{
	for(int i = 0; i < k; i++ ) {
		int sum = 0;
		for(int j = 0; j < k; j++) {
			sum += users[c][j+1] * T[i][j];
		}
		temp[i] = sum;
	}
	for(int i = 1; i <= k; i ++) {
		users[c][i] = temp[i-1];
	}

	
}

int main() {

	// user, item id ��� -1���� ���� ( ���� or ���� x )
	for(int i = 0; i < N; i++) {
		user_ids[i] = -1;
		item_ids[i] = -1;
	}
	char cmd_type[15];

	while (1) {
		scanf("%s", cmd_type);

		if (!strcmp(cmd_type, "set_k")) {
			scanf("%d", &k);
		}
		else if (!strcmp(cmd_type, "add_user")) {
			int id;
			scanf("%d", &id);
			for (int i = 0; i < k; i++) {
				scanf("%d", &v[i]);
			}

			if(user_ids[id] != -1) printf("Error\n");
			else add_user(id);
		}
		else if (!strcmp(cmd_type, "del_user")) {
			int id;
			scanf("%d", &id);

			if(user_ids[id] == -1) printf("Error\n");
			else del_user(id);
			
		}
		else if (!strcmp(cmd_type, "add_item")) {
			int id;
			scanf("%d", &id);
			for (int i = 0; i < k; i++) {
				scanf("%d", &v[i]);
			}
			if(item_ids[id] != -1) printf("Error\n");
			else add_item(id);			
		}
		else if (!strcmp(cmd_type, "del_item")) {
			int id;
			scanf("%d", &id);

			if(item_ids[id] == -1) printf("Error\n");
			else del_item(id);
		}
		else if (!strcmp(cmd_type, "recommend")) {
			int id;
			long long max = LLONG_MIN;
			int index;
			scanf("%d", &id);
			
			if(user_ids[id] == -1) printf("Error\n");
			else {
				for(int i = 0; i < c2; i++) {
					long long temp = dotProduct(id, i);
					if(temp > max) {
						index = i;
						max = temp;
					}
				}
				printf("%d\n", items[index][0]);
			}
			
		}
		else if (!strcmp(cmd_type, "find_similar")) {
			int id;
			long long min = LLONG_MAX;
			int index;
			scanf("%d", &id);

			if(c1 == 1 || user_ids[id] == -1) printf("Error\n");

			else {
				for(int i = 0; i < c1; i++) {
					if(id != users[i][0]) {
						long long temp = Distance(id, i);
						if(temp < min) {
							index = i;
							min = temp;
						}
					}
				
				}

				printf("%d\n", users[index][0]);
			}
			
		}
		else if (!strcmp(cmd_type, "transform")) {
			
			for(int i = 0 ; i < k; i++) {
				for(int j = 0; j < k; j++) {
					scanf("%d", &T[i][j]);
				}
			}
			
			for(int i = 0; i < c1; i++) {
				Transform(i);
			}

	

		}
		else if (!strcmp(cmd_type, "exit")) {
			break;
		}
	}

	return 0;
}