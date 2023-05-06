import sys


def bitCount(n):
    count = 0
    while n != 0:
        n = n & n-1
        count += 1
    return count


def assignmentProblem(matrix, n):
    dp = [0]
    for _ in range(1, pow(2, n)):
        dp.append(sys.maxsize)

    for mask in range(pow(2, n) - 1):
        x = bitCount(mask)
        for j in range(n):
            if bin(mask)[j] != 1:
                dp[mask | 1 << j] = min(
                    dp[mask | 1 << j], dp[mask] + matrix[x][j])
    return dp[pow(2, n) - 1]


def main():
    n = int(input("Enter the number of people/jobs:"))
    matrix = []

    print("\nEnter the cost matrix line by line\n")
    for _ in range(n):
        matrix.append(list(map(int, input().rstrip().split())))

    optimalJobCompletionTime = assignmentProblem(matrix, n)
    print(
        f"\nOptimal Job completion time taken by all {n} people: {optimalJobCompletionTime} seconds")


if __name__ == '__main__':
    main()
