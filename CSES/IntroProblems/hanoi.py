def hanoi(S, A, E, N):
    if (N == 0):
        return
    hanoi(S, E, A, N-1)
    print(S, E)
    hanoi(A, S, E, N-1)

n = int(input())
print(pow(2, n)-1)
hanoi(1, 2, 3, n)