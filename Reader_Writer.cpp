//Reader Writer with Reader having priority.
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <cstdint>
#include <chrono>
#include <thread>
using namespace std;

#define R 5
#define W 5

void *reader(void *a);
void *writer(void *a);

pthread_mutex_t x; //Declaring resource lock.
sem_t wsem; //Declaring Writers lock.

int s=5;
int h=11, m=45;
int readcount;

int main()
{
    
    pthread_t read[R];
    pthread_t write[W]; //Declaring reader and writers array.
    pthread_mutex_init (&x, NULL); //Initializing thread by passing Mutex by default value.
    
    sem_init(&wsem, 0, 1);
    
    readcount = 0;
    
    for(int i=0; i<W; i++) {
        pthread_create(&write[i], NULL, *writer, (void *)(intptr_t)i);
    }
    
    for(int i=0; i<R; i++) {
        pthread_create(&read[i], NULL, *reader, (void *)(intptr_t)i);
    }
    
    for(int i=0; i<W; i++) {
        pthread_join(write[i], NULL);
    }
    
    for(int i=0; i<R; i++) {
        pthread_join(read[i], NULL);
    }
    
    return 0;
}

void *writer(void *a) {
    
    int w = (intptr_t)a;
    int i = 0;
    while(i<2) {
        sem_wait(&wsem);
        m = m+s;
        if (m>=60) {
            m = m - 60;
            h = h + 1;
            if (h > 12) {
                h = 0;
            }
        }
        cout<<"Writer "<<w<<" is writing: "<<h<<" : "<<m<<endl;
        sem_post(&wsem);
        this_thread :: sleep_for(chrono :: seconds(5));
        i++;
    }
    
    return nullptr;
    
}

void *reader(void *a) {
    
    int r = (intptr_t)a;
    int i=0;
    while(i<5) {
        pthread_mutex_lock(&x);
        readcount++;
        if (readcount == 1 ) {
            sem_wait(&wsem);
        }
        pthread_mutex_unlock(&x);
        cout<<"\t\tReader "<<r<<" reading: "<<h<<" : "<<m<<endl;
        
        pthread_mutex_lock(&x);
        readcount--;
        if (readcount == 0) {
            sem_post(&wsem);
        }
        pthread_mutex_unlock(&x);
        this_thread :: sleep_for(chrono :: seconds(5));
        i++;
    }
    return nullptr;
}
