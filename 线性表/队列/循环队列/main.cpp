// 入队操作
int enterQueue(SeqQueue *Q, QueueElementType x)
{
    // 将元素 x 入队
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return false;
    
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;

    return true;
}

// 出队操作
int deleteQueue(SeqQueue *Q, QueueElementType *x)
{
    // 删除队头元素，用 x 返回其值
    if (Q->front == Q->rear)
        return false;
    
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return true;
}
