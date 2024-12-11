#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct mojod{
	int x, y, value;
};
int n, m;
int id_in_field[1003][1003];
char type[1003];
struct mojod mj[1003];
int capacity[1003];
int LIST[1003];
int number_of_mojod, number_of_guns;

void get_input(){
	scanf("%d%d", &n, &m);
	scanf("%d", &number_of_mojod);
	char waste;
	for(int i = 1; i <= number_of_mojod; i++){
		int id, x, y, value;
		char tpe;
		scanf(" %c %d (%d,%d) %d", &tpe, &id, &x, &y, &value);
		if(x < 0 || x >= n || y < 0 || y >= m || value < 1 || (tpe != 'A' && tpe != 'S')){
			i--;
			number_of_mojod--;
			continue;
		}
		id_in_field[x][y] = id;
		type[id] = tpe;
		mj[id].x = x;
		mj[id].y = y;
		mj[id].value = value;
		LIST[i] = id;
	}
	scanf("%d", &number_of_guns);
	for(int i = 1; i <= number_of_guns; i++){
		char ch;
		scanf(" %c", &ch);
		int id;
		scanf("%d", &id);
		scanf("%d", &capacity[id]);
		type[id] = ch;
	}
}

void CALCULATE(){
	long long ans = 0;
	for(int i = 1; i <= number_of_mojod; i++)
		ans += mj[LIST[i]].value;
	printf("%lld\n", ans);
}

void PRINT(){
	for(int i = 1; i <= number_of_mojod; i++)
		if(mj[LIST[i]].x != -1)
			printf("%d(%d)\n", LIST[i], mj[LIST[i]].value);
}

void SHOOT(int id, int x, int y){
	if(capacity[id] <= 0)
		return;
	capacity[id]--;
	if(id_in_field[x][y] != 0 && (type[id] == 'M' || (type[id] == 'G' && type[id_in_field[x][y]] == 'S'))){
		mj[id_in_field[x][y]].value = 0;
		mj[id_in_field[x][y]].x = -1;
	}
}

int main() {
	get_input();
	int q;
	scanf("%d", &q);
	while(q--){
		char ch;
		scanf(" %c", &ch);
		if(ch == 'C')
			CALCULATE();
		else if(ch == 'P')
			PRINT();
		else{
			int id, x, y;
			char waste;
			scanf("%d (%d", &id, &x);
			scanf(" %c", &waste);
			scanf("%d)", &y);
			SHOOT(id, x, y);
		}
	}
	return 0;
}

