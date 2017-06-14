void YangHuiTriangle()
{
    SeqQueue Q;
    InitQueue(&Q);
    // 第一行元素入队
    EnterQueue(&Q, 1);

    // 产生第 n 行元素并入队，同时打印第 n - 1 行的元素
    for (n = 2; n <= N; n++)
    {
        // 第 n 行的第一个元素入队
        EnterQueue(&Q, 1);

        // 利用队中第 n - 1 行元素产生第 n 行的中间 n - 2 个元素并入队
        for (i = 1; i <= n - 2; i++)
        {
            DeleteQueue(&Q, &temp);
            // 打印第 n - 1 行的元素
            printf("%d", temp);
            // 获取队头元素
            GetHead(Q, &x);
            // 利用队中第 n - 1 行元素产生第 n 行元素
            temp += x;
            EnterQueue(&Q, temp);
        }
        DeleteQueue(&Q, &x);
        // 打印第 n - 1 行的最后一个元素
        printf("%d", x);
        // 第 n 行的最后一个元素入队
        EnterQueue(&Q, 1);
    }

    // 打印最后一行元素
    while (!IsEmpty(Q))
    {
        DeleteQueue(&Q, &x);
        printf("%d", x);
    }
}
