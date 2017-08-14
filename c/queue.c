#include<stdio.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord *queue;

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    int* array;
};

int isempty(queue q);
int isfull(queue q);
queue init(int m);
void dispose(queue q);
void makeempty(queue q);
void enqueue(int x, queue q);
int front(queue q);
void dequeue(queue q);
int frontdequeue(queue q);
void printq(queue q);

void main(void)
{
    int i = 0;
    int dat[7] = {1, 2, 3, 4, 5, 6, 7};
    queue q = init(7);
    for(; i<7; i++)
    {
        enqueue(dat[i], q);
        printf("Queue number is %d, ", q->size);
        printq(q);
        printf("\n");
    }
    printf("test dequeue\r\n");
    dequeue(q);
    printq(q);printf("\n");

    printf("test front \r\n");
    int t = front(q);
    printf("after front %d\r\n", t);
    printf("test front dequeue\r\n");
    t = frontdequeue(q);
    printf("after front and dequeue%d\r\n", t);
    printq(q);printf("\n");

    dispose(q);
    return;
}

void dispose(queue q)
{
    free(q->array);
    free(q);
}

void printq(queue q)
{
    int i;
    i = q->front;
    if(q->rear == q->front)
    {
        return;
    }
    do
    {
        printf("%d ",q->array[(i+1)%q->capacity]);
        i = (i+1)%q->capacity;

    }while(i!=q->rear);
}

queue init(int m)
{
    queue q;
    q = (queue)malloc(sizeof(struct QueueRecord));
    q->capacity = m;
    q->front = 1;
    q->rear = 1;
    q->size = 0;
    q->array = (int *)malloc(m*sizeof(int));
    return q;
}

int isempty(queue q)
{
    return q->size == 0;
}

void makeempty(queue q)
{
    q->size = 0;
    q->front = 1;
    q->rear = 0;
    return;
}

int isfull(queue q)
{
    if(q->rear + 1 == q->front)
    {
        return 1;
    }
    return 0;
}

static int succ(int value, queue q)
{
    if(++value == q->capacity)
    {
        value = 0;
    }
    return value;
}
void enqueue(int x, queue q)
{
    if(isfull(q))
    {
        printf("the queue is full");
    }
    else
    {
        q->size++;
        q->rear = succ(q->rear, q);
        q->array[q->rear] = x;
    }
    return;
}
void dequeue(queue q)
{
    if(q->rear!=q->front)
    {
        q->front = succ(q->front, q);
        printf("in dequeue and the value is %d \r\n", q->array[q->front]);
        q->size--;
    }
    return;
}

int front(queue q)
{
    if(q->rear!=q->front)
    {
        int t = succ(q->front, q);
        printf("in front and the value is %d \r\n", q->array[t]);
        return q->array[t];
    }
    return 0;
}

int frontdequeue(queue q)
{
    if(q->rear!=q->front)
    {
        q->front = succ(q->front, q);
        printf("in frontdequeue and the value is %d \r\n", q->array[q->front]);
        q->size--;
    }
    return q->array[q->front];
}

