#include <pthread.h>
#include <stdio.h>
int val = 4000;
pthread_mutex_t mtx;

void * work(void * ptr){
	pthread_mutex_lock(&mtx);
	for(int i=0;i<10;i++){
	 val = val-1;
	 printf("%d\n",val);
	}
	pthread_mutex_unlock(&mtx);
	
	pthread_exit(0);
}
void * work2(void * ptr){
	pthread_mutex_lock(&mtx);
	for(int i=0;i<10;i++){
	val = val +1;
	printf("%d\n",val);
	}
	pthread_mutex_unlock(&mtx);

	pthread_exit(0);
}

int main(int argc,char ** argv){
	pthread_t t0,t1;
	pthread_mutex_init(&mtx,0);
	pthread_create(&t0,0,work,(void *)0); pthread_create(&t1,0,work2,(void *)0); 
	pthread_join(t0,0); pthread_join(t1,0);
	pthread_mutex_destroy(&mtx);
	printf("%d",val);
}