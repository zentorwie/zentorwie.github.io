#include <stdio.h>

typedef struct {
    int loc; //location
    char gen;//gender
    char drc;//direction
    int s;//steps
} human;

void sort(human *, int);
int pro(human *, int);
int leave(human *, int, int);
void move(human *, int);
void turn(human *, int);
void print_walkers(human *, int);

double sum_time;
human *final;
int s_sum;

int L;
int step;
int main()
{
    human walker[110];
    int N, V, i, j, k, count, timecount;
    
    while (1) {
	scanf("%d%d%d", &N, &L, &V);
	if (N==0)
	    break;
	
	for (i = 0; i < N; i++) {
	    scanf("%d %c %c", &walker[i].loc, &walker[i].gen, &walker[i].drc);
//	    printf("walker[%d].loc = %d\ngender = %c\ndrc = %c\n", i, walker[i].loc, walker[i].gen, walker[i].drc);
	}
       
	
	count = N;
//	printf("count = %d\n", count);
	sort(walker, N);
	
	for (i = 0; i < count; i++) {
	    walker[i].loc *= 2;
	    walker[i].s = 0;
//	    printf("walker[%d].loc = %d\n", i, walker[i].loc);
	    
	}
	step = 0;
	s_sum = 0;
	while (count > 0) {
//	    printf("||||||||||||||||||||Step %d : \n", step);
//	    sort(walker, count);
	    count = pro(walker, count);
	}
	
//	printf("Finish!!!!!\n");
//	printf("********\nFinal.step : %d\n********\n", step);
//	printf("********\ns_sum : %d\n********\n", s_sum);
	printf("%.2f %.2f\n", step*0.5/V, s_sum*0.5);
    }
    return 0;
}

void sort(human *walker, int count)
{
    int i, j, min;
    human t;
    //  printf("sorting...\n");
    for (i = 0; i < count-1; i++) {
	min = i;
	for (j = i + 1; j < count; j++) {
	    if (walker[j].loc < walker[min].loc)
		min = j;
	}
	
	t = walker[i];
	walker[i] = walker[min];
	walker[min] = t;
    }
//    printf("Sorted!\n");
    return;
}

int pro(human *walker, int count)
{//problem
//    print_walkers(walker, count);

    
    if (walker[0].loc <= 0 && walker[0].drc == 'W') {
	count = leave(walker, 0, count);
//	printf("Left from the left side.\n");
    }
    if (walker[count-1].loc >= L*2 && walker[count-1].drc == 'E') {
	count =	leave(walker, 1, count);
//	printf("Left from the right side.\n");
    }

    if (count > 0)
	move(walker, count);
    if (count > 1)
	turn(walker, count);

    return count;
}

int leave(human *walker, int which, int count)
{
    int i;
    
    if (which == 0) {//left
	s_sum += walker[0].s;
	for (i = 0; i < count - 1; i++) {
	    walker[i] = walker[i+1];
	}
    }
    else
	s_sum += walker[count-1].s;
	
    
    count--;
    //  printf("Count == %d, leave!\n", count);
    //exit(0);
    return count;
}

void move(human *walker, int count)
{
    int i;
    //  printf("count == %d, move!\n", count);
    for (i = 0; i < count; i++) {
	if (walker[i].drc == 'E')
	    walker[i].loc++;
	else
	    walker[i].loc--;
	walker[i].s++;
    }
    step++;
    if (count == 1) {
	printf("walker0.loc == %d\n", walker[0].loc);
    }
    
    return;
}

void turn(human *walker, int count)
{
    char t;
    int i;
    human temp;
    for (i = 0; i < count - 1; i++) {
	if (walker[i].loc == walker[i+1].loc) {
	    if (walker[i].gen == walker[i+1].gen) {

		t = walker[i].drc;
		walker[i].drc = walker[i+1].drc;
		walker[i+1].drc = t;
//		printf("Turned!\n");
	    }
	    else if (walker[i].drc == 'E') {
		temp = walker[i];
		walker[i] = walker[i+1];
		walker[i+1] = temp;
	    }
		
	}
    }
    
    return;
}

void print_walkers(human *walker, int count)
{
    int i;
    for (i = 0; i < count; i++) {
	printf("\n==walker%3d==\n", i);
	printf("==loc : %3d==\n", walker[i].loc);
	printf("==gen : %3c==\n", walker[i].gen);
	printf("==drc : %3c==\n", walker[i].drc);

    }
    return;
}
